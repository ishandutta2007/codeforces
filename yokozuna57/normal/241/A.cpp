#include<iostream>
using namespace std;

int main(){
int m,k,d[2000],s[2000],n=0,big=0,ans=0;
cin>>m>>k;
for(int i=0;i<m;i++)cin>>d[i];
for(int i=0;i<m;i++)cin>>s[i];
for(int i=0;i<m;i++){
n+=s[i];
if(s[i]>big)big=s[i];
while(n<d[i]){n+=big; ans+=k;}
n-=d[i];
ans+=d[i];}
cout<<ans<<endl;}