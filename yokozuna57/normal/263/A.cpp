#include<iostream>
using namespace std;

int b(int x){
if(x<0)x=-x;
return x;
}

int main(){
int a[6][6];
int ans;
for(int i=0;i<5;i++){
for(int j=0;j<5;j++){
cin>>a[i][j];
if(a[i][j]==1)ans=b(i-2)+b(j-2);
}
}
cout<<ans;
}