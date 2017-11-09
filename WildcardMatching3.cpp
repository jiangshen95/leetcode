#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        int i=0;
        int j=0;
        int star=-1;
        int match;
        while(i<s.length()){
        	
        	if(j<p.length()&&(s[i]==p[j]||p[j]=='?')){
        		i++;
        		j++;
        		continue;
			}
			
			else if(j<p.length()&&p[j]=='*'){
				star=j;
				j++;
				
				match=i;
			}
			
			else if(star>=0){
				i=++match;
				j=star+1;
			}
			else{
				return false;
			}
        	
		}
		
		while(j<p.length()&&p[j]=='*') j++;
		return j==p.length();
        
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
