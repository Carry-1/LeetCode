#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<unordered_set>
using namespace std;
class Solution {
public:
    string intToRoman(int num) {
        string result;        
        map<int, string, greater<int>> m1 =
        {   
            {1000, "M"},
            {900, "CM"},
            {500, "D"},
            {400, "CD"}, 
            {100, "C"},
            {90, "XC"},
            {50, "L"},
            {40,"XL"},
            {10, "X"},
            {9,"IX"},
            {5, "V"},
            {4,"IV"},
            {1, "I"}
        };
        while(num>0)
        {
            auto ite = m1.begin();
            for(; ite != m1.end(); ite++)
            {
                if(num >= ite->first)
                {
                    num-=ite->first;
                    result+=ite->second;        
                }
            }
        }
        return result;
    }
};
int main(){
        int num = 20;
        Solution sol;
        cout<<sol.intToRoman(num);
    }
    