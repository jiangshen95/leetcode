#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    	if(strs.empty()){
    		return "";
		}
        string prefix=strs.at(0);
        for(int i=1;i<strs.size();i++){
        	cout<<prefix<<endl;
        	string nowstr=strs.at(i);
        	int j=0;
        	for(;j<prefix.length()&&j<nowstr.length();j++){
        		if(nowstr[j]!=prefix[j]){
        			break;
				}
			}
			prefix=prefix.substr(0,j);
			
		}
		
		return prefix;
    }
};

int main(){
	vector<string> strs;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		string str;
		cin>>str;
		strs.push_back(str);
	}
	
	Solution *solution=new Solution();
	cout<<solution->longestCommonPrefix(strs);
	
	return 0;
}
