#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    long long minimumTime(vector<int>& time, int totalTrips)
    {
        ios::sync_with_stdio(false);
        cout.tie(0);

        long long lowerBound = 1L;
        long long upperBound = 10e14;

        while (lowerBound < upperBound)
        {
            bool flag = false;
            long long totalCoat = 0L;
            long long mid = (lowerBound + upperBound) >> 1;

            for(int eachTime : time)
            {
                totalCoat += mid/eachTime;
                flag = totalCoat >= totalTrips;
                if(flag) { break; }
            }

            if (flag)
            {
                upperBound = mid;
            }
            else
            {
                lowerBound = mid + 1;
            }
        }
        return lowerBound;
    }
};

int main()
{
    Solution solution;
    vector<int> a{2};
    int b = 1;
    cout << solution.minimumTime(a, b) << endl;
}