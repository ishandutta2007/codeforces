#include<bits/stdc++.h>
using namespace std;
int a[8010];
int sum[8010];
int main(){
  int t;cin>>t;
  while(t--){
    int a,b,c;cin>>a>>b>>c;
    if(a==0&&c==0){
      for(int i=0,f=0;i<=b;i++,f=1-f)cout<<f;
      cout<<endl;
      continue;
    }
    if(a==0){
      for(int i=0;i<=c;i++)cout<<1;
      for(int i=1,f=0;i<=b;i++,f=1-f)cout<<f;
      cout<<endl;
      continue;
    }
    if(c==0){
      for(int i=0;i<=a;i++)cout<<0;
      for(int i=1,f=1;i<=b;i++,f=1-f)cout<<f;
      cout<<endl;
      continue;
    }
    for(int i=0;i<=a;i++)cout<<0;
    for(int i=0;i<=c;i++)cout<<1;
    for(int i=2,f=0;i<=b;i++,f=1-f)cout<<f;
    cout<<endl;
  }
}