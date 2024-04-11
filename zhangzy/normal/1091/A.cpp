#include<bits/stdc++.h>
using namespace std;

int r,b,y,ans;

int main(){
  cin>>y>>b>>r;
  ans=min(b,min(r-1,y+1));
  cout<<ans*3<<endl;
}