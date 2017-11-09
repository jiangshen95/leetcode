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
        
        vector<int> stack;
        stack.push_back(0);
        
        for(int i=1;i<height.size();i++){
        	
        	cout<<"--------"<<endl;
        	for(int j=0;j<stack.size();j++){
        		cout<<stack.at(j)<<", ";
			}
			cout<<endl;
			cout<<"sum: "<<sum<<endl;
        	
        	if(stack.empty() || height[i]<height[stack.back()]){
        		stack.push_back(i);
			}
			else{
				
				int mid=stack.back();
				stack.pop_back();
				
				if(!stack.empty()){
					int lower=height[stack.back()]>height[i] ? height[i] : height[stack.back()];
					sum+= (lower-height[mid])*(i-stack.back()-1);
				}
				
				i--;
				
			}
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
