#include<iostream>
#include<vector>
#include<string.h>
#include<map>

using namespace std;

class Solution{
	public:
		vector<int> findSubstring(string s,vector<string>& words) {
			int n=s.length();
			int wn=words.size();
			int wl=words[0].length();
			
			vector<int> result;
			
			map<string,int> dict;
			for(int i=0;i<wn;i++) dict[words[i]]++;
			
			for(int i=0;i<wl;i++){
				map<string,int> sdict;
				int count=0;
				for(int j=i;j<=n-wl;j+=wl){
					string str=s.substr(j,wl);
					sdict[str]++;
					if(sdict[str]<=dict[str]){
						cout<<"str: "<<str<<endl;
						cout<<"count: "<<count<<endl;
						cout<<"j: "<<j<<endl;
						count++;
						
						if(count==wn){
							result.push_back(j-wn*wl+wl);
						}
					}else{
						cout<<"str: "<<str<<endl;
						cout<<"count: "<<count<<endl;
						
						
						if(dict[str]>0){
							j-=count*wl;
						}
						sdict.clear();
						count=0;
					}
				}
				
				//if(count==wn){
				//	result.push_back(n-wn*wl);
				//}
				
			}
			
			return result;
		}
};

int main(){
	string s;
	cin>>s;
	
	int n;
	cin>>n;
	vector<string> words;
	for(int i=0;i<n;i++){
		string word;
		cin>>word;
		words.push_back(word);
	}
	
	Solution *solution=new Solution();
	vector<int> result=solution->findSubstring(s,words);
	for(int i=0;i<result.size();i++){
		cout<<result.at(i)<<", ";
	}
	
	return 0;
}
