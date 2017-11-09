#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x),next(NULL){}
};

class Solution{
	public:
		ListNode* removeNthFromEnd(ListNode* head,int n){
			ListNode *p,*q,*last;
			p=head;
			if(p->next==NULL){
				return NULL;
			}
			q=p;
			while(q->next!=NULL){
				q=p;
				for(int i=0;i<n;i++){
					q=q->next;
					if(q==NULL&&p==head){
						return head->next;
					}
				}
				cout<<"p: "<<p->val<<"-------";
				cout<<"q: "<<q->val<<endl;
				last=p;
				p=p->next;
			}
			last->next=last->next->next;
			
			return head;
		}
};

int main(){
	int n;
	cin>>n;
	int num;
	cin>>num;
	ListNode *p=new ListNode(num);
	ListNode *head=p;
	for(int i=1;i<n;i++){
		cin>>num;
		ListNode *q=new ListNode(num);
		p->next=q;
		p=q;
	}
	p->next=NULL;
	
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	head=solution->removeNthFromEnd(head,target);
	
	while(head!=NULL){
		cout<<head->val<<endl;
		head=head->next;
	}
	
	return 0;
}
