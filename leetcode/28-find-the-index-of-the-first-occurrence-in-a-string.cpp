#include <iostream>
#include <string>
#include <iterator>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle)
    {
        return  (int)haystack.find(needle);
    }
};

int main()
{
    string a("abcdefg");
    string b("h");

    Solution solution;
    cout << solution.strStr(a, b);
}