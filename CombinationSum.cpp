#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int> > result;
        vector<int> one;
        combinationSum(result,one,candidates,target,0);
        
        return result;
        
    }
    
    void combinationSum(vector<vector<int> >& result,vector<int>& one,vector<int>& candidates,int target,int l){
    	for(int i=l;i<candidates.size();i++){
    		
    		if(target>candidates.at(i)){
    			one.push_back(candidates[i]);
    			combinationSum(result,one,candidates,target-candidates[i],i);
			}
			else if(target==candidates.at(i)){
				one.push_back(candidates[i]);
				result.push_back(one);
				one.pop_back();
			}
    		
		}
		one.pop_back();
	}
    
    /*bool combinationSum(vector<vector<int> >& result,vector<int>& one,vector<int>& candidates,int target,int l){
    	
    	for(int i=l;i<candidates.size();i++){
    		if(target>candidates[i]){
    			one.push_back(candidates[i]);
    			cout<<"push_back: "<<candidates[i]<<endl;
    			cout<<"i: "<<i<<"-----"<<"l: "<<l<<endl;
    			cout<<"target: "<<target<<endl;
    			system("pause");
    			combinationSum(result,one,candidates,target-candidates[i],i);
    			//if(combinationSum(result,one,candidates,target-candidates[i],i)){
    				
    				//one.clear();
    				//one.pop_back();
    				//one.pop_back();
    				
    				//return true;
				//}
				//else{
				//	cout<<"pop_back: "<<one.back()<<endl;
				//	one.pop_back();
				//}
			}
			else if(target<candidates[i]){
				cout<<"---back---"<<endl;
				cout<<"i: "<<i<<"-----"<<"l: "<<l<<endl;
    			cout<<"target: "<<target<<endl;
    			system("pause");
				//return false;
			}
			else{
				one.push_back(candidates[i]);
				cout<<"-----same------"<<endl;
				cout<<"push_back: "<<candidates[i]<<endl;
    			cout<<"i: "<<i<<"-----"<<"l: "<<l<<endl;
    			cout<<"target: "<<target<<endl;
    			system("pause");
				result.push_back(one);
				//return true;
				one.pop_back();
			}
		}
		
		one.clear();
		
		return false;
    	
	}*/
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
