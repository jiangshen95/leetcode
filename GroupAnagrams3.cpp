#include<iostream>
#include<string.h>
#include<vector>
#include<map>

using namespace std;

class Solution {
public:
    vector<vector<string> > groupAnagrams(vector<string>& strs) {
        
        vector<vector<string> > result;
        
        map<string,vector<string> > strmap;
        
        for(int i=0;i<strs.size();i++){
        	
        	string where="00000000000000000000000000";
        	
        	for(int j=0;j<strs[i].length();j++){
        		where[strs[i][j]-'a']++;
			}
        	
        	strmap[where].push_back(strs[i]);

		}
		
		map<string,vector<string> >::iterator it;
		for(it=strmap.begin();it!=strmap.end();it++){
			result.push_back(it->second);
		}
		
		return result;
        
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
