#include<iostream>
#include<string.h>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        
        bool matching[s.length()+1][p.length()+1];
        
        for(int i=0;i<=s.length();i++){
        	for(int j=0;j<=p.length();j++){
        		matching[i][j]=false;
			}
		}
        
        matching[s.length()][p.length()]=true;
        
        for(int i=s.length();i>=0;i--){
        	for(int j=p.length()-1;j>=0;j--){
        		bool fetch = i<s.length() && (s[i]==p[j]||p[j]=='?');
        		if(p[j]=='*'){
        			matching[i][j]=(i+1<=s.length()&&matching[i+1][j])||matching[i][j+1];
				}
        		//if(j+1<p.length() && p[j+1]=='*'){
        		//	matching[i][j] = (fetch&&(j+2<=p.length()&&matching[i+1][j+2]))||(fetch&&(matching[i+1][j+1]));
				//}
				else{
					matching[i][j]=fetch&&matching[i+1][j+1];
				}
        		
			}
		}
		
		return matching[0][0];
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
