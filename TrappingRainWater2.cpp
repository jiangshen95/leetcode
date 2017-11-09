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
        
        for(int i=1;i<height.size()-1;i++){
        	int left_max=0,right_max=0;
        	for(int j=i;j>=0;j--){
        		if(left_max<height[j]){
        			left_max=height[j];
				}
			}
			for(int j=i;j<height.size();j++){
				if(height[j]>right_max){
					right_max=height[j];
				}
			}
			
			int lower = left_max>right_max ? right_max : left_max;
			
			sum+=lower-height[i];
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
