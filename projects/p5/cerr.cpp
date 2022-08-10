#include <iostream>

using namespace std;

const int32_t MAX_LINES = 1000;
const int32_t MAGIC_ERROR_LINE = 654;

int main() {
	for (int32_t counter = 0; counter < MAX_LINES; counter++) {
		if (counter == MAGIC_ERROR_LINE) {
			cerr << "Uh oh.  Bad!\n";
		} else {
			cout << "All is well!\n";
		}
	}
	return 0;
}