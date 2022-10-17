#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int t,n,m,x,a[N],p[N],b[N];
int main(){
  for(scanf("%d",&t);t;--t){
    scanf("%d%d%d",&n,&m,&x);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    priority_queue<pair<int,int>>que;
    for(int i=1;i<=m;++i)que.push({0,i});
    for(int i=1;i<=n;++i){
      auto p=que.top();que.pop();
      ::p[i]=p.second;p.first-=a[i];que.emplace(p);
    }
    puts("YES");for(int i=1;i<=n;++i)printf("%d%c",p[i]," \n"[i==n]);
  }
  return 0;
}