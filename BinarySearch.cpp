#include <iostream>
using namespace std;
#define Type int
//二分查找需要数列有序
int BinarySearch(Type a[],Type &x,int n){
	int left=0;
	int right=n-1;
	while(left<=right){
		int middle=(left+right)/2;
		if(x==a[middle])
			return middle;
		if(x>a[middle])
			left=middle+1;
		else
			right=middle-1;
	}
	return -1;
}
int main(){
	int n,i;
	Type t;
	cin>>n;
	Type *a=new Type[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	cin>>t;
	Type x=t;
	cout<<BinarySearch(a,x,n)<<endl;
	return 0;
}