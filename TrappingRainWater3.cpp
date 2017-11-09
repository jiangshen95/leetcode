#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()<3){
        	return 0;
		}
        
        vector<int> left_max(height.size()), right_max(height.size());
        
        left_max[0]=height[0];
        for(int i=1;i<height.size();i++){
        	if(height[i]>left_max[i-1]){
        		left_max[i]=height[i];
			}else{
				left_max[i]=left_max[i-1];
			}
		}
		
		right_max[height.size()-1]=height.back();
		for(int i=height.size()-2;i>=0;i--){
			if(height[i]>right_max[i+1]){
				right_max[i]=height[i];
			}else{
				right_max[i]=right_max[i+1];
			}
		}
		
		int sum=0;
		for(int i=0;i<height.size();i++){
			sum+= (left_max[i]>right_max[i] ? right_max[i] : left_max[i]) - height[i];
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
