#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int> > result;
        vector<int> one;
        
        vector<int> index;
        
        //for(int i=0;i<candidates.size();i++){
        	int sum=target;
        	for(int j=0;j<candidates.size();j++){
        		if(sum>candidates.at(j)){
        			one.push_back(candidates[j]);
        			index.push_back(j);
        			sum-=candidates.at(j);
        			j--;
        			
        			cout<<"----<-----"<<endl;
        			for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
				}
				else if(sum==candidates.at(j)){
					one.push_back(candidates[j]);
					result.push_back(one);
					
					cout<<"-----==-----"<<endl;
					for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
					
					one.pop_back();
					
					
					

						while(index.size()>0&&j==candidates.size()-1){
							sum+=one.back();
							one.pop_back();
							cout<<"j: "<<j<<endl;
							j=index.back();
							cout<<"j: "<<j<<endl;
							index.pop_back();
						}
					
				}
				else{
					
					cout<<"------>------"<<endl;
					for(int x=0;x<one.size();x++){
        				cout<<one.at(x)<<", ";
					}
					cout<<endl;
					cout<<"j: "<<j<<endl;
					
					while(j==candidates.size()-1&&index.size()>0){
						sum+=one.back();
						one.pop_back();
						j=index.back();
						cout<<"j: "<<j<<endl;
						index.pop_back();
					}
					
				}
			}
			//one.clear();
			
		//}
        
        return result;
        
    }
    
};

int main(){
	int n;
	cin>>n;
	
	vector<int> candidates;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		candidates.push_back(num);
	}
	
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	vector<vector<int> > result=solution->combinationSum(candidates,target);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
}
