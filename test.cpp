#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    string replaceSpace(string s) {
    string delim = "%20";
    for(int i=0; i<s.size(); i++)
    {
        if(s[i]==' ')
        {
            string pre = s.substr(0,i);
            string post = s.substr(i+1,s.size()-i-1);
            s = pre + delim + post;
            i += delim.size();
        }
    }
    return s;
    }
};
int main()
{
    string s = "  ";
    Solution sol;
    cout<<sol.replaceSpace(s);
    return 0;
}