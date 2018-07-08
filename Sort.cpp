#include <iostream>
using namespace std;
int main(){
    int a[]={5,3,23,0,-1};
    int i,j;
    for(i=0;i<5-1;i++)
        for(j=i+1;j<5;j++){
            if(a[i]>a[j]){
                int temp=a[i];
                a[i]=a[j];
                a[j]=temp;
            }
        }
/*    for(i=0;i<5-1;i++)
        for(j=0;j<5-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }*/
    for(i=0;i<5;i++)
        cout<<a[i]<<" ";
    cout<<endl;
    return 0;
}