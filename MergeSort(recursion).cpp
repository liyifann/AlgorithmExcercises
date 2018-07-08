#include <iostream>
using namespace std;
#define Type int
void Merge(Type a[],int left,int mid,int right,Type temp[]){
	int i=left,j=mid+1,t=0;  //i�������±�,j���Ұ���±�,t����ʱ����temp�±�
	while(i<=mid && j<=right){
		if(a[i]<=a[j])
			temp[t++]=a[i++];
		else
			temp[t++]=a[j++];
	}
	while(i<=mid)  //�����ʣ��Ԫ������temp��
		temp[t++]=a[i++];
	while(j<=right)  //���ұ�ʣ��Ԫ������temp��
		temp[t++]=a[j++];
	t=0;
	//��temp��Ԫ�ؿ�����ԭ������
	while(left<=right)
		a[left++]=temp[t++];
}
void MergeSort(Type a[],int left,int right,Type temp[]){
	if(left<right){
		int mid=(left+right)/2;
		MergeSort(a,left,mid,temp);  //��߹鲢����
		MergeSort(a,mid+1,right,temp);  //�ұ߹鲢����
		Merge(a,left,mid,right,temp);  //�����������������кϲ�
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
