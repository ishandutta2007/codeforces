// LUOGU_RID: 97318825
#include <bits/stdc++.h>

using namespace std;

using i64=long long;
using vi=vector<int>;
using pii=pair<int,int>;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=(x*10)+(ch^48),ch=getchar();
    return !f?x:-x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=2010;

int n;
char ch[N][N];

int f[N];
int find(int x) {return x==f[x]?f[x]:f[x]=find(f[x]);}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) scanf("%s",ch[i]+i);
    iota(f+1,f+n+1,1);
    for(int l=n;l>=1;l--){
        for(int r=l+1;r<=n;r++){
            if(ch[l][r]=='0'||find(l)==find(r)) continue;
            cout<<l<<' '<<r<<'\n';
            for(int i=find(find(l)+1);i!=find(r);i=find(i)){
                if(find(i+1)==find(r)) cout<<l<<' '<<i<<'\n';
                else cout<<i<<' '<<r<<'\n';
                f[i]=i+1;
            }
            f[find(l)]=find(r);
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}