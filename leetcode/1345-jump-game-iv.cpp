#include <queue>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

class Solution {
public:
    int minJumps(vector<int>& arr)
    {
        int length = arr.size();
        if(1 == length) { return 0; }
        if(arr[0] == arr[length - 1]) { return 1; }

        queue<int> bfs;
        vector<int> dist(length);
        vector<bool> visited(length, false);
        unordered_map<int, vector<int>> idxSameValue;

        for(int idx = 0; idx < length; ++idx)
        {
            idxSameValue[arr[idx]].push_back(idx);
        }

        bfs.push(0);
        dist[0] = 0;
        visited[0] = true;

        while (!bfs.empty())
        {
            int idx = bfs.front();
            int step = dist[idx];
            bfs.pop();

            if(idx == length - 1) { return step; }

            ++step;
            for(auto item : idxSameValue[arr[idx]])
            {
                if(!visited[item])
                {
                    bfs.push(item);
                    dist[item] = step;
                    visited[item] = true;
                }
            }
            idxSameValue.erase(arr[idx]);

            if(idx > 1 && !visited[idx - 1])
            {
                bfs.push(idx - 1);
                dist[idx - 1] = step;
                visited[idx - 1] = true;
            }

            if(idx < length - 1 && !visited[idx + 1])
            {
                bfs.push(idx + 1);
                dist[idx + 1] = step;
                visited[idx + 1] = true;
            }
        }
        return -1;
    }
};


int main()
{
    vector a{51,64,-15,58,98,31,48,72,78,-63,92,-5,64,-64,51,-48,64,48,-76,-86,-5,-64,-86,-47,92,-41,58,72,31,78,-15,-76,72,-5,-97,98,78,-97,-41,-47,-86,-97,78,-97,58,-41,72,-41,72,-25,-76,51,-86,-65,78,-63,72,-15,48,-15,-63,-65,31,-41,95,51,-47,51,-41,-76,58,-81,-41,88,58,-81,88,88,-47,-48,72,-25,-86,-41,-86,-64,-15,-63};
    Solution solution;
    cout << solution.minJumps(a);
}