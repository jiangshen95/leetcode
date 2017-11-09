#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL){}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
        	return head;
		}
		
		ListNode *p,*q,*last;
		
		p=new ListNode(0);
		
		p->next=head;
		head=head->next;
		while(p->next!=NULL&&p!=NULL){
			
			last=p;
			
			p=p->next;
			
			if(p->next!=NULL){
				q=p->next;
				p->next=q->next;
				q->next=p;
			
				if(q!=head){
					last->next=q;
				}
			}
		}
		
		return head;
    }
};

int main(){
	int n;
	cin>>n;
	int num;
	cin>>num;
	ListNode *head;
	ListNode *p=new ListNode(num);
	head=p;
	for(int i=1;i<n;i++){
		cin>>num;
		ListNode *q=new ListNode(num);
		p->next=q;
		p=q;
	}
	p->next=NULL;
	
	Solution *solution=new Solution();
	head=solution->swapPairs(head);
	while(head!=NULL){
		cout<<head->val<<endl;
		head=head->next;
	}
	
	return 0;
}
