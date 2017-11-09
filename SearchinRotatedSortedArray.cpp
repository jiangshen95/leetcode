#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
    	
    	int n=nums.size();
    	int l=0,r=nums.size()-1;
    	while(l<r){
    		int mid=(l+r)/2;
    		if(nums.at(mid)>nums.at(l)) l=mid;
    		else r=mid;
		}
		
		int rot=l;
		cout<<"rot: "<<rot<<endl;
		if(rot+1<n&&nums[rot+1]>nums[rot]) rot+=1;
		
		
		
		cout<<"rot: "<<rot<<endl;
		
		l=rot+1;
		r=rot;
		
		int reall=l-rot-1;
		int realr=n-1;
		
		while(reall<=realr){
			int realmid=(reall+realr)/2;
			int mid=realmid+rot+1-n>=0 ? realmid+rot+1-n : realmid+rot+1;
			cout<<"realmid: "<<realmid<<endl;
			cout<<"mid: "<<mid<<endl;
			if(nums.at(mid)==target) return mid;
			else if(nums.at(mid)>target) realr=realmid-1;
			else reall=realmid+1;
		}
		
		/*l=0;
		r=nums.size()-1;
		
		while(l<=r){
			int mid=(l+r)/2;
			int realmid=(mid+rot)%(nums.size());//原位置x变到翻转之后的位置，rot-(n-x) 或者 rot+x 即 rot+x-n 或者 rot+x 可变换成 （rot+x)%n 
			cout<<"mid: "<<mid<<endl;
			cout<<"realmid: "<<realmid<<endl;
			if(nums.at(realmid)==target) return realmid;
			else if(nums.at(realmid)>target) r=mid-1;
			else l=mid+1;
		}*/
		
    	
        //for(int i=0;i<nums.size();i++){
        //	if(nums.at(i)==target){
        //		return i;
		//	}
		//}
		
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
