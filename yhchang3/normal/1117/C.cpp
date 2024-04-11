#include<bits/stdc++.h>
using namespace std;
string s;
int x[100001],y[100001];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int xs,ys,xt,yt;
   cin>>xs>>ys>>xt>>yt;
   int n;
   cin>>n;
   cin>>s;
   for(int i=0;i<n;i++){
      if(s[i]=='U'){
         x[i+1]=x[i];
         y[i+1]=y[i]+1;
      }
      if(s[i]=='D'){
         x[i+1]=x[i];
         y[i+1]=y[i]-1;
      }
      if(s[i]=='R'){
         x[i+1]=x[i]+1;
         y[i+1]=y[i];
      }
      if(s[i]=='L'){
         x[i+1]=x[i]-1;
         y[i+1]=y[i];
      }
   }
   long long int l=0,r=1e18;
   while(l<r){
      long long int mid=(l+r)/2;
      if(abs(xs+mid/n*x[n]+x[int(mid%n)]-xt)+abs(ys+mid/n*y[n]+y[int(mid%n)]-yt)<=mid)
         r=mid;
      else
         l=mid+1;
   }
   if(abs(xs+l/n*x[n]+x[int(l%n)]-xt)+abs(ys+l/n*y[n]+y[int(l%n)]-yt)<=l)
      cout<<l<<endl;
   else
      cout<<-1<<endl;
}