#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int l=0,r=nums.size()-1;
        
        while(l<r){
        	int mid=(l+r)/2;
        	if(nums[mid]>=target) r=mid;
        	else l=mid+1;
		}
		
		cout<<"l: "<<l<<endl;
		
		int result;
		if(l>=0&&l<nums.size()-1){
			result=l;
		}
		else if(l==nums.size()-1){
			if(nums[l]>=target) result=l;
			else result=l+1;
		}
		else{
			result=0;
		}
		
		return result;
        
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
	cout<<solution->searchInsert(nums,target);
	
	return 0;
}
