#pragma once
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
	void set(); /*Sets the values of Frame bits.*/
	string CalculationOfCRC(); /*Calculates the remainder and returns the frame to be sent.*/
	void verify(string newFrame); /*Checks whether a transmitted frame is correct or not.*/

};
