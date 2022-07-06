#include <iostream>
#include <string>
#include <cctype>

using namespace std;

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

bool IsVowel(char c) {
	return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y');
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
