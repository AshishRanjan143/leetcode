/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
 //this can also be done by stack just push everything to stack then keep the pointer at front and move until N/2
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* temp=head;
        vector<int> vec;
        while(temp!=NULL){
            vec.push_back(temp->val);
            temp=temp->next;
        } 
        int i=0,j=vec.size()-1;
        int result=0;
        while(i<j){
            result=max(result,vec[i]+vec[j]);
            i++;
            j--;
        }
        return result;
    }
};
//using reversal in linked list approach -2
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        //1.Find mid
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* mid=slow;
        //2.Reverse from mid
        ListNode* prev=NULL;
        ListNode* nextNode=NULL;
        while(mid!=NULL){
            nextNode=mid->next;
            mid->next=prev;
            prev=mid;
            mid=nextNode;
        }
        //3.Find max Result
        int res=0;
        ListNode* curr=head;
        while(prev!=NULL){
            res=max(res,curr->val+prev->val);
            curr=curr->next;
            prev=prev->next;
        }
        return res;
        
    }
};