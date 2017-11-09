#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if(nums.size()<2){
        	return nums.size();
		}
		
		int curr=0;
		int count=0;
		
		for(int i=1;i<nums.size();i++){
			if(nums.at(i)==nums.at(curr)){
				count++;
			}else{
				curr++;
				nums[curr]=nums[i];
			}
		}
		for(int i=0;i<count;i++){
			nums.pop_back();
		}
		
		for(int i=0;i<nums.size();i++){
			cout<<nums.at(i)<<endl;
		}
		
		/*int i=1;
		while(i<nums.size()){
			int n=i;
			int count=0;
			while(n<nums.size()&&nums.at(n)==nums.at(n-1)){
				n++;
				count++;
			}
			
			cout<<"n: "<<n<<"-----"<<"count: "<<count<<endl;
			if(count>0){
				for(int j=i;j+count<nums.size();j++){
					nums[j]=nums[j+count];
				}
			
				for(int j=0;j<count;j++){
					nums.pop_back();
				}
			}
			
			i++;
		}*/
		
		return nums.size();
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
	cout<<solution->removeDuplicates(nums);
}
