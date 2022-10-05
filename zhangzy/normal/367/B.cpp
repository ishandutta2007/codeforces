#include<bits/stdc++.h>
using namespace std;

int n,m,p,x,now,aim,cc;
vector<int>ans,b[201000];
map<int,int>A,B;

void add(int x,int v){
  cc-=A[x]==B[x];
  cc+=A[x]==(B[x]+=v);
}

void doit(vector<int>&vec){
  if (vec.size()<n) return;
  cc=0, B.clear();
  for (int i=0;i<vec.size();++i){
    add(vec[i],1);
    if (i>=n-1){
      if (cc==aim) ans.push_back((i-n+1)*p+now+1);      
      add(vec[i-n+1],-1);
    }
  }
}

int main(){
  scanf("%d%d%d",&m,&n,&p);
  for (int i=0;i<m;++i) scanf("%d",&x), b[i%p].push_back(x);
  for (int i=0;i<n;++i) scanf("%d",&x), ++A[x];
  aim=A.size();
  for (now=0;now<p;++now) doit(b[now]);
  sort(ans.begin(),ans.end());
  printf("%d\n",ans.size());
  for (int i=0;i<ans.size();++i) printf("%d ",ans[i]); puts("");
}