#include <iostream>
using namespace std;
#define Type int
/* �鲢�������˼��:
	1)��n����¼�Ĵ��������п�Ϊn�����ȶ�Ϊ1�������ӱ����
	2)���������ڵ��ӱ�鲢Ϊһ�������ӱ�
	3)�ظ��������裬ֱ���鲢Ϊһ������Ϊn�������
*/

//���������鲢��һ�������,��ʵ����[һ�ι鲢]
void Merge(Type c[],Type d[],int low,int mid,int high){
	int i=low,j=mid+1,k=low;  //iΪ��1���±�,jΪ��2���±�,kΪ��������d�±�
	while(i<=mid && j<=high){   //������c�����μ�¼����鲢������d��
		if(c[i]<=c[j])   //ÿ�ν������еĽ�С�߹鲢������d
			d[k++]=c[i++];
		else
			d[k++]=c[j++];
	}
	if(i>mid)  //����2��ʣ�ಿ�ֹ鲢������d��
		for(int t=j;t<=high;t++)
			d[k++]=c[t];
	else   //����1��ʣ�ಿ�ֹ鲢������d��
		for(int t=i;t<=mid;t++)
			d[k++]=c[t];
}

/* ʵ��[һ�˹鲢]
	��ĳ�˹鲢��,����ӱ���s,�ӱ�鲢ʱ,���ܳ��������������:
		1)���ֺ��ӱ�ĸ���������;
		2)���һ���ӱ�ĳ���С��s.
	-ʣ��С�ڵ���s��Ԫ��(ʣ�µ���s��Ԫ�ؼ������1) ):ֱ�Ӽӵ���������
	-ʣ�´���s��С��2*s��Ԫ��:��ʣ�µ�1-s��Ԫ����Ϊ��1��,ʣ�ಿ��Ϊ��2��,����Merge()
*/
void MergePass(Type x[],Type y[],int s,int n){
	int i=0;
	while(i<=n-2*s){
		Merge(x,y,i,i+s-1,i+2*s-1);
		i=i+2*s;
	}
	if(i+s<n)  //ʣ�´���s��С��2*s��Ԫ��
		Merge(x,y,i,i+s-1,n-1);
	else   //ʣ��С�ڵ���s��Ԫ��
		for(int j=i;j<=n-1;j++)
			y[j]=x[j];
}

//ʵ�ּ�������
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
