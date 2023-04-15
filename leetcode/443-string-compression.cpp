#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    int compress(vector<char>& chars)
    {
        int left;
        int count;
        int write = 0;
        int length = (int)chars.size();

        for(int read = 0; read < length; ++read)
        {
            left = read;
            while (read + 1 < length && chars[read] == chars[read + 1])
            {
                ++read;
            }

            count = read - left + 1;
            chars[write++] = chars[read];
            if(count > 1)
            {
                for(char c: to_string(count))
                {
                    chars[write++] = c;
                }
            }

        }
        return write;
    }
};