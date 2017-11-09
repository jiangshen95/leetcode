#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution{
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
			
			if(l1==NULL){
				return l2;
			}
			if(l2==NULL){
				return l1;
			}
			
			ListNode *p,*q,*head;
			if(l1->val>l2->val){
				head=l2;
				q=l1;
			}else{
				head=l1;
				q=l2;
			}
			
			p=head;
			ListNode *last,*next;
			while(p->next!=NULL&&q!=NULL){
				cout<<"p: "<<p->val<<endl;
				if(p->val<=q->val&&p->next->val>=q->val){
					cout<<"p: "<<p->val<<"------"<<"q: "<<q->val<<endl;
					last=q;
					while(q->next!=NULL&&p->val<=q->next->val&&p->next->val>=q->next->val){
						
						q=q->next;
						cout<<"q: "<<q->val<<endl;
					}
					cout<<"q: "<<q->val<<endl;
					next=q;
					q=q->next;
					next->next=p->next;
					p->next=last;
					p=next;
				}
				p=p->next;
			}
			if(p->next==NULL){
				p->next=q;
			}
			return head;
		}
};

int main(){
	int m,n;
	cin>>m>>n;
	int num;
	cin>>num;
	ListNode *l1,*l2;
	ListNode *p=new ListNode(num);
	l1=p;
	for(int i=1;i<m;i++){
		cin>>num;
		ListNode *q=new ListNode(num);
		p->next=q;
		p=q;
	}
	p->next=NULL;
	
	cin>>num;
	p=new ListNode(num);
	l2=p;
	for(int i=1;i<n;i++){
		cin>>num;
		ListNode *q=new ListNode(num);
		p->next=q;
		p=q;
	}
	p->next=NULL;
	
	Solution *solution=new Solution();
	ListNode *marge=solution->mergeTwoLists(l1,l2);
	while(marge!=NULL){
		cout<<marge->val<<endl;
		marge=marge->next;
	}
	
	return 0;
	
}
