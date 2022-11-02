#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=1234567;
int deg[maxn],n,a[maxn*2],b[maxn*2],p[maxn];
struct node{
    int to,pos,id;
};
vector <node> h[maxn];
vector <int> ans;
void dfs(int u){
    while (p[u]<h[u].size()){
        if (h[u][p[u]].pos==-1) {p[u]++;continue;}
        int v=h[u][p[u]].to,pp=h[u][p[u]].pos,id=h[u][p[u]].id;
        h[u][p[u]].pos=-1;
        h[v][pp].pos=-1;
        p[u]++;
        dfs(v);
        ans.pb(id);
    }
}
int main(){
    cin >> n;
    for (int i=0;i<n*2;i++) cin >> a[i];
    for (int i=20;i>=0;i--){
        int m=1<<i;
        for (int j=0;j<m;j++) h[j].clear(),p[j]=0;
        for (int j=0;j<n*2;j++) b[j]=a[j]%m;
        for (int j=0;j<n;j++){
            int u=b[j*2],v=b[j*2+1];
            if (u!=v){
                h[u].pb((node){v,h[v].size(),j*2+1});
                h[v].pb((node){u,h[u].size()-1,j*2});
            } else {
                int now=h[u].size();
                h[u].pb((node){u,now+1,j*2+1});
                h[u].pb((node){u,now,j*2});
            }
        }
        ans.clear();
        bool flag=1;
        for (int j=0;j<m;j++) if (h[j].size()%2==1) {flag=0;break;}
        if (!flag) continue;
        for (int j=0;j<m;j++) if (h[j].size()){
            dfs(j);
            break;
        }
        if (ans.size()<n) continue;
        cout << i << endl;
        for (auto x:ans) printf("%d %d ",1+x,1+(x^1)); puts("");
        return 0;
    }
    assert(0);
    return 0;
}