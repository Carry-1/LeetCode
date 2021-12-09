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
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return {-1,-1};
        vector<int> result(2,-1);
        int low = 0, high = nums.size()-1, mid = 0;
        int found = 0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if(nums[mid]==target)
            {
                found = 1;
                break;
            }
            else if(nums[mid]>target)
            {
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        if(!found)
            return {-1,-1};
        low = 0; 
        high = nums.size()-1;
        while(low<=high)
        {
            mid = (low+high)/2;
            if((mid==0&&nums[mid]==target)||(nums[mid-1]<target&&nums[mid]==target))
            {
                result[0] = mid;
                break;
            }
            else if(nums[mid]>=target)
            {
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        low = 0, high = nums.size()-1, mid = 0;
        while(low<=high)
        {
            mid = (low+high)/2;
            if((mid==nums.size()-1&&nums[mid]==target)||(nums[mid]==target&&nums[mid+1]>target))
            {
                result[1] = mid;
                break;
            }
            else if(nums[mid]>target)
            {
                high = mid -1;
            }
            else{
                low = mid+1;
            }
        }
        return result;

    }
};

int main()
{
vector<int> nums = {1,4};
int target = 4;
    Solution sol;
    vector<int> result = sol.searchRange(nums, target);
    return 0;
}