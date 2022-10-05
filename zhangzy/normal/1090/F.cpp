#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n, ans[1010], que[6][6][6], rk[6];
ll a[6], b[6], c[6];

int ask(int a,int b,int c){
  printf("? %d %d %d",a,b,c);
  cout<<endl;
  int x; cin>>x; return x;
}

void realmain(int s){
  s=min(s,n-4);
  for (int i=0;i<5;++i)
    for (int j=i+1;j<5;++j)
      for (int k=j+1;k<5;++k)
        que[i][j][k]=ask(i+s,j+s,k+s);
  for (int i=0;i<5;++i) rk[i]=i;
  do{
    for (int i=0;i<5;++i)
      for (int j=i+1;j<5;++j)
        for (int k=j+1;k<5;++k){
          int x=min(rk[i],min(rk[j],rk[k]));
          int y=max(rk[i],max(rk[j],rk[k]));
          if (x==0) a[y]=que[i][j][k];
          if (y==4) b[x]=que[i][j][k];
        }
    ll t=(a[2]+a[4]+b[2])/2;
    c[0]=t-b[2]; c[4]=t-a[2];
    c[1]=b[1]-c[4]; c[2]=b[2]-c[4]; c[3]=a[3]-c[0];
    int fl=1;
    for (int i=0;i<5;++i)
      for (int j=i+1;j<5;++j)
        for (int k=j+1;k<5;++k){
          int x=min(rk[i],min(rk[j],rk[k]));
          int y=max(rk[i],max(rk[j],rk[k]));
          if (c[x]+c[y]!=que[i][j][k]) fl=0;
        }
    if (fl){
      for (int i=0;i<5;++i) ans[i+s]=c[rk[i]];
    }
  }while (next_permutation(rk,rk+5));
}

int main(){
  cin>>n;
  for (int i=1;i<=n;i+=5)
    realmain(i);
  printf("!");
  for (int i=1;i<=n;++i) printf(" %d",ans[i]);
  cout<<endl;
}