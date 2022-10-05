#include<bits/stdc++.h>
#define ll long long
using namespace std;

int G[1001000]; 
int n=1000000, fl[1001000], f[1001000], a[1001000];

int tr[4004000];

void build(int x,int l,int r){
  if (l==r){
    tr[x]=a[l]; return;
  }
  int mid=l+r>>1;
  build(x<<1,l,mid);
  build(x<<1|1,mid+1,r);
  tr[x]=min(tr[x<<1],tr[x<<1|1]);
}
int que(int x,int l,int r,int st,int en){
  if (st>en) return (1e9);
  if (l==st&&r==en) return tr[x];
  int mid=l+r>>1;
  return min(que(x<<1,l,mid,max(st,l),min(en,mid)),
    que(x<<1|1,mid+1,r,max(st,mid+1),min(en,r)));
}

int main(){
  for (int i=2;i<=n;++i)
    if (!fl[i]){
      for (int j=i;j<=n;j+=i){
        fl[j]=1; G[j]=max(G[j],i);
      }
    }
  for (int i=1;i<=n;++i) a[i]=i; a[1]=a[2]=1e9;
  build(1,1,n);
  for (int i=1;i<=n;++i){
    f[i]=a[i];
    f[i]=min(f[i],que(1,1,n,max(G[i]+1,i-G[i]+1),i));
  }
  for (int i=1;i<=n;++i) a[i]=f[i];
  
  build(1,1,n);
  for (int i=1;i<=n;++i){
    f[i]=a[i];
    f[i]=min(f[i],que(1,1,n,max(G[i]+1,i-G[i]+1),i));
  }
  for (int i=1;i<=n;++i) a[i]=f[i];
  
  cin>>n;
  cout<<a[n]<<endl;
}