#include <iostream>
using namespace std;
const int maxn=100;
int a[maxn][maxn],b[maxn];
bool odd(int n){
	return n&1;
}
void copy(int n){
	int m=n/2;
	for(int i=1;i<=m;i++)
		for(int j=1;j<=m;j++){
			a[i][j+m]=a[i][j]+m;
			a[i+m][j]=a[i][j+m];
			a[i+m][j+m]=a[i][j];
		}
}
void copyodd(int n){
	int m=n/2;
	for(int i=1;i<=m;i++){
		b[i]=m+i;
		b[m+i]=b[i];
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=m+1;j++){
			if(a[i][j]>m){
				a[i][j]=b[i];
				a[m+i][j]=(b[i]+m)%n;
			}
			else
				a[m+i][j]=a[i][j]+m;
		}
		for(int j=2;j<=m;j++){
			a[i][m+j]=b[i+j-1];
			a[b[i+j-1]][m+j]=i;
		}
	}
}
void makecopy(int n){
	if(n/2>1 && odd(n/2))
		copyodd(n);
	else
		copy(n);
}
void tournament(int n){
	if(n==1){
		a[1][1]=1;
		return;
	}
	if(odd(n)){
		tournament(n+1);
		return;
	}
	tournament(n/2);
	makecopy(n);
}
int main(){
	int n,i,j;
	cin>>n;
	tournament(n);
	if(odd(n)){
		cout<<"/* 0��ʾ�ֿ� */"<<endl;
		for(i=1;i<=n;i++){
			for(j=1;j<=n+1;j++)
				if(a[i][j]==n+1)
					cout<<"0 ";
				else
					cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}
	else{
		for(i=1;i<=n;i++){
			for(j=1;j<=n;j++)
				cout<<a[i][j]<<" ";
			cout<<endl;
		}
	}

	return 0;
}
