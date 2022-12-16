#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=100010;

int n,a[N];
vi res;

int vis[21][N],ti[21];

void dfs(int d,vi a,vi cards,int maxn){
    if(maxn<=1){
        int flg=0;
        for(auto x:a) flg|=(x>0),flg|=((x<0)<<1);
        if(flg&1) cards.pb(1<<d);
        if(flg&2) cards.pb(-(1<<d));
        if(res.empty()||cards.size()<res.size()) res=cards;
        return;
    }

    bool flg=1;
    for(auto x:a) flg&=(x%2==0);
    if(flg){
        maxn=0;
        for(auto &x:a) x/=2,maxn=max(maxn,abs(x));
        dfs(d+1,a,cards,maxn);
    }
    else{
        for(auto c:{1,-1}){
            cards.pb(c*(1<<d)),maxn=0;
            vi tmp;
            for(auto x:a){
                x&1?x=(x-c)/2:x/=2;
                maxn=max(maxn,abs(x)),tmp.pb(x);
            }

            tmp.erase(unique(tmp.begin(),tmp.end()),tmp.end());
            dfs(d+1,tmp,cards,maxn);
            cards.pop_back();
        }
    }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();int maxn=0;
    for(int i=1;i<=n;i++) a[i]=rdi(),maxn=max(maxn,abs(a[i]));
    sort(a+1,a+n+1),dfs(0,vi(a+1,a+n+1),{},maxn);
    cout<<res.size()<<'\n';
    for(auto x:res) cout<<x<<' ';
    cout<<'\n';
    return 0;
}