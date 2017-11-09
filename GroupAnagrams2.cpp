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
        	//if(strmap[get_sort(strs[i])]){
        		strmap[get_sort(strs[i])].push_back(strs[i]);
			//}else{
			//	vector<string> one;
			//	one.push_back(strs[i]);
			//	strmap[get_sort(strs[i])]=one; 
			//}
		}
		
		map<string,vector<string> >::iterator it;
		for(it=strmap.begin();it!=strmap.end();it++){
			result.push_back(it->second);
		}
		
		return result;
        
    }
    
    string get_sort(string s){
    	string_qsort(s,0,s.length()-1);
    	return s;
	}
    
    void string_qsort(string& s,int l,int r){
    	if(l<r){
    		int i=l,j=r;
    		char v=s[l];
    		while(i<j){
    			while(i<j&&s[j]>=v) j--;
    			s[i]=s[j];
    			while(i<j&&s[i]<=v) i++;
    			s[j]=s[i];
			}
			s[i]=v;
			string_qsort(s,l,i);
			string_qsort(s,i+1,r);
		}
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
