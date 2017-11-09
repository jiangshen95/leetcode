#include<iostream>
#include<string.h>

using namespace std;

class Solution{
	public:
		int longestValidParentheses(string s){
			if(s.length()<2){
				return 0;
			}
			
			int dp[s.length()];
			for(int i=0;i<s.length();i++) dp[i]=0;
			
			int max_len=0;
			
			for(int i=1;i<s.length();i++){
				if(s[i]==')'&&s[i-1]=='('){
					if(i-2>=0) dp[i]=dp[i-2]+2;
					else dp[i]=2;
				}
				else if(s[i]==')'&&s[i-1]==')'){
					if(i-dp[i-1]-1>=0&&s[i-dp[i-1]-1]=='('){
						dp[i]= (i-dp[i-1]-2>=0 ? dp[i-dp[i-1]-2] : 0)+dp[i-1]+2;
					}
				}
				if(dp[i]>max_len){
					max_len=dp[i];
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
