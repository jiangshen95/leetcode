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
		
		ListNode *pre,*curr,*temp,*nex;
		ListNode *first=new ListNode(0);
		pre=first;
		pre->next=head;
		while(1){
			curr=pre;
			int i;
			for(i=0;i<k;i++){
				curr=curr->next;
				if(curr==NULL){
					break;
				}
			}
			if(i!=k){
				break;
			}
			curr=pre->next;
			temp=curr->next;
			for(i=0;i<k-1;i++){
				nex=temp->next;
				temp->next=pre->next;
				pre->next=temp;
				curr->next=nex;
				temp=nex;
			}
			pre=curr;
		}
		
		return first->next;
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
