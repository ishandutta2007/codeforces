#include<iostream>
using namespace std;

int main(){
int n,k,m,b[31][31],a[31];
bool c[902];
for(int i=0;i<902;i++)c[i]=true;
cin>>n>>k;
for(int i=0;i<k;i++){
cin>>a[i];
b[i][0]=a[i];
c[a[i]]=false;}
m=1;
for(int i=1;i<n;i++){
for(int j=0;j<k;j++){
while(!c[m])m++;
b[j][i]=m;
c[m]=false;}}
for(int i=0;i<k;i++){
cout<<b[i][0];
for(int j=1;j<n;j++)cout<<" "<<b[i][j];
cout<<endl;}}