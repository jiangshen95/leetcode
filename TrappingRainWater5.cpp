#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()<3){
        	return 0;
		}
		
		int sum=0;
        
        int left=0,right=height.size()-1;
        int left_max=0;
        int right_max=0;
        while(left<right){
        	
        	if(height[left]<height[right]){
        		
        		if(height[left]>=left_max){
        			left_max=height[left];
				}else{
					sum+=left_max-height[left];
				}
				
				left++;
        		
			}else{
				if(height[right]>=right_max){
					right_max=height[right];
				}else{
					sum+=right_max-height[right];
				}
				
				right--;
			}
        	
//        	if(height[left]>left_max) left_max=height[left];
//        	if(height[right]>right_max) right_max=height[right];
//        	
//        	if(left_max>height[left]){
//        		sum+=left_max-height[left];
//			}
//			if(right_max>height[right]){
//				sum+=right_max-height[right];
//			}
//			
//			if(height[left]<height[right]) left++;
//			else right--;
		}
        
        
		
		return sum;
        
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
	cout<<solution->trap(nums);
	
	return 0;
}
