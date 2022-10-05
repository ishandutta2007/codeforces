#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#pragma GCC optimize("-ffast-math")
#pragma GCC optimize("inline-functions")
#pragma GCC optimize("inline-small-functions")
#pragma GCC optimize("inline-functions-called-once")
#include<bits/stdc++.h>
#define rint register int
using namespace std;
#define N 100000

bitset<N>b[26],bas,ful,ans;
char s[N+233],t[N+233];
int n,T,ty,l,r,m,x,z,len;

int main(){
  scanf("%s",s); n=strlen(s);
  for (int i=0;i<n;++i) b[s[i]-'a'][i]=ful[i]=1;
  for (scanf("%d",&T);T--;){
    scanf("%d",&ty);
    if (ty==1){
      scanf("%d%s",&x,t); --x;
      b[s[x]-'a'][x]=0;
      b[(s[x]=t[0])-'a'][x]=1;
    }else{
      scanf("%d%d%s",&l,&r,t); --l, --r; m=strlen(t);
      len=r-l+1;
      bas=(ful>>(n-len))<<l;
      ans=bas;
      for (int i=0;i<m;++i){
        ans&=(b[t[i]-'a']&bas)>>i;
      }
      printf("%d\n",ans.count());
    }
  }
}