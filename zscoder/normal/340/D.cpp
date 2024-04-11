#include<iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<string>
#define Pi 3.14159265358
#define mod9 %1000000009
#define INF 1000000000
#define mod7 %1000000007
#define LL  long long
#define time clock()/(double)CLOCKS_PER_SEC
using namespace std;
  int n,i,a[1000001],ans[1000001],out;
  int T[400001];
  int query(int v,int tl,int tr,int l,int r){
      if (l>r) return 0;
      if (tl==l && tr==r){
          return T[v];
      };
      int tm=(tl+tr)/2;
      return max(query(2*v,tl,tm,l,min(tm,r)),query(2*v+1,tm+1,tr,max(tm+1,l),r));
  };
  void update(int v,int tl,int tr,int pos,int val){
       if (tl==tr){
          T[v]=val;
          return;
       };
       int tm=(tl+tr)/2;
       if (tm>=pos) update(2*v,tl,tm,pos,val); else update(2*v+1,tm+1,tr,pos,val);
       T[v]=max(T[2*v],T[2*v+1]);
  };
int main(){
 #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
 #endif
   cin>>n;
   for (i=1;i<=n;i++)
       cin>>a[i];
   for (i=1;i<=n;i++){
       ans[a[i]]=query(1,1,n,1,a[i]-1)+1;
       update(1,1,n,a[i],ans[a[i]]);
       out=max(out,ans[a[i]]);
   };
   cout<<out;
 return 0;
}