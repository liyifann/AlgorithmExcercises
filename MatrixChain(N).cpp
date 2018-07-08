#include <iostream>
using namespace std;
void MatrixChain(int *p,int n,int **m,int **s){
	for(int i=0;i<n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
		for(int i=0;i<n-l+1;i++){
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
void Traceback(int **s,int i,int j){
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
	int n,i;
	cin>>n;
	int *p=new int[n+1];
	for(i=0;i<=n;i++)
		cin>>p[i];
	int **m=new int *[n];
	for(i=0;i<n;i++)
		m[i]=new int[n];
	int **s=new int *[n];
	for(i=0;i<n;i++)
		s[i]=new int[n];
	MatrixChain(p,n,m,s);
	Traceback(s,0,n-1);
	cout<<endl;
	return 0;
}
