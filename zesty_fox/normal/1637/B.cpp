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

const int N=110;

int n,a[N],me[N][N];

int mex(vi a){
    sort(a.begin(),a.end());
    int last=-1;
    for(auto x:a){
        if(x>last+1) return last+1;
        else last=x;
    }
    return a.back()+1;
}

void solve(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi();

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j++) me[i][j]=mex(vi(a+i,a+j+1));

    ll sum=0;
    for(int l=1;l<=n;l++){
        static int f[N];
        f[l-1]=0;
        for(int r=l;r<=n;r++){
            f[r]=-1;
            for(int k=r;k>=l;k--) f[r]=max(f[r],f[k-1]+me[k][r]+1);
            sum+=f[r];
        }
    }
    cout<<sum<<'\n';
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}