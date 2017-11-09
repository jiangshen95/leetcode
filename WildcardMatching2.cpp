#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        return isMatch(s,p,0,0);
        
    }
    
    bool isMatch(string s, string p, int s_begin, int p_begin){
    	
    	if(p_begin==p.length()) return s_begin==s.length();
    	
    	if(p[p_begin]=='*'){
    		for(int i=s_begin;i<=s.length();i++){
    			if(isMatch(s,p,i,p_begin+1)){
    				return true;
				}
			}
			return false;
		}
		else if(p[p_begin]=='?'){
			return isMatch(s,p,s_begin+1,p_begin+1);
		}
		else{
			if(p[p_begin]==s[s_begin]){
				return isMatch(s,p,s_begin+1,p_begin+1);
			}else{
				return false;
			}
		}
    	
	}
};

int main(){
	string s,p;
	cin>>s;
	cin>>p;
	
	Solution *solution=new Solution();
	cout<<solution->isMatch(s,p);
	
	return 0;
}
