#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int t,n,l,r,c1[N],c2[N];
int main(){
  for(scanf("%d",&t);t;--t){
    scanf("%d%d%d",&n,&l,&r);
    memset(c1,0,n+1<<2);
    memset(c2,0,n+1<<2);
    for(int i=1;i<=n;++i){
      int x;scanf("%d",&x);
      if(i<=l)++c1[x];else ++c2[x]; 
    }
    int ans1=std::abs(r-l)/2,ans2=0,ans3=0;
    for(int i=1;i<=n;++i)ans2+=std::abs(c1[i]-c2[i]);
    for(int i=1;i<=n;++i){
      if(l<=r){
        if(c1[i]<=c2[i])ans3+=min((c2[i]-c1[i])/2,ans1);
      }else{
        if(c1[i]>=c2[i])ans3+=min((c1[i]-c2[i])/2,ans1);
      }
    }
    printf("%d\n",ans1+ans2/2-min(ans1,ans3));
  }
  return 0;
}