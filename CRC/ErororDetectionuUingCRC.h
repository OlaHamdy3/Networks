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

public:
	void set();
	string CalculationOfCRC();

};