#include <iostream>
using namespace std;
#define N 200
int r[N][N];
int n;
void minFee(){
	int i,j,len,p;
	for(len=2;len<n;len++)
		for(i=0;i<n-1;i++){
			j=i+len;
			for(p=i+1;p<j;p++){
				int temp=r[i][p]+r[p][j];
				if(temp<r[i][j])
					r[i][j]=temp;
			}
		}
}
int main(){
	cin>>n;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=i+1;j<n;j++)
			cin>>r[i][j];
	minFee();
	cout<<r[0][n-1]<<endl;
	return 0;
}
