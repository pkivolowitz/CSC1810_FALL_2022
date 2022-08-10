#include <iostream>
#include <iomanip>

using namespace std;

/*	This version of enumerating argv makes use of the pointers directly so
	is a bit more advanced. You'll do just fine sticking with args1.cpp.

	Suppose the program is called by: prog one two three

	argv is an array in memory that looks like this:

	address of "prog"
	address of "one"
	address of "two"
	address of "three"
	zero (or nullptr)

	Given this example, can you work out the rest?
*/

int main(int argc, char * argv[]) {
	int32_t counter = 0;
	while (*argv != nullptr) {
		cout << "Argument [" << setw(3) << counter << "] is " << *argv << endl;
		argv++;
		counter++;
	}
	return 0;
}
