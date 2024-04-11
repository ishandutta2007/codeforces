#include<iostream>
using namespace std;

int main(){
int x,y,a,b,ans=0;
cin>>x>>y>>a>>b;
for(int i=a;i<x+1;i++){
for(int j=b;j<y+1;j++){
if(i>j)ans++;}}
cout<<ans<<endl;
for(int i=a;i<x+1;i++){
for(int j=b;j<y+1;j++){
if(i>j)cout<<i<<" "<<j<<endl;}}}