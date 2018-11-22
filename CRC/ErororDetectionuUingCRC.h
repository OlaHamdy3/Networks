//#pragma once
#include <iostream>
#include <string>
using namespace std;

class ErororDetectionuUingCRC
{
private:
	int frameSize, generatorSize, operationOutputSize, remainderSize;
	string frame;
	string generator;
	string rOfCrc;

public:
	void set();
	string CalculationOfCRC();
	void verify(string newFrame);

};
