#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <queue>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
#include<cstring>
using namespace std;
struct ListNode {
     int val;
     ListNode()
     {

     }
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };

typedef pair<int,int> pii;

class Solution {
public:
    void DFS(vector<vector<int>>& richer,vector<int>& quiet, int i, vector<bool>& visited, vector<int>& answer )
    {
        int n = quiet.size(); 
        int m = richer.size();
        for(int j=0; j<m; j++)
        {
            if(richer[j][1]==i)
            {
                if(!visited[j])
                {
                    visited[j] = true;
                    DFS(richer, quiet, j, visited, answer);
                }
                if(quiet[answer[i]]>quiet[answer[j]])
                    answer[i] = answer[j];
            }
        }
    }
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        queue<int> q;
        vector<int> answer(n, 0);
        vector<bool> visited(n,false);
        for(int i=0; i<n; i++)
        {
            visited[i] = false;
            answer[i] = i;
        }
        for(int i=0; i<n; i++)
        {
            if(!visited[i])
            {
                DFS(richer, quiet, i, visited, answer);
            }
        }

        return answer;
    }
};

int main()
{
vector<vector<int>> richer = {{1,0},{2,1},{3,1},{3,7},{4,3},{5,3},{6,3}};
vector<int> quiet = {3,2,5,4,6,1,7,0};
 Solution sol;
 auto result = sol.loudAndRich(richer,quiet);
    return 0;
}