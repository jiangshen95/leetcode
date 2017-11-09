#include<iostream>
#include<string.h>

using namespace std;

class Solution{
	public:
		int longestValidParentheses(string s){
			
			int left=0,right=0;
			int max_len=0;
			for(int i=0;i<s.length();i++){
				if(s[i]=='(') left++;
				else if(s[i]==')') right++;
				if(left<right){
					left=0;
					right=0;
				}
				else if(left==right){
					if(left*2>max_len){
						max_len=left*2;
					}
				}
			}
			
			left=0;
			right=0;
			for(int i=s.length()-1;i>=0;i--){
				if(s[i]==')') right++;
				else if(s[i]=='(') left++;
				if(left>right){
					left=0;
					right=0;
				}
				else if(left==right){
					if(left*2>max_len){
						max_len=left*2;
					}
				}
			}
			
			
			return max_len;
		}
};

int main(){
	string s;
	cin>>s;
	
	Solution *solution=new Solution();
	cout<<solution->longestValidParentheses(s);
	
	return 0;
}
