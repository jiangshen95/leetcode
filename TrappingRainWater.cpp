#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        
        if(height.size()<3){
        	return 0;
		}
        
        int i=1;
        int sum=0;
        while(i<height.size()){
        	int l=i;
        	int r=i;
        	int next=i;
        	//while(r+1<height.size() && l-1>=0 && height[l-1]>=height[l] && height[r+1]>=height[r]){
        	//	r++;
        	//	l--;
			//}
			int heightest=0;
			for(int j=r;j<height.size();j++){
				if(height[j]>heightest){
					heightest=height[j];
					r=j;
				}
			}
			
			heightest=0;
			for(int j=l;j>=0;j--){
				if(height[j]>heightest){
					heightest=height[j];
					l=j;
				}
			}
			
			while(next+1<height.size()&&height[next+1]>=height[next]) next++;
			//while(r+1<height.size() && height[r+1]>=height[r]) r++;
			//while(l-1>=0 && height[l-1]>=height[l]) l--;
			
			cout<<"i: "<<i<<endl;
			cout<<"l: "<<l<<endl;
			cout<<"r: "<<r<<endl;
			
			if(r>i&&l<i){
				int lower=height[l]>height[r] ? height[r] : height[l];
				for(int j=l+1;j<r;j++){
					if(lower>height[j]){
						sum+=lower-height[j];
						height[j]=lower;
					}
				}
			}
			
			i=next+1;
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
