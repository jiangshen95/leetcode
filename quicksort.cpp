#include<iostream>

using namespace std;

void quicksort(int a[],int l,int r){
	if(l<r){
		int v=a[l];
		int i=l,j=r;
		while(i<j){
			while(i<j&&a[j]>=v) j--;
			a[i]=a[j];
			while(i<j&&a[i]<=v) i++;
			a[j]=a[i];
		}
		a[i]=v;
		quicksort(a,l,i);
		quicksort(a,i+1,r);
	}
}

int main(){
	int n;
	cin>>n;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	quicksort(a,0,n-1);
	
	for(int i=0;i<n;i++){
		cout<<a[i]<<", ";
	}
	
	return 0;
}
