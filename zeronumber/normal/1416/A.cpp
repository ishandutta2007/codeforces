#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<int,int> pi;
typedef vector<int> vi;
const int maxn=1e6+10;
const int M=998244353;
vi a[maxn];
int n,_,ans[maxn];

int main(){
    scanf("%d",&_);
    while (_--){
        scanf("%d",&n);
        for (int i=1;i<=n;i++){
            a[i].clear();
            a[i].pb(0);
        }
        for (int i=1;i<=n;i++){
            int x; scanf("%d",&x);
            a[x].pb(i);
        }
        for (int i=1;i<=n;i++) a[i].pb(n+1);
        for (int i=1;i<=n;i++) ans[i]=n+1;
        for (int i=n;i;i--){
            int dif=0;
            for (int j=0;j<a[i].size()-1;j++) dif=max(dif,a[i][j+1]-a[i][j]);
            ans[dif]=i;
        }
        for (int i=2;i<=n;i++) ans[i]=min(ans[i],ans[i-1]);
        for (int i=1;i<=n;i++) if (ans[i]==n+1) printf("-1 "); else printf("%d ",ans[i]);
        puts("");
    }
    return 0;
}