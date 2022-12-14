#include<bits/stdc++.h>
using namespace std;
int p[30];
int main(){
   ios_base::sync_with_stdio(0);
   cin.tie(0);
   int m,n,tmp;
   cin>>m>>n;
   for(int i=0;i<n;i++){
      cout<<1<<endl;
      fflush(stdout);
      cin>>tmp;
      if(tmp==0)  return 0;
      if(tmp==1)  p[i]=1;
      else  p[i]=-1;
   }
   int l=1,r=m;
   for(int i=n;i;i++){
      int mid=(l+r)/2;
      cout<<mid<<endl;
      fflush(stdout);
      cin>>tmp;
      tmp*=p[i%n];
      if(tmp==0)  return 0;
      if(tmp==1)  l=mid+1;
      else  r=mid-1;
   }
}