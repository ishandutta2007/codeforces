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

const int N=5010;
const i64 INFl=0x3f3f3f3f3f3f3f3f;

int n,num[N];
char a[N],b[N];
i64 x,y;
void solve(){
    n=rdi(),x=rdi(),y=rdi();
    scanf("%s%s",a+1,b+1);
    for(int i=1;i<=n;i++) num[i]=a[i]^b[i];
    int cnt=count(num+1,num+n+1,1);
    if(cnt&1) {puts("-1");return;}
    i64 ans=0;
    if(x>=y){
        if(cnt==2){
            bool fl=1;
            for(int i=1;i<n;i++)
                if(num[i]&&num[i+1]) {fl=0;break;}
            ans=fl?y:min(x,2*y);
        }
        else ans=cnt/2*y;
    }
    else{
        static i64 f[N];
        static int pos[N];int c=0;
        for(int i=1;i<=n;i++) if(num[i]) pos[++c]=i;
        auto W = [&](int d){return min(x*d,y);};
        for(int i=1;i<=c;i++){
            f[i]=INFl;
            if(i&1){
                if(i>1) f[i]=f[i-2]+W(pos[i]-pos[i-1]);
                f[i]=min(f[i],f[i-1]);
            }
            else{
                if(i>1) f[i]=f[i-2]+W(pos[i]-pos[i-1]);
                f[i]=min(f[i],f[i-1]+y);
            }
        }
        ans=f[c];
    }
    cout<<ans<<'\n';
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int T=rdi();
    while(T--) solve();
    return 0;
}