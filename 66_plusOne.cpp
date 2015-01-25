

#include <vector>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
		int extra = 1;
		for (int i = digits.size(); extra && i > 0; --i)
		{
			if (digits[i - 1] == 9)
			{
				digits[i - 1] = 0;
				extra = 1;
			}
			else
			{
				++digits[i - 1];
				extra = 0;
			}
		}

		if (extra)
		{
			digits.insert(digits.begin(), extra);
		}
        
		return digits;
    }
};

void getVal(const char * s, vector<int> & v)
{
	while (*s)
	{
		v.push_back(*s - '0');
		++s;
	}
}

void printVecInt(vector<int> & vint)
{
	copy(vint.begin(), vint.end(), ostream_iterator<int>(cout, ""));
}

int main(int argc, char * argv[])
{
	if (argc < 2)
	{
		printf("usage: %s <digit>\n", argv[0]);
		exit(1);
	}

	vector<int> vint;
	getVal(argv[1], vint);

	printVecInt(vint);
	cout << endl;

	Solution sl;
	sl.plusOne(vint);
	printVecInt(vint);
	cout << endl;

	return 0;
}

