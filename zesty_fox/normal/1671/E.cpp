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

const int N=300010,MOD=998244353;

int n,flg[N];
char s[N];

string dfs(int x,int dep=1){
    if(dep==n) return string(1,s[x]);
    auto tmp1=dfs(x*2,dep+1),tmp2=dfs(x*2+1,dep+1);
    if(tmp1==tmp2) flg[x]=1;
    else if(tmp1>tmp2) swap(tmp1,tmp2);
    return s[x]+tmp1+tmp2;
}

ll dfs1(int x,int dep=1){
    if(dep==n) return 1;
    return dfs1(x*2,dep+1)*dfs1(x*2+1,dep+1)%MOD*(flg[x]?1:2)%MOD;
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();scanf("%s",s+1);
    dfs(1);cout<<dfs1(1)<<endl;
    return 0;
}