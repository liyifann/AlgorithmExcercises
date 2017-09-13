#include <iostream>
using namespace std;
#define Type char
int count=0;
bool is_swap(Type values[],int i,int k){
	if(i==k)
		return true;
	for(int j=k;j<i;j++){	
		if(values[j]==values[i])
			return false;
	}
	return true;
}
void swap(Type *a,Type *b){
	Type temp=*a;
	*a=*b;
	*b=temp;
}
void perm(Type values[],int k,int m){
	int i;
	if(k==m){
		for(i=0;i<=m;i++)
			cout<<values[i];
		cout<<endl;
		count++;
		return;
	}
	for(i=k;i<=m;i++){
		if(is_swap(values,i,k)){
			swap(&values[k],&values[i]);
			perm(values,k+1,m);
			swap(&values[i],&values[k]);
		}
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
	cout<<count<<endl;
	return 0;
}
