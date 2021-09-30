#include <iostream>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *p = l1, *q = l2;
        ListNode* Result = new ListNode;
        ListNode* r = Result;
        int count = 0;
        for(; p && q; p = p->next, q = q->next){
            if(p->val+q->val+count>9){
                r->val = (p->val+q->val+count)%10;
                count = 1;
            }
            else{
                r->val = p->val+q->val+count;
                count = 0;
            }
            r->next = new ListNode;
            r = r->next; 
        }
        if(p||q){
            p = (p ? p : q);  
            for(; p; p = p->next){
                if(p->val+count>9){
                    r->val = (p->val+count) % 10;
                    count = 1;
                }
                else{
                    r->val = (p->val+count);
                    count = 0;
                }
                r->next = new ListNode;
                r = r->next;
            }
        }
        if(count==1){
            r->val = count;
        }
        else
            delete r;
        return Result;
    }
};
    
int main(){
        int array1[] = {2,4,3};
        int array2[] = {5,6,4};
        ListNode* L1 = new ListNode;
        ListNode* r1 = L1;
        ListNode* L2 = new ListNode;
        ListNode* r2 = L2;

        for(int i=0; i< 3; i++){
            r1->val = array1[i];
            r1->next = new ListNode;
            r1 = r1->next;
        }
         
        for(int i=0; i< 3; i++){
            r2->val = array2[i];
            r2->next = new ListNode;
            r2 = r2->next;
        }
        delete r1;
        delete r2;
        Solution S1;
        ListNode* Result = S1.addTwoNumbers(L1,L2);
        for(ListNode* p1 = Result; p1; p1=p1->next){
            cout<<p1->val<<" ";
        }         
    }
    