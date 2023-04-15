#include <vector>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> getFolderNames(vector<string>& names)
    {
        unordered_map<string, int> assigned;
        for(auto &name : names)
        {
            int count = assigned[name];
            if(0 != count)
            {
                while (assigned[name + '(' + to_string(count) + ')'])
                {
                    count++;
                }
                assigned[name] = count + 1;
                name += '(' + to_string(count) + ')';
            }
            assigned[name] = 1;
        }
        return names;
    }
};