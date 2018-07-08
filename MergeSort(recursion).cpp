#include <iostream>
using namespace std;
#define Type int
void Merge(Type a[],int left,int mid,int right,Type temp[]){
	int i=left,j=mid+1,t=0;  //i是左半段下标,j是右半段下标,t是临时数组temp下标
	while(i<=mid && j<=right){
		if(a[i]<=a[j])
			temp[t++]=a[i++];
		else
			temp[t++]=a[j++];
	}
	while(i<=mid)  //将左边剩余元素填充进temp中
		temp[t++]=a[i++];
	while(j<=right)  //将右边剩余元素填充进temp中
		temp[t++]=a[j++];
	t=0;
	//将temp中元素拷贝到原数组中
	while(left<=right)
		a[left++]=temp[t++];
}
void MergeSort(Type a[],int left,int right,Type temp[]){
	if(left<right){
		int mid=(left+right)/2;
		MergeSort(a,left,mid,temp);  //左边归并排序
		MergeSort(a,mid+1,right,temp);  //右边归并排序
		Merge(a,left,mid,right,temp);  //左右两个有序子序列合并
	}
}
int main(){
	int n,i;
	cin>>n;
	Type *a=new Type[n];
	Type *temp=new Type[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	MergeSort(a,0,n-1,temp);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
