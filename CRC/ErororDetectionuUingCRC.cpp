#include "ErororDetectionuUingCRC.h"

string alter(string frame) {
	cout << "Do you wish to flip a bit? (Y|N)" << endl;
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
