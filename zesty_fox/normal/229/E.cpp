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

const int N=1010;
const double eps=1e-10;
int n,m;

double fac[N];
void init_fac(int lim){
    fac[0]=1;
    for(int i=1;i<=lim;i++) fac[i]=fac[i-1]*i;
}
inline double C(int n,int m){return fac[n]/fac[m]/fac[n-m];}

vi s[N],seq;
int cnt[N][2];
void init(){
    n=rdi(),m=rdi();
    for(int i=1;i<=m;i++){
        int k=rdi();
        for(int j=1;j<=k;j++){
            int tmp=rdi();
            s[i].pb(tmp),seq.pb(tmp);
        }
    }
    nth_element(seq.begin(),seq.begin()+n-1,seq.end(),greater<int>());
    int mid=seq[n-1];
    for(int i=1;i<=m;i++){
        for(auto x:s[i]){
            if(x==mid) cnt[i][1]++;
            if(x>mid) cnt[i][0]++;
        }
    }
}

double f[N][N],g[N][N];
void solve(){
    f[0][0]=1,g[0][0]=1;
    for(int i=1;i<=m;i++){
        for(int j=cnt[i][0];j<=n;j++){
            for(int k=cnt[i][0];k<=cnt[i][0]+cnt[i][1];k++){
                if(j<k) break;
                g[i][j]+=g[i-1][j-k];
                f[i][j]+=f[i-1][j-k]/C(s[i].size(),k);
            }
        }
    }
    printf("%.10lf\n",f[m][n]/g[m][n]);
}

int main(){
    init_fac(N-10);init();
    solve();
    return 0;
}