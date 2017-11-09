#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution{
	public:
		bool isValid(string s){
			vector<char> stack;
			stack.push_back(s[0]);
			for(int i=1;i<s.length();i++){
				if((stack.back()=='('&&s[i]==')')||(stack.back()=='['&&s[i]==']')||(stack.back()=='{'&&s[i]=='}')){
					stack.pop_back();
				}else{
					if(s[i]==')'||s[i]==']'||s[i]=='}'){
						return false;
					}
					stack.push_back(s[i]);
				}
			}
			return stack.empty();
		}
};

int main(){
	string s;
	cin>>s;
	Solution *solution=new Solution();
	cout<<solution->isValid(s);
	return 0;
}
