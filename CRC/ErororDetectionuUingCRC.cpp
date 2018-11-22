#include "ErororDetectionuUingCRC.h"

string alter(string frame) {
	cout << "Do you wish to flip a bit? (Y|N)" << endl; /*Can be Y, y, N, or n.*/
	char c;
	cin >> c;
	if (c == 'Y' || c == 'y') {
		cout << "Enter the index of the bit to be flipped (index of the first bit is 1): ";
		int index;
		cin >> index;
		if (index - 1 < frame.length()) {
			if (frame[index - 1] == '0') {
				frame[index - 1] = '1';
			}
			else {
				frame[index - 1] = '0';
			}
		}
	}
	return frame;
}


void ErororDetectionuUingCRC::set() {
	cout << "Enter the frame to be sent: ";
	cin >> frame;
	frameSize = frame.length();
	cout << "Enter the generator bits: ";
	cin >> generator;
	generatorSize = generator.length();
	cout << "The original message is: " << frame << endl;
	cout << "The generator bits are: " << generator << endl;
}

string ErororDetectionuUingCRC::CalculationOfCRC() {
	int n = 0, m = 0, flag = 0, k = 0, count = 0;
	/*Generating the frame with zero appended to use it for the remainder calculations.*/
	string frameWithZerosAppended = frame;
		for (int i = 0; i < generatorSize - 1; i++) {
			frameWithZerosAppended += '0';
		}
	/*Convirting the string frame with zero appended to integer.*/
	int* message = new int[frameSize + generatorSize - 1];
	for (int i = 0; i < frameSize+generatorSize; i++) {
		if (frameWithZerosAppended[i] == '1') {
			message[i] = 1;
		}
		else {
			message[i] = 0;
		}
	}
	/*Convirting the string generator bits to integer.*/
	int* divisor = new int[generatorSize];
	for (int i = 0; i < generator.length(); i++) {
		if (generator[i] == '1') {
			divisor[i] = 1;
		}
		else {
			divisor[i] = 0;
		}
	}
	/*Calculating the remainder.*/
	frameSize = (frameSize + generatorSize) - 1;
	remainderSize = frameSize;
	int* remainder = new int[remainderSize];
	string remainderOfCRC = "";
	operationOutputSize = frameSize;
	int* operationOutput = new int[operationOutputSize];
	for (int i = 0; i < frameSize; i++) {
		operationOutput[i] = message[i];
	}
	for (int i = 0; i<generatorSize; i++){
		operationOutput[i] = message[i] ^ divisor[i];
		n = i;
	}

	while (n <= frameSize)
	{
		while (flag == 0)
		{
			if (operationOutput[m] == 0)
				m++;
			else
				flag = 1;
		}
		flag = 0;

		for (int i = m; i<(generatorSize + m); i++)
		{
			if (operationOutput[i] == 0 || operationOutput[i] == 1)
				count++;
		}
		if (count == generatorSize)
		{
			for (int i = m; i<(generatorSize + m); i++)
			{
				operationOutput[i] = operationOutput[i] ^ divisor[k];
				k++;
			}
			k = 0;
		}
		else
			break;
		count = 0;
		n = (generatorSize + m) + 1;
	}

	remainderSize = frameSize - 1;

	for (int i = 1; i<generatorSize; i++)
	{
		message[remainderSize] = operationOutput[remainderSize];
		remainderSize--;
	}
	remainderSize = frameSize - 1;

	for (int i = (generatorSize - 1); i>0; i--)
	{
		remainder[i] = operationOutput[remainderSize];
		remainderSize--;
	}
	for (int i = 1; i < generatorSize; i++) {
		if (remainder[i] == 0)
			remainderOfCRC += '0';
		else
			remainderOfCRC += '1';
	}
	/*Convering the integer array remainder to string.*/
	string finalFrame = "";
	for (int i = 0; i < frameSize; i++) {
		if (message[i] == 0) {
			finalFrame += '0';
		}
		else {
			finalFrame += '1';
		}
	}
	/*Printing all outputs.*/
	rOfCrc = remainderOfCRC;
	cout << "The frame with zeros appended used to calculate the CRC remainder is: " << frameWithZerosAppended << endl;
	cout << "The remainder is: " << remainderOfCRC << endl;
	/*Return value.*/
	return finalFrame;
}

void ErororDetectionuUingCRC::verify(string newFrame) {
	frame = newFrame; /*Frame to be tested.*/
	CalculationOfCRC(); /*Getting the remainder*/
	if (stoi(rOfCrc) == 0) { /*Verify*/
		cout << "No error occured while transmitting the frame." << endl;
	}
	else {
		cout << "An error occured while transmitting the frame." << endl;
	}
}
