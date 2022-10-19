#include<iostream>
using namespace std;

int main(){
int n,d,l,x,y;
int a,s,s1;;
int ans[101];
cin>>n>>d>>l;
a=n%2;
x=(n-a)/2;
y=n-x;
if(d<y-x*l||y*l-x<d){
cout<<-1;
}
if(y-x*l<=d&&d<=y*l-x){
if(d<=0){
for(int i=0;i<y;i++){
ans[2*i]=1;
}
s=y-d;
s%=x;
s1=(y-d-s)/x;
for(int i=0;i<x;i++){
if(i<s){ans[2*i+1]=s1+1;}
if(i>=s){ans[2*i+1]=s1;}
}
}
if(d>0){
for(int i=0;i<x;i++){
ans[2*i+1]=1;
}
s=x+d;
s%=y;
s1=(x+d-s)/y;
for(int i=0;i<y;i++){
if(i<s){ans[2*i]=s1+1;}
if(i>=s){ans[2*i]=s1;}
}
}for(int i=0;i<n-1;i++){
cout<<ans[i]<<" ";}
cout<<ans[n-1]<<endl;
}
}