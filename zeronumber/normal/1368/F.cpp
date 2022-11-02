#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
const int maxn=1e6+12;
const int M=1000000007;
int n,v[maxn],f[maxn],p,ans,s;
void work(vector<int> &a){
    int m=a.size(); printf("%d",m);
    for (auto x:a) v[x]=1;
    for (auto x:a) printf(" %d",x); puts(""); fflush(stdout);
    int p; scanf("%d",&p);
    for (int j=0;j<m;j++) v[p]=0,p=p%n+1;
}
int now(){
    int ret=0;
    for (int i=1;i<=n;i++) if (f[i]) ret+=v[i];
    return ret;
}
int main(){
    scanf("%d",&n);
    if (n<=3){
        puts("0");
        return 0;
    }
    for (int j=2;j<n;j++){
        int tot=n-j-(n-1)/j;
        if (tot>ans) ans=tot,p=j;
    }
    memset(f,1,sizeof(f));
    for (int j=1;j<=p;j++) f[j*n/p]=0;
    s=(n-1)/p;
    //cout<<p<<' '<<s<<' '<<ans<<endl;
    while (now()<ans){
        vector <int> res; res.clear();
        for (int i=1;i<=n;i++) if (f[i]&&!v[i]){
            res.pb(i);
            if (res.size()==s+1) break;
        }
        work(res);
    }
    puts("0");
    return 0;
}