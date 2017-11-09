#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        
        vector<vector<int> > result;
        
        permute(nums,result,0);
        
        return result;
        
    }
    
    void permute(vector<int>& nums,vector<vector<int> >& result,int l){
    	
    	if(l==nums.size()-1){
    		result.push_back(nums);
		}
		else{
			for(int i=l;i<nums.size();i++){
				swap(nums[l],nums[i]);
				permute(nums,result,l+1);
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
	vector<vector<int> > result=solution->permute(nums);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
	
}
