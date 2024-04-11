#include<iostream>
using namespace std;

int z(int x){
if(x<0)x=-x;
return x;
}

int main(){
long int n,a,b,ans=0;
a=0;
cin>>n;
for(int i=0;i<n;i++){
cin>>b;
ans+=z(b-a)+1;
a=b;
}
cout<<ans+n-1<<endl;
}