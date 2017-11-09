#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	
    	int l=0,r=nums.size()-1;
    	
    	while(l<=r){
    		int mid=(l+r)/2;
    		if(nums[mid]==target) return mid;
    		if(nums[mid]>=nums[l]){
    			if(nums[mid]>=target&&nums[l]<=target){
    				r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			else{
				if(nums[mid]<=target&&nums[r]>=target){
					l=mid+1;
				}else{
					r=mid-1;
				}
			}
		}
		
		return -1;
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
	
	int target;
	cin>>target;
	
	Solution *solution=new Solution();
	cout<<solution->search(nums,target);
}
