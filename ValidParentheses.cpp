#include<iostream>
#include<string.h>

using namespace std;

class Solution{
	public:
		bool isValid(string s){
			return strIsValid(s,0,s.length()-1);
		}
		bool strIsValid(string s,int l,int r){
			if(l>r){
				return true;
			}
			if(((s[l]=='('&&s[r]==')')||(s[l]=='['&&s[r]==']')||(s[l]=='{'&&s[r]=='}'))&&l+1==r){
				cout<<"1-----"<<"l: "<<l<<"------"<<"r: "<<r<<endl;
				return true;
			}
			else{
				if(l+1==r){
					cout<<"2-----"<<"l: "<<l<<"------"<<"r: "<<r<<endl;
					return false;
				}
				else{
					int i;
					for(i=l+1;i<=r;i++){
						if((s[l]=='('&&s[i]==')')||(s[l]=='['&&s[i]==']')||(s[l]=='{'&&s[i]=='}')){
							cout<<"3-----"<<"l: "<<l<<"------"<<"r: "<<r<<endl;
							if(strIsValid(s,l+1,i-1)){
								break;
							}
						}
					}
					if(i==r+1){
						cout<<"4-----"<<"l: "<<l<<"------"<<"r: "<<r<<endl;
						return false;
					}
					else{
						cout<<"5-----"<<"l: "<<l<<"------"<<"r: "<<r<<endl;
						return strIsValid(s,i+1,r);
					}
				}
			}
		}
};

int main(){
	string s;
	cin>>s;
	Solution *solution=new Solution();
	cout<<solution->isValid(s);
	return 0;
}
