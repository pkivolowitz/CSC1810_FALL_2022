#include <iostream>

//	This is a single line comment. It can appear on a line
//	by itself or to the RIGHT of code (not recommended).

/*	This is a multiline comment. It makes writing extended
	documentation easier.
*/

//	For now, think of the following line as a typing saver.
using namespace std;


int main() {
	/*	"const" means the value cannot be changed after being set.

		"int32_t" is the precise way of saying signed 32 bit integer.
		Using "int" instead of "uint32_t" means the same thing almost
		all the time. "int32_t" always means the same thing.
	*/
	const int32_t NUM_NAS = 16;

	/*	The "for" loop is a way of repeating what's between the { }
		"braces" a specific number of times.
	*/
	for (int32_t na_counter = 0; na_counter <= NUM_NAS; na_counter++) {
		cout << "Na ";
	}
	cout << "Batman!" << endl;
	return 0;
}
