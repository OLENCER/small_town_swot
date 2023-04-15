#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        size_t length = nums.size();
        ::qsort()

        if(nums[0] > 0 || nums[length - 1] < 0)
        {
            return ans;
        }

        for(size_t first = 0; first < length - 2; ++first)
        {
            if(first > 0 && nums[first] == nums[first - 1])
            {
                continue;
            }

            int target = -nums[first];
            size_t third = length - 1;
            for(size_t second = first + 1; second < length - 1; ++second)
            {
                if(second > first + 1 && nums[second] == nums[second - 1])
                {
                    continue;
                }

                while (second < third && nums[second] + nums[third] > target)
                {
                    --third;
                }

                if(second == third)
                {
                    break;
                }

                if(nums[second] + nums[third] == target)
                {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }
        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> a {-1,0,1,2,-1,-4};
    vector<vector<int>> b = solution.threeSum(a);
    for(vector<int> c : b)
    {
        for(int d : c)
        {
            cout << d << " ";
        }
        cout << endl;
    }
}