#include <iostream>
using namespace std;
#define Type char
int count=0;
void swap(Type *a,Type *b){
	Type temp=*a;
	*a=*b;
	*b=temp;
}
void perm(Type values[],int k,int m){
	int i=0;
	if(k==m){
		for(i=0;i<=m;i++)
			cout<<values[i]<<" ";
		cout<<endl;
		count++;
		return;
	}
	for(i=k;i<=m;i++){
		swap(&values[k],&values[i]);
		perm(values,k+1,m);
		swap(&values[i],&values[k]);
	}
	return;
}
int main(){
	int n,i;
	cin>>n;
	Type *values=new Type[n];
	for(i=0;i<n;i++)
		cin>>values[i];
	cout<<endl;
	perm(values,0,n-1);
	cout<<"count:"<<count<<endl;
	return 0;
}
