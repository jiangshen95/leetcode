#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums) {
        
        vector<vector<int> > result;
        
        vector_qsort(nums,0,nums.size()-1);
        
        result.push_back(nums);
        
        int i,j;
        while(1){
        	
        	for(i=nums.size()-1;i>0;i--){
        		if(nums[i-1]<nums[i]){
        			break;
				}
			}
			
			if(i==0) break;
			
			for(j=nums.size()-1;j>i-1;j--){
				if(nums[j]>nums[i-1]){
					break;
				}
			}
			
			swap(nums[i-1],nums[j]);
			vector_reserve(nums,i,nums.size()-1);
			
			result.push_back(nums);
        	
		}
        
		
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
	
	void swap(int& x,int& y){
		int v=x;
		x=y;
		y=v;
	}
	
	void vector_reserve(vector<int>& nums,int l,int r){
    	while(l<r){
    		int v=nums[l];
    		nums[l]=nums[r];
    		nums[r]=v;
    		l++;
    		r--;
		}
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
