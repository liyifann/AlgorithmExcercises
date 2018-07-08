#include <iostream>
using namespace std;
#define MAX 101
int D[MAX][MAX];
int n;
int main(){
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
		for(j=1;j<=i;j++)
			cin>>D[i][j];
	for(i=n-1;i>=1;i--)
		for(j=1;j<=i;j++)
			D[i][j]+=(D[i+1][j]>D[i+1][j+1]?D[i+1][j]:D[i+1][j+1]);
	cout<<D[1][1]<<endl;
	return 0;
}
