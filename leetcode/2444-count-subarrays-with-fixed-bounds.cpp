#include <vector>

using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        long long res = 0L;
        int length = (int)nums.size();
        int right = -1, minI = -1, maxI = -1;

        for(int left = 0; left < length; ++left)
        {
            if(nums[left] < minK || nums[left] > maxK) { right = left; }
            if(nums[left] == minK) { minI = left; }
            if(nums[left] == maxK) { maxI = left; }

            res += max(min(minI, maxI) - right, 0);
        }
        return res;
    }
};