#include<bits/stdc++.h>
using namespace std;
int n,k,a[101000];
int cnt[33],m,p[33];
long long ans=0;
void add(int x,int v){
  for (int i=1;i<=m;i++)
    for (;x%p[i]==0;x/=p[i],cnt[i]+=v);
}
int main(){
  scanf("%d%d",&n,&k);
  for (int i=1;i<=n;scanf("%d",&a[i++]));
  for (int i=2;i<=100000;i++){
    if (k%i==0){
      p[++m]=i;
      for (;k%i==0;k/=i,cnt[m]--);
    }
  }
  if (k>1) {
    p[++m]=k;
    cnt[m]--;
  }
  int t1,t2=0;
  for (t1=1;;add(a[t1++],-1)){
    for (;*min_element(cnt+1,cnt+m+1)<0|t2<t1;){
      if (t2>=n) return 0*printf("%I64d",ans);
      add(a[++t2],1);
    }
    ans+=n-t2+1;
  }
}