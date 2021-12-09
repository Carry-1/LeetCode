#include <iostream>
#include <vector>
#include <map>
#include <string>
#include<unordered_set>
#include<unordered_map>
#include<algorithm>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
class Solution {
public:
    ListNode* Merge(ListNode* l1, ListNode* l2)
    {
        //合并两链表，将l2插入l1中   
        if(!l1||!l2)
        {
            if(l2)
                return l2;
            else
                return l1;
        }
        ListNode* result = new ListNode;

        ListNode* rear = result;
        
        ListNode* p;
        while(l1&&l2)
        {
            if(l1->val<=l2->val)
            {
                p = l1;
                l1 = l1->next;
            }
            else
            {
                p = l2;
                l2 = l2->next;
            }   
            rear->next = p;
            p->next = nullptr;
            rear = p;
        }
        while(l1)
        {
            p = l1;
            l1 = l1->next;
            rear->next = p;
            p->next = nullptr;
            rear = p;
        }
        while(l2)
        {
            p = l2;
            l2 = l2->next;
            rear->next = p;
            p->next = nullptr;
            rear = p;
        }
        rear->next = nullptr;
        return result->next;
    }
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0)
            return 0;
        else if(lists.size()==1)
            return lists[0];
        else
        {
            ListNode* l1=lists[0];
            ListNode* l2=lists[1];
            if(lists.size()>2)
            {
                vector<ListNode*> lists1;
                vector<ListNode*> lists2;
                for(int i=0; i<lists.size()/2; i++)
                {
                    lists1.push_back(lists[i]);
                }
                for(int i=lists.size()/2; i<lists.size(); i++)
                {
                    lists2.push_back(lists[i]);
                }
                l1 = mergeKLists(lists1);
                l2 = mergeKLists(lists2);

            }
            return Merge(l1, l2);

            
        }
        
    }
};

int main()
{
    vector<vector<int>> Input = {{2},{},{-1}};
    vector<ListNode*> lists;
    for(int i =0; i<Input.size(); i++)
    {
        ListNode* l = nullptr;
        ListNode* rear = l;

        for(int j=0; j<Input[i].size(); j++)
        {
            
            ListNode* p = new ListNode;
            p->val = Input[i][j];
            p->next = nullptr;
            if(j==0)
            {
                l = p;
                rear = p;
            }
            else{
                rear->next = p;
                rear = p;
            }

        }
        
        lists.push_back(l);
    }
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);

    INT_MIN
    return 0;
}