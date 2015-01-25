
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
	inline void reverse(string & s) {
		for (size_t i = 0, n = s.size(); i < n / 2; ++i)
		{
			std::swap(s[i], s[n - 1 - i]);
		}
	}
	inline int popVal(string & s, int & pos)
	{
		if (pos > 0)
		{
			return (s[--pos] - '0');
		}
		return 0;
	}
    string addBinary(string a, string b) {
		string rslt;

		int an = a.size(), bn = b.size();
		int extra = 0;
		while (an > 0 || bn >0 || extra)
		{
			int t = popVal(a, an) + popVal(b, bn) + extra;
			rslt.push_back((t & 0x1) + '0');
			extra = (t >> 1);
		}

		if (rslt.empty()) rslt.push_back('0');
		reverse(rslt);
        
		return rslt;
    }
};

int main(int argc, char * argv[])
{
	if (argc < 3)
	{
		printf("usage: %s <binary_a> <binary_b>\n", argv[0]);
		exit(1);
	}

	string a = argv[1];
	string b = argv[2];
	Solution sl;
	
	cout << a << " + " 
		 << b << " = " 
		 << sl.addBinary(a, b) 
		 << endl;

	return 0;
}
