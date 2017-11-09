#include<iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL){}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==NULL || head->next==NULL||k==1){
        	return head;
		}
		
		ListNode *p,*q,*last,*r,*s;
		p=head;
		while(p!=NULL){
			int i;
			last=p;
			s=p;
			for(i=0;i<k-1;i++){
				s=s->next;
				//cout<<"i: "<<i<<"------"<<"s: "<<s->val<<endl;
				if(s==NULL){
					break;
				}
			}
			cout<<"i: "<<i<<"s: "<<s->val<<endl;
			if(i!=k-1){
				cout<<"i: "<<i<<endl;
				if(last==head){
					head=p;
				}
				break;
			}
			else{
				if(last==head){
					head=s;
				}
				cout<<"head: "<<head->val<<endl;
			}
			for(int i=0;i<k-1;i++){
				if(i==0){
					q=p->next;
				}
				else{
					p=q;
					q=r;
				}
				r=q->next;
				q->next=p;
				
				//cout<<"p: "<<p->val<<"------"<<"q: "<<q->val<<"------"<<"r: "<<r->val<<endl;
			}
			
			cout<<"r: "<<r<<endl;
			
			s=r;
			if(s!=NULL){
				for(i=0;i<k-1;i++){
					s=s->next;
					if(s==NULL){
						break;
					}
				}
			
				cout<<"i: "<<i<<endl;
			
				if(i!=k-1){
					s=r;
				}
			}
			
			
			//cout<<"s: "<<s->val<<"-------"<<"last: "<<last->val<<endl;
			
			last->next=s;
			p=r;
			
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
	
	int k;
	cin>>k;
	
	Solution *solution=new Solution();
	head=solution->reverseKGroup(head,k);
	while(head!=NULL){
		cout<<head->val<<endl;
		head=head->next;
	}
	
	return 0;
}
