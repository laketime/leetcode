
#include <string>

using namespace std;

class Solution {
	public:
		int lengthOfLongestSubstring(string s) {
			int idx[256] = {0};		
			int pos = 0;
			int maxlen = 0;

			for (size_t i = 0, n = s.size(); i != n; ++i)
			{
				char c = s[i];

				if (idx[c] > 0 && idx[c] > pos) {
					pos = idx[c];
				}

				int len = i + 1 - pos;
				idx[c] = i + 1;
				if (maxlen < len) maxlen = len;
			}

			return maxlen;
		}
};

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("usage: %s <string>\n", argv[0]);
		exit(1);
	}

	string s = argv[1];

	Solution sl;
	printf("%s -> %d\n", s.c_str(), sl.lengthOfLongestSubstring(s));

	return 0;
}
