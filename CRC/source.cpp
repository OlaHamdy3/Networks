#include "ErororDetectionuUingCRC.h"
int main(void) {
	ErororDetectionuUingCRC c;
	c.set();
	string frame= c.CalculationOfCRC();
	cout << "The final frame to be sent is: " << frame << endl;
	frame = alter(frame);
	c.verify(frame);
	return 0;
}
