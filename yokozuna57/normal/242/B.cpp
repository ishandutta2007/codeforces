#include<iostream>
using namespace std;

int main(){
int n,a,b,c,d,ans=-1;
cin>>n;
for(int i=0;i<n;i++){
cin>>a>>b;
if(i==0){c=a;d=b;}
if(a<c){c=a; ans=-1;}
if(d<b){d=b; ans=-1;}
if(a==c&&b==d)ans=i+1;}
cout<<ans<<endl;}