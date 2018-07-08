#include <iostream>
using namespace std;
void MatrixChain(int *p,int n,int m[][7],int s[][7]){
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
		for(int i=1;i<=n-l+1;i++){
			int j=i+l-1;
			m[i][j]=m[i+1][j]+p[i-1]*p[i]*p[j];
			s[i][j]=i;
			for(int k=i+1;k<j;k++){
				int t=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
				if(t<m[i][j]){
					m[i][j]=t;
					s[i][j]=k;
				}
			}
		}
}
void Traceback(int s[][7],int i,int j){
	if(i==j)
		cout<<"A"<<i;
	else{
		cout<<"(";
		Traceback(s,i,s[i][j]);
		Traceback(s,s[i][j]+1,j);
		cout<<")";
	}
}
int main(){
	int n=6;
	int p[7]={30,35,15,5,10,20,25};
	int m[7][7],s[7][7];
	MatrixChain(p,n,m,s);
	Traceback(s,1,n);
	return 0;
}