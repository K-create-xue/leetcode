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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==NULL)
        return l2;
        ListNode* cur=l1;
        while(cur->next){
            cur=cur->next;
        }
        cur->next=l2;
        cur=l1;
        vector<int> v;
        while(cur){
            v.push_back(cur->val);
            cur=cur->next;
        }
        std::sort(v.begin(),v.end());
        cur=l1;
        int i=0;
        while(cur){
            cur->val=v[i++];
            cur=cur->next;
        }
        return l1;
       /*
        if(l1==NULL)
        return l2;
        if(l2==NULL)
        return l1;
        //ListNode* newHead=NULL;
        ListNode* newHead=(ListNode*)malloc(sizeof(ListNode));
        // if(l1->val<=l2->val){
        //     newHead=l1;
        //     l1=l1->next;
        // }else{
        //     newHead=l2;
        //     l2=l2->next;
        // }
        ListNode* cur=newHead;
        while(l1 && l2){
            if(l1->val<=l2->val){
                cur->next=l1;
                cur=l1;
                l1=l1->next;
            }else{
                cur->next=l2;
                cur=l2;
                l2=l2->next;
            }
        }
        if(l1==NULL)
        cur->next=l2;
        else if(l2==NULL)
        cur->next=l1;
       // return newHead;
       cur=newHead->next;
       free(newHead);
       return cur;
    */

    }
};
