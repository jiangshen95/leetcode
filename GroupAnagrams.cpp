/*
  *Time Limite Exceeded
*/
#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        
        vector<vector<string> > result;
        
        vector<string> one;
        
        result.push_back(one);
        
        for(int i=0;i<strs.size();i++){
        	
        	int j;
        	for(j=0;j<result.size();j++){
        		
        		if(result[j].size()<=0||(result[j].size()>0&&(isSame(result[j].back(),strs[i])))){
        			result[j].push_back(strs[i]);
        			break;
				}
        		
			}
			if(j==result.size()){
				vector<string> new_line;
				new_line.push_back(strs[i]);
				result.push_back(new_line);
			}
        	
		}
		
		return result;
        
    }
    
    bool isSame(string s, string p){
    	if(s.length()!=p.length()){
    		return false;
		}
    	for(int i=0;i<s.length();i++){
    		int j;
    		for(j=0;j<p.length();j++){
    			if(s[i]==p[j]){
    				p[j]='A';
    				break;
				}
			}
			if(j==p.length()){
				return false;
			}
		}
		
		return true;
	}
};

int main(){
	int n;
	cin>>n;
	
	vector<string> strs;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		strs.push_back(str);
	}
	
	Solution *solution=new Solution();
	vector<vector<string> > result=solution->groupAnagrams(strs);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
}
