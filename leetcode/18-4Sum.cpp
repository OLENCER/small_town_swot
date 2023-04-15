#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target)
    {
        vector<int> path;
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());

        nSum(nums, 4, target, 0, (int)nums.size() - 1, path, ans);
        return ans;
    }

private:
    void nSum(const vector<int>& nums, long n, long target, int l, int r,
              vector<int>& path, vector<vector<int>>& ans) {
        if (r - l + 1 < n || target < nums[l] * n || target > nums[r] * n)
            return;
        if (n == 2) {
            // Very similar to the sub procedure in 15. 3Sum
            while (l < r) {
                const int sum = nums[l] + nums[r];
                if (sum == target) {
                    path.push_back(nums[l]);
                    path.push_back(nums[r]);
                    ans.push_back(path);
                    path.pop_back();
                    path.pop_back();
                    ++l;
                    --r;
                    while (l < r && nums[l] == nums[l - 1])
                        ++l;
                    while (l < r && nums[r] == nums[r + 1])
                        --r;
                } else if (sum < target) {
                    ++l;
                } else {
                    --r;
                }
            }
            return;
        }

        for (int i = l; i <= r; ++i) {
            if (i > l && nums[i] == nums[i - 1])
                continue;
            path.push_back(nums[i]);
            nSum(nums, n - 1, target - nums[i], i + 1, r, path, ans);
            path.pop_back();
        }
    }
};

int main()
{
    Solution solution;
    vector<int> a {-3,-2,-1,0,0,1,2,3};
    vector<vector<int>> b = solution.fourSum(a, 0);
    for(const vector<int>& c : b)
    {
        for(int d : c)
        {
            cout << d << " ";
        }
        cout << endl;
    }
}
