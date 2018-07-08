#include <iostream>
#include <iomanip>
using namespace std;
void GameTable(int **a,int x,int y,int n){
	/* 规模为2时可以用以下递归通式
	if(n==2){
		a[x+1][y+1]=a[x][y];
		a[x][y+1]=a[x+1][y];
		return;
	}
	*/
	if(n==1)
		return;
	n/=2;   //缩小规模
	GameTable(a,x,y,n);   //左上子表
	GameTable(a,x+n,y,n);   //左下子表
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			a[x+n+i][y+n+j]=a[x+i][y+j];   //将左上子表的值赋给右下子表
			a[x+i][y+n+j]=a[x+n+i][y+j];   //将左下子表的值赋给右上子表
		}
}
int main(){
	int n,i,j;   //n支队伍(n必须为2的幂次方)
	cin>>n;
	int **a=new int *[n];   //动态二维数组(行)
	for(i=0;i<n;i++){
		a[i]=new int[n];   //动态二维数组(列)
		a[0][i]=i+1;   //给第一列赋值
		a[i][0]=i+1;   //给第一行赋值
	}
	GameTable(a,0,0,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
	return 0;
}

	
