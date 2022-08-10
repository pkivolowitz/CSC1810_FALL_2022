#include <iostream>
#include <iomanip>

using namespace std;

/*	It is important to note that argv[index] is the address of a C string and
	NOT A C++ "string". A C string is an array of characters with the very last
	character being zero (or NULL). The terminating NULL is what is used to 
	determine where the last character in the C string is.
*/

int main(int argc, char * argv[]) {
	for (int32_t index = 0; index < argc; index++) {
		cout << "Argument [" << setw(3) << index << "] is " << argv[index] << endl;
	}
	return 0;
}
