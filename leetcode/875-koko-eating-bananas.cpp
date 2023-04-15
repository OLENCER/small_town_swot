#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int lowerBound = 1;
        int upperBound = *max_element(piles.begin(), piles.end());

        while (lowerBound < upperBound)
        {
            int cost = 0;
            int k = (lowerBound + upperBound) >> 1;

            for(int pile : piles)
            {
                cost += (pile + k - 1) / k;
            }

            if(cost <= h)
            {
                upperBound = k;
            }
            else
            {
                lowerBound = k + 1;
            }
        }
        return lowerBound;
    }
};

int main()
{
    vector<int> a{30,11,23,4,20};
    int h = 5;
    Solution solution;
    cout << solution.minEatingSpeed(a, h);
}