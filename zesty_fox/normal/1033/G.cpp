#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
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
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=1e5+10;
const int INF=0x3f3f3f3f;

int n,m;
i64 v[N],ans1,ans2;

void solve(int s){
    static int c[N];
    for(int i=1;i<=n;i++) c[i]=v[i]%s;
    sort(c+1,c+n+1),c[n+1]=INF;
    for(int i=1;i<=n+1;i++)
        if(s<=2*c[i]){
            int mi=c[i-1]+1,mx=min(c[i],m);
            if(n-i+1&1){
                mi=max(mi,n==1?0:c[n-1]/2+1);
                tie(mi,mx)=mp(max(mi,s-mx),min(mx,s-mi));
                ans1+=max(mx-mi+1,0);
            }
            else{
                mi=max(mi,c[n]/2+1);
                tie(mi,mx)=mp(max(mi,s-mx),min(mx,s-mi));
                ans2+=max(mx-mi+1,0);
            }
            return;
       }
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) v[i]=rdi64();
    for(int s=2;s<=m*2;s++) solve(s);
    i64 ans3=((i64)m*m-ans1-ans2)/2;
    cout<<ans3<<' '<<ans3<<' '<<ans1<<' '<<ans2<<'\n';
    return 0;
}