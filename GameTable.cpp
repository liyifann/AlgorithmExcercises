#include <iostream>
#include <iomanip>
using namespace std;
void GameTable(int **a,int x,int y,int n){
	/* ��ģΪ2ʱ���������µݹ�ͨʽ
	if(n==2){
		a[x+1][y+1]=a[x][y];
		a[x][y+1]=a[x+1][y];
		return;
	}
	*/
	if(n==1)
		return;
	n/=2;   //��С��ģ
	GameTable(a,x,y,n);   //�����ӱ�
	GameTable(a,x+n,y,n);   //�����ӱ�
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			a[x+n+i][y+n+j]=a[x+i][y+j];   //�������ӱ��ֵ���������ӱ�
			a[x+i][y+n+j]=a[x+n+i][y+j];   //�������ӱ��ֵ���������ӱ�
		}
}
int main(){
	int n,i,j;   //n֧����(n����Ϊ2���ݴη�)
	cin>>n;
	int **a=new int *[n];   //��̬��ά����(��)
	for(i=0;i<n;i++){
		a[i]=new int[n];   //��̬��ά����(��)
		a[0][i]=i+1;   //����һ�и�ֵ
		a[i][0]=i+1;   //����һ�и�ֵ
	}
	GameTable(a,0,0,n);
	for(i=0;i<n;i++){
		for(j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
	return 0;
}

	
