#include "simple_csv.hpp"

using namespace std;

/*	These trim tools are adapted from:
	http://www.martinbroadhurst.com/how-to-trim-a-stdstring.html
*/

static string & ltrim(string & str, const string & chars = "\t\n\v\f\r ")
{
    str.erase(0, str.find_first_not_of(chars));
    return str;
}
 
static string & rtrim(string & str, const string & chars = "\t\n\v\f\r ")
{
    str.erase(str.find_last_not_of(chars) + 1);
    return str;
}
 
static string & trim(string & str, const string & chars = "\t\n\v\f\r ")
{
    return ltrim(rtrim(str, chars), chars);
}

/*	End adaptation.
*/

/*	I am not in love with this for several reasons.
*/

static string sso_trim(string str, uint32_t sso) {
	if (!(sso & SS_NOTRIMMING)) {
		if (sso & SS_TRIM) {
			str = trim(str);
		}
		if (sso & SS_NOQUOTES) {
			str = trim(str, "\"");
		}
	}
	return str;
}

/*	This is simple because, for instance, delimiter cannot be escaped.
*/

vector<string> SimpleSplit(string &input, char delimiter, uint32_t sso) {
	vector<string> tokens;
	size_t pos;

	while ((pos = input.find(delimiter)) != string::npos) {
		tokens.push_back(sso_trim(input.substr(0, pos), sso));
		input.erase(0, pos  + 1);
	}
	if (input.size() > 0) {
		tokens.push_back(sso_trim(input, sso));
	}
	return tokens;
}
