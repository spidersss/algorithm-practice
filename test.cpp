#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
struct ListNode {
   	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* Head = new ListNode(0);
        Head->val = (l1->val + l2->val)%10;
        Head->next = NULL;
        int a = (l1->val + l2->val)/10;
        ListNode* L = Head->next;
        ListNode* LL = Head;
        ListNode* LL1 = l1->next;
        ListNode* LL2 = l2->next;
        while(LL1 != NULL && LL2!=NULL){
            LL = L;
            LL = new ListNode(0);
            LL->val = (LL1->val + LL2->val + a)%10;
            a = (LL1->val + LL2->val + a)/10;
            LL1 = LL1->next; LL2 = LL2->next;  
            L = LL->next;
            delete LL;
        }
        L = NULL;
        return Head;
    }
};
int main(){
	ListNode* l1 = new ListNode(0);
	int a;
	ListNode* ll1 = l1->next;
	cin>>a;
	l1->val = a;
	while(cin>>a){
		if(a == -1) break;
		ll1->val = a;
		ll1 = ll1->next;
	}
	ll1 = NULL;
	free(ll1);
	ListNode* l2 = new ListNode(0);
	ListNode* ll2 = l2->next;
	cin>>a;
	l2->val = a;
	while(cin>>a){
		if(a == -1) break;
		ll2->val = a;
		ll2 = ll2->next;
	}
	ll2 = NULL;
	free(ll2);
	Solution A;
	ListNode* L = A.addTwoNumbers(l1, l2);
	ListNode* LL = L->next;
	cout<<L->val<<" ";
	while(LL!=NULL){
		cout<<LL->val<<" ";
		LL = LL->next;
	}
	delete(l1);
	delete(l2);
	return 0;
	
}
