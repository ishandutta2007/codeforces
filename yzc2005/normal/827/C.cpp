#include <bits/stdc++.h>
const int N=2e5+5;
int n,q,id[233];
char s[N],t[N];
struct bit{
  int s[N];
  void add(int p,int x){
    while(p<=n){
      s[p]+=x;
      p+=p&-p;
    }
  }
  int query(int p){
    int res=0;
    while(p){
      res+=s[p];
      p-=p&-p;
    }
    return res;
  }
  int query(int l,int r){
    return query(r)-query(l-1);
  }
}b[4][11][11];
void modify(int p,int id,int x){
  id=::id[id];
  for(int i=1;i<=10;++i){
    b[id][i][p%i].add(p,x);
  }
}
int main(){
  scanf("%s",s+1);
  id['A']=0;
  id['C']=1;
  id['G']=2;
  id['T']=3;
  n=strlen(s+1);
  for(int i=1;i<=n;++i){
    modify(i,s[i],1);
  }
  scanf("%d",&q);
  while(q--){
    int op;
    scanf("%d",&op);
    if(op==1){
      int x;
      char c;
      scanf("%d %c",&x,&c);
      modify(x,s[x],-1);
      s[x]=c;
      modify(x,c,1);
    }else{
      int l,r,ans=0;
      scanf("%d%d%s",&l,&r,t+1);
      int len=strlen(t+1);
      for(int i=l,j=1;i<=l+len-1;++i,++j){
        ans+=b[id[t[j]]][len][i%len].query(l,r);
      }
      printf("%d\n",ans);
    }
  }
}