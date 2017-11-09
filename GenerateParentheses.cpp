#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        return getParenthesis(n);
    }
    
    vector<string> getParenthesis(int n){
    	if(n==0){
    		vector<string> par;
    		par.push_back("");
    		return par;
		}
    	if(n==1){
    		vector<string> par;
    		par.push_back("()");
    		return par;
		}
		else{
			
			vector<string> par;
			
			for(int i=0;i<n;i++){
				vector<string> first=getParenthesis(i);
				vector<string> second=getParenthesis(n-i-1);
				for(int f=0;f<first.size();f++){
					for(int s=0;s<second.size();s++){
						par.push_back("("+first.at(f)+")"+second.at(s));
					}
				}
			}
			
			/*vector<string> par;
			
			for(int i=n-1;i> 0;i--){
				
				string l="",r="";
				for(int k=0;k<i;k++){
					l.append("(");
					r.append(")");
				}
				
				for(int x=n-i;x>0;x--){
					
					vector<string> second=getParenthesis(x);
					for(int j=0;j<second.size();j++){
						par.push_back(l+second.at(j)+r);
					}
					cout<<"par: "<<par.back()<<endl;
					vector<string> temp=getParenthesis(n-x-i);
					for(int j=0;j<par.size();j++){
						for(int k=0;k<temp.size();k++){
							cout<<"------"<<temp.size()<<endl;
							par[j].append(temp[k]);
						}
					}
				
				
			}}*/
			
			/*vector<string> temp=getParenthesis(n-1);
			vector<string> par;
			
			for(int i=0;i<temp.size();i++){
				par.push_back("("+temp.at(i)+")");
			}
			
			for(int i=n-1;i>=1;i--){
				vector<string> first=getParenthesis(i);
				vector<string> second=getParenthesis(n-i);
				
				for(int f=0;f<first.size();f++){
					for(int s=0;s<second.size();s++){
						if(!(f==first.size()-1&&s==second.size()-1)){
							par.push_back(first.at(f)+second.at(s));
						}
						
					}
				}	
			}
			string str="";
			for(int i=0;i<n;i++){
				str.append("()");
			}
			par.push_back(str);*/
			return par;
			
		}
	}
};

int main(){
	int n;
	cin>>n;
	Solution *solution=new Solution();
	vector<string> res=solution->generateParenthesis(n);
	for(int i=0;i<res.size();i++){
		cout<<res.at(i)<<endl;
	}
	
	return 0;
}


