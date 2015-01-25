#include <string>
#include <stdlib.h>

using namespace std;

class Solution {
public:
	void reverseWords(string & s)
	{
		int beg = s.size() - 1;
		int end = beg;
		bool in_word = false;
		string tmp;
		for (int i = s.size() - 1; i >= 0; --i)
		{
			if (isspace(s[i]))
			{
				if (in_word) {
					if (!tmp.empty()) tmp.push_back(' ');
					tmp.append(s.begin() + i + 1, s.begin() + end + 1);

					in_word = false;
				}
			}
			else
			{
				if (!in_word) {
					end = i;
					in_word = true;
				}
			}
		}
		if (in_word) {
			if (!tmp.empty()) tmp.push_back(' ');
			tmp.append(s.begin(), s.begin() + end + 1);
		}
		s.swap(tmp);
	}
};

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("usage: %s <string>\n", argv[0]);
		exit(1);
	}

	Solution sl;
	string s = argv[1];
	printf("'%s'\n", s.c_str());
	sl.reverseWords(s);
	printf("'%s'\n", s.c_str());
}
