#include<iostream>
using namespace std;

int main(){
int n,a,b;
bool c;
cin>>n;
for(int i=0;i<n;i++){
cin>>a;
c=false;
for(int j=3;j<361;j++){
b=180*(j-2);
if(b%j==0){
b/=j;
if(a==b){c=true; break;}
}
}
if(c)cout<<"YES"<<endl;
if(!c)cout<<"NO"<<endl;
}
}