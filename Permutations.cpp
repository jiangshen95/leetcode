#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    vector<vector<int> > permute(vector<int>& nums) {
        
        vector<vector<int> > result;
        
        vector<int> one;
        
        result.push_back(one);
        
        for(int i=0;i<nums.size();i++){
        	vector<vector<int> > temp;
        	
        	for(int j=0;j<=i;j++){
        		for(int k=0;k<result.size();k++){
        			vector<int> one=result[k];
        			one.insert(one.begin()+j,nums[i]);
        			temp.push_back(one);
				}
			}
			
			result=temp;
		
		cout<<"----------"<<endl;	
		for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}system("pause");
        	
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
	
	Solution *solution=new Solution();
	vector<vector<int> > result=solution->permute(nums);
	
	for(int i=0;i<result.size();i++){
		for(int j=0;j<result[i].size();j++){
			cout<<result[i][j]<<", ";
		}
		cout<<endl;
	}
	
	return 0;
	
}
