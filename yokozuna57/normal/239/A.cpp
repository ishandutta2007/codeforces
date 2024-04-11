#include<iostream>
using namespace std;
int main(){
int x,y,k,n,ans[10000000],a=0;
cin>>y>>k>>n;
for(int i=k;i<=n;i+=k){
x=i-y;
if(x>0){ans[a]=x; a++;}}
if(a==0)cout<<"-1"<<endl;
if(a!=0){
cout<<ans[0];
for(int i=1;i<a;i++)cout<<" "<<ans[i];
cout<<endl;}}