#include<bits/stdc++.h>
using namespace std;

int T,n,m,k,f[101000],g[101000],ans,l,x;
vector<int>vec[101000];

int main(){
  for (cin>>T>>n>>m>>k;T--;){
    k=min(k,min(n,m)); l=n*k;
    for (int i=0;i<=m;++i) vec[i].clear();
    for (int i=0;i<n;++i) scanf("%d",&x), vec[x].push_back(i);
    memset(f,33,sizeof f); f[0]=0;
    for (int i=1;i<=m;++i) if (vec[i].size()){
        memset(g,33,sizeof g);
        for (auto o:vec[i]){
          for (int j=0;j<m&&f[j]<l;++j){
            g[j]=min(g[j],f[j]);
            g[j+1]=min(g[j+1],f[j]%n<=o? f[j]/n*n+o: (f[j]/n+1)*n+o);
          }
        }
        memcpy(f,g,sizeof (int)*(m+2));
      }
    for (ans=0;f[ans+1]<l;++ans);
    cout<<ans<<endl;
  }
}