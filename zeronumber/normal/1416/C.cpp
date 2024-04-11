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
int n;
ll f[30][2];

void dfs(int x,vi &b){
    vi p,q; p.clear(); q.clear();
    int cnt0=0,cnt1=0;
    for (auto v:b){
        if (v&(1<<x)){
            cnt1++;
            f[x][1]+=cnt0;
            q.pb(v);
        } else {
            cnt0++;
            f[x][0]+=cnt1;
            p.pb(v);
        }
    }
    if (x==0) return;
    if (p.size()) dfs(x-1,p);
    if (q.size()) dfs(x-1,q);
}
mt19937_64 gen(time(0));
int main(){
    scanf("%d",&n);
    vi a; a.clear();
    for (int i=0;i<n;i++){
        int x; scanf("%d",&x);
        a.pb(x);
    }
    dfs(29,a);
    int ans=0; ll inv=0;
    for (int i=0;i<30;i++){
        if (f[i][0]<=f[i][1]) inv+=f[i][0];
        else ans|=1<<i,inv+=f[i][1];
    }
    printf("%lld %d\n",inv,ans);
    return 0;
}