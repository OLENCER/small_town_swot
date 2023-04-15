#include <vector>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& nums)
    {
        int count = 0;
        int length = nums.size();
        for(int i = 0; i < length; ++i)
        {
            for(int j = 0; j < length; ++j)
            {
                for(int k = 0; k < length; ++k)
                {
                    if((nums[i] & nums[j] & nums[k]) == 0)
                    {
                        ++count;
                    }
                }
            }
        }
        return count;
    }
};