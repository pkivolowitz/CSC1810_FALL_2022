#include <iostream>
#include <string>
#include <cctype>

using namespace std;

/*	This is a multiline comment.
	It can stretch over several lines.
*/

// 	This is a single line comment.

/*	This is using the preprocessor to sort out the differences
	between platforms. On Windows, the ^z line will be active.
	On all else, the ^d line will be active.

	You won't need this for a year or more. But it is nice to
	see it once.
*/

#if __APPLE__ || __linux__ || __unix__
const string EOF_character("^d");
#else
const string EOF_character("^z");
#endif 

int32_t CountWhiteSpace(string l) {
	int32_t white_space_count = 0;
	for (uint32_t index = 0; index < l.size(); index++) {
		if (isspace(l.at(index))) {
			white_space_count++;
		}
	}
	return white_space_count;
}

/*	A comment that appears  immediately before a function also
	shows up when you hover over the function's name. Use this
	kind of comment to  help  you  remember  what the function
	does and how to use it.
*/
bool IsVowel(char c) {
	return (
		// This is interesting!  There are two ways of
		// writing "logical or". The old way "||"" and
		// the new way "or"
		c == 'a' || 
		c == 'e' || 
		c == 'i' || 
		c == 'o' or 
		c == 'u' or 
		c == 'y'
	);
}

int32_t CountVowels(string l) {
	int32_t vowel_count = 0;
	for (uint32_t index = 0; index < l.size(); index++) {
		if (IsVowel(l.at(index))) {
			vowel_count++;
		}
	}
	return vowel_count;
}

/*	main() will keep reading from the standard input until it receives
	an end-of-file. On Windows, this is ^z. Everywhere else, it is ^d.
	
	If the line is not empty, various statistics about the line will
	be printed.
*/
int main()
{
	string a_line_of_input;
	cout << "Enter a line of text (" << EOF_character << " to exit): ";
	while (getline(cin, a_line_of_input)) {
		if (a_line_of_input.size() > 0) {
			cout << "You entered: \"" << a_line_of_input << "\"" << endl;
			cout << "This text has " << a_line_of_input.size() << " total characters." << endl;
			cout << "Of these, " << CountWhiteSpace(a_line_of_input) << " are whitespace characters." << endl;
			cout << "And, " << CountVowels(a_line_of_input) << " are vowels." << endl;
		}
		cout << "Enter a line of text (^z to exit): ";
	}
	return 0;
}
