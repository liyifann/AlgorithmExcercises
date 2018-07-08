#include <iostream>
using namespace std;
#define Type int
/* 归并排序基本思想:
	1)将n个记录的待排序序列看为n个长度都为1的有序子表组成
	2)将两两相邻的子表归并为一个有序子表
	3)重复上述步骤，直至归并为一个长度为n的有序表
*/

//两个有序表归并成一个有序表,即实现了[一次归并]
void Merge(Type c[],Type d[],int low,int mid,int high){
	int i=low,j=mid+1,k=low;  //i为第1段下标,j为第2段下标,k为有序数组d下标
	while(i<=mid && j<=high){   //将数组c中两段记录有序归并到数组d中
		if(c[i]<=c[j])   //每次将二者中的较小者归并到数组d
			d[k++]=c[i++];
		else
			d[k++]=c[j++];
	}
	if(i>mid)  //将第2段剩余部分归并到数组d中
		for(int t=j;t<=high;t++)
			d[k++]=c[t];
	else   //将第1段剩余部分归并到数组d中
		for(int t=i;t<=mid;t++)
			d[k++]=c[t];
}

/* 实现[一趟归并]
	在某趟归并中,设各子表长度s,子表归并时,可能出现如下特殊情况:
		1)划分后子表的个数是奇数;
		2)最后一个子表的长度小于s.
	-剩下小于等于s个元素(剩下等于s个元素即是情况1) ):直接加到有序表后面
	-剩下大于s个小于2*s个元素:将剩下的1-s个元素作为第1段,剩余部分为第2段,进行Merge()
*/
void MergePass(Type x[],Type y[],int s,int n){
	int i=0;
	while(i<=n-2*s){
		Merge(x,y,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i+s<n)  //剩下大于s个小于2*s个元素
		Merge(x,y,i,i+s-1,n-1);
	else   //剩下小于等于s个元素
		for(int j=i;j<=n-1;j++)
			y[j]=x[j];
}

//实现几趟排序
void MergeSort(Type a[],int n){
	Type *b=new Type[n];
	int s=1;
	while(s<n){
		MergePass(a,b,s,n);
		s+=s;
		MergePass(b,a,s,n);
		s+=s;
	}
}

int main(){
	int n,i;
	cin>>n;
	Type *a=new Type[n];
	for(i=0;i<n;i++)
		cin>>a[i];
	MergeSort(a,n);
	for(i=0;i<n;i++)
		cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}
