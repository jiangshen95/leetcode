#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        
        vector<vector<int> > result;
        
        permuteUnique(result,nums,0);
        
        return result;
        
    }
    
    void permuteUnique(vector<vector<int> >& result,vector<int>& nums,int l){
    	if(l==nums.size()-1){
    		result.push_back(nums);
		}
		else{
			for(int i=l;i<nums.size();i++){
				if(i!=l&&nums[l]==nums[i]){
					continue;
				}
				bool skip=false;
				for(int j=l;j<i;j++){
					if(nums[i]==nums[j]){
						skip=true;
						break;
					}
				}
				if(skip) continue;
				swap(nums[l],nums[i]);
				permuteUnique(result,nums,l+1);
				swap(nums[l],nums[i]);
			}
		}
	}
	
	void swap(int& x,int& y){
		int v=x;
		x=y;
		y=v;
	}
};

int main(){
	
	int n;
	cin>>n;
	
	vector<int> nums;
	for(int i=0;i<n;i++){
		int num;
		cin>>num;
		nums.push_back(num);
	}
	
	Solution *solution=new Solution();
	vector<vector<int> > result=solution->permuteUnique(nums);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
	
}
