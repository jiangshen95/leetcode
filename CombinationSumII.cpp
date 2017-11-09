#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
        
        vector<vector<int> > result;
        vector<int> one;
        
        vector_qsort(candidates,0,candidates.size()-1);
        
        combinationSum2(result,one,candidates,target,0);
        
        return result;
        
    }
    
    void vector_qsort(vector<int>& nums,int l,int r){
    	if(l<r){
    		int i=l,j=r;
    		int v=nums[l];
    		while(i<j){
    			while(i<j&&nums[j]>=v) j--;
    			nums[i]=nums[j];
    			while(i<j&&nums[i]<=v) i++;
    			nums[j]=nums[i];
			}
			nums[i]=v;
			vector_qsort(nums,l,i);
			vector_qsort(nums,i+1,r);
		}
	}
    
    void combinationSum2(vector<vector<int> >& result, vector<int>& one, vector<int>& candidates, int target, int l){
    	for(int i=l;i<candidates.size();i++){
    		if(i>l&&candidates[i]==candidates[i-1]){
    			continue;
			}

    		if(target>candidates[i]){
    			one.push_back(candidates[i]);
    			combinationSum2(result,one,candidates,target-candidates[i],i+1);
			}
			else if(target==candidates[i]){
				
				one.push_back(candidates[i]);
				result.push_back(one);
				one.pop_back();
				
				break;
				
			}
			else{
				break;
			}
		}
		if(!one.empty()){
			one.pop_back();
		}
			
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
	vector<vector<int> > result=solution->combinationSum2(candidates,target);
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
}
