#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdll read<ll>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=200010;
int n,m,vis[N],ti;
void solve(){
    n=rdi(),m=rdi();++ti;
    for(int i=1;i<=m;i++) rdi(),vis[rdi()]=ti,rdi();
    for(int i=1;i<=n;i++){
        if(vis[i]<ti){
            for(int j=1;j<=n;j++){
                if(i!=j) printf("%d %d\n",i,j);
            }
            return;
        }
    }
    
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}