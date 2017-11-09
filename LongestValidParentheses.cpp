#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
    	if(s.length()<=0){
    		return 0;
		}
        vector<char> stack;
        vector<int> pos_stack;
        stack.push_back(s[0]);
        pos_stack.push_back(0);
        for(int i=1;i<s.length();i++){
        	if(stack.back()=='('&&s[i]==')'){
        		stack.pop_back();
        		pos_stack.pop_back();
			}else{
				stack.push_back(s[i]);
				pos_stack.push_back(i);
			}
		}
		
		if(pos_stack.size()==0){
			return s.length();
		}
		
		int max_len;
		int l=0,r=s.length()-1;
		max_len=pos_stack[0]-l>r-pos_stack.back() ? pos_stack[0]-l : r-pos_stack.back();
		for(int i=0;i<pos_stack.size()-1;i++){
			if(pos_stack[i+1]-pos_stack[i]-1>max_len){
				max_len=pos_stack[i+1]-pos_stack[i]-1;
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
