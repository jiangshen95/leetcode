#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        
        int l,r;
        int i;
        for(i=nums.size()-1;i>0;i--){
        	if(nums.at(i)>nums.at(i-1)){
        		break;
			}
		}
		if(i==0){
			vector_qsort(nums,0,nums.size()-1);
		}else{
			cout<<"i: "<<i<<endl;
			l=i-1;
			int j;
			for(j=nums.size()-1;j>l;j--){
				if(nums[j]>nums[l]){
					break;
				}
			}
			
			r=j;
			
			cout<<"j: "<<j<<endl;
			
			int v=nums[l];
			nums[l]=nums[r];
			nums[r]=v;
			
			vector_qsort(nums,l+1,nums.size()-1);
		}
		
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
	solution->nextPermutation(nums);
	
	for(int i=0;i<n;i++){
		cout<<nums.at(i)<<", ";
	}
}
