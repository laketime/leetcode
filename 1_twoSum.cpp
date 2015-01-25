
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
		vector<int> rslt;
        map<int, int> mapVal2Idx;
        for (size_t i = 0, n = numbers.size(); i != n; ++i)
        {
            int fn = target - numbers[i];
            map<int, int>::iterator it = mapVal2Idx.find(fn);
            if (it != mapVal2Idx.end())
            {
                rslt.push_back(it->second);
                rslt.push_back(i);
				break;
            }
            else
            {
                mapVal2Idx[ numbers[i] ] = i;
            }
        }
		return rslt;
    }
};

int main(int argc, char * argv[])
{
	Solution sl;
	
	vector<int> numbers;
	numbers.push_back(3);
	numbers.push_back(2);
	numbers.push_back(4);
	int target = 6;
    vector<int> v = sl.twoSum(numbers, target);
	for (int i = 0, n = v.size(); i < n; ++i)
	{
		printf("%d\n", v[i]);
	}
}
