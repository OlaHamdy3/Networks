#include <iostream>
using namespace std;

int frameSize, generatorSize;
int* frame;
int* generator;

void fill() {
	cout << "Frame size is: ";
	cin >> frameSize;
	cout << "Generator size is: ";
	cin >> generatorSize;
	int* frameXX = new int[frameSize];
	int* generatorXX = new int[generatorSize];
	frame = frameXX;
	generator = generatorXX;
	for (int i = 0; i < frameSize; i++) {
		cout << "Frame bit #" << i+1 << endl;
		cin >> frameXX[i];
	}
	for (int i = 0; i < generatorSize; i++) {
		cout << "Generator bit #" << i+1 << endl;
		cin >> generatorXX[i];
	}
}

void calculate() {
	int n = 0, m = 0, flag = 0, k = 0, count = 0;
	for (int i = frameSize; i<(frameSize + generatorSize) - 1; i++)
		frame[i] = 0;

	frameSize = (frameSize + generatorSize) - 1;
	int rsize = frameSize;
	int* res = new int[rsize];
	for (int i = 0; i<frameSize; i++)
		res[i] = frame[i];


	for (int i = 0; i<generatorSize; i++)
	{
		res[i] = frame[i] ^ generator[i];
		n = i;
	}
	while (n <= frameSize)
	{
		while (flag == 0)
		{
			if (res[m] == 0)
				m++;
			else
				flag = 1;
		}
		flag = 0;

		for (int i = m; i < (generatorSize + m); i++)
		{
			if (res[i] == 0 || res[i] == 1)
				count++;
		}
		if (count == generatorSize)
		{
			for (int i = m; i < (generatorSize + m); i++)
			{
				res[i] = res[i] ^ generator[k];
				k++;
			}
			k = 0;
		}
		else
			break;
		count = 0;
		n = (generatorSize + m) + 1;
	}

	rsize = frameSize - 1;

	for (int i = 1; i<generatorSize; i++)
	{
		frame[rsize] = res[rsize];
		rsize--;
	}

	rsize = frameSize - 1;
	int* rem = new int[rsize];
	for (int i = (generatorSize - 1); i>0; i--)
	{
		rem[i] = res[rsize];
		rsize--;
	}
	cout << "\nRemainder is ";
	for (int i = 1; i<generatorSize; i++)
		cout << rem[i]<< endl;
}

int main(void) {
	fill();
	calculate();
}