#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int N=300010,INF=0x3f3f3f3f;
int T,n,a[N];
vector<int> v[N],q[N];
int main(){
    cin>>T;
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            v[i].clear();
            v[i].push_back(0);
        }
        for(int i=1;i<=n;i++) v[a[i]].push_back(i);
        for(int i=1;i<=n;i++){
            if(v[i].size()==1) v[i].push_back(INF);
            else v[i].push_back(n+1);
        }
        for(int i=1;i<=n;i++) q[i].clear();
        for(int i=1;i<=n;i++){
            int maxn=0;
            for(int j=1;j<v[i].size();j++) maxn=max(maxn,v[i][j]-v[i][j-1]);
            if(maxn!=INF) q[maxn].push_back(i);
        }
        int minx=INF;
        for(int i=1;i<=n;i++){
            for(auto j:q[i]) minx=min(minx,j);
            if(minx==INF) printf("-1 ");
            else printf("%d ",minx);
        }
        puts("");
    }
    return 0;
}