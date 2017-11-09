#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        
        vector<vector<int> > wheres;
        vector<int> res;
        for(int i=0;i<words.size();i++){
        	vector<int> where=strStr(s,words[i]);
        	if(where.size()==0){
        		return res;
			}
			wheres.push_back(where);
		}
		
		/*int flag[words.size()][s.length()];
		for(int i=0;i<words.size();i++){
			for(int j=0;j<s.length();j++){
				flag[i][j]=0;
			}
		}
		for(int i=0;i<wheres.size();i++){
			for(int j=0;j<wheres[i].size();j++){
				for(int k=0;k<words[0].length();k++){
					flag[i][k+wheres[i][j]]=1;
				}
			}
		}*/
		
		int wl=words[0].length();
		int len=(words.size())*wl;
		
		for(int i=0;i<wheres.size();i++){
			for(int j=0;j<wheres[i].size();j++){
				int k;
				vector<int> haschecked;
				for(k=wheres[i][j];k<wheres[i][j]+len&&k<s.length();k+=wl){
					
					cout<<"k: "<<k<<endl;
					
					int p;
					for(p=0;p<wheres.size();p++){
						bool is_add=false;
						for(int q=0;q<wheres[p].size();q++){
							if(wheres[p][q]==k){
								cout<<"p: "<<p<<endl;
								int a;
								for(a=0;a<haschecked.size();a++){
									if(p==haschecked[a]){
										break;
									}
								}
								is_add=false;
								if(a==haschecked.size()){
									haschecked.push_back(p);
									is_add=true;
								}

								break;
							}
						}
						if(is_add){
							break;
						}
					}
					
					if(p==wheres.size()){
						cout<<"not ok"<<endl;
						break;
					}
					
					
					/*if(flag[k]==0){
						break;
					}else{
						int thewl=wl;
						cout<<"k: "<<k<<endl;
						while(k-thewl>wheres[i][j]){
							if(flag[k]==flag[k-thewl]){
								break;
							}
							thewl+=wl;
						}
						if(k-thewl>wheres[i][j]){
							break;
						}
					}*/
				}
				cout<<"k: "<<k<<"-------"<<"wheres: "<<wheres[i][j]+len<<endl;
				if(k==wheres[i][j]+len){
					int x;
					for(x=0;x<res.size();x++){
						if(res.at(x)==wheres[i][j]){
							break;
						}
					}
					if(x==res.size()){
						res.push_back(wheres[i][j]);
					}
				}
			}
		}
		
		return res;
        
    }
    
    vector<int> strStr(string haystack, string needle) {
    	int l1=haystack.length(),l2=needle.length();
		
		int next[l2+1];
		next[0]=next[1]=0;
		int i,k=0;
		
		for(i=2;i<=l2;i++){
			
			for(;k!=0&&needle[k]!=needle[i-1];k=next[k]);
			
			if(needle[k]==needle[i-1]){
				k++;
			}
			
			next[i]=k;
		}
		
		vector<int> result;
		i=0;
		k=0;
		while(i<l1){
			int j;
			for(j=k;j<l2;j++){
				if(i+j>=l1||needle[j]!=haystack[i+j]){
					break;
				}
			}
			if(j==l2){
				result.push_back(i);
			}
			k=next[j];
			i+=(j==0?1:j-k);
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
