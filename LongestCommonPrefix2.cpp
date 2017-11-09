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
        return longestCommonPrefix(strs,0,strs.size()-1);
    }
    
    string longestCommonPrefix(vector<string>& strs,int l,int r){
    	if(l==r){
    		return strs.at(l);
		}
		else{
			int mid=(l+r)/2;
			string lcpLeft=longestCommonPrefix(strs,l,mid);
			string lcpRight=longestCommonPrefix(strs,mid+1,r);
			return commonPrefix(lcpLeft,lcpRight);
		}
	}
    
    string commonPrefix(string left,string right){
    	int i=0;
    	for(;i<left.length()&&i<right.length();i++){
    		if(left[i]!=right[i]){
    			break;
			}
		}
		return left.substr(0,i);
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
