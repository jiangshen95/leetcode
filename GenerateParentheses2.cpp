#include<iostream>
#include<string.h>
#include<vector>

using namespace std;

class Solution{
	public:
		vector<string> generateParenthesis(int n){
			vector<string> res;
			getParenthesis(res,"",0,0,n);
			return res;
		}
		
		void getParenthesis(vector<string>& res,string str,int left,int right,int n){
			if(str.length()==n*2){
				res.push_back(str);
			}
			else{
				if(left<n){
					getParenthesis(res,str+"(",left+1,right,n);
				}
				if(right<left){
					getParenthesis(res,str+")",left,right+1,n);
				}
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

