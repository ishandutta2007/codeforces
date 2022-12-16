#include <bits/stdc++.h>

using namespace std;

using ll=long long;
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back

const int N=55;

int n,k;
int vis[N][N];

void solve(){
    memset(vis,0,sizeof(vis));
    
    n=rdi(),k=rdi();
    for(int i=1;i<=n;i+=2){
        if(k) vis[i][i]=1,k--;
        else break;
    }
    if(k) puts("-1");
    else{
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) putchar(vis[i][j]?'R':'.');
        puts("");
    }
    }
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}