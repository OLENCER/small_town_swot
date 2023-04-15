#include <vector>
#include <unordered_map>

using namespace std;

class Solution{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        unordered_map<int, int> hashTable;
        for(int i = 0; i < nums.size(); ++i)
        {
            auto it = hashTable.find(target - nums[i]);
            if(it != hashTable.end())
            {
                return {it->second, i};
            }
            else
            {
                hashTable[nums[i]] = i;
            }
        }
        return {};

    }
};