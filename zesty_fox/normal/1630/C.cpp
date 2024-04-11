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

const int N=200010;

int n,a[N],f[N],L[N],R[N];
int sum[N],ans;
vector<pii> v,v1;

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi();
    for(int i=1;i<=n;i++){
        a[i]=rdi();
        if(!L[a[i]]) L[a[i]]=i;
        R[a[i]]=i;
    }
    for(int i=1;i<=n;i++){
        if(L[i]+1>=R[i]) continue;
        v.pb({L[i],R[i]});
    }
    sort(v.begin(),v.end());
    int r=0,siz=v.size();
    for(int i=0;i<siz;i++){
        if(v[i].se<=r) continue;
        v1.pb(v[i]),r=v[i].se;
    }
    swap(v,v1),siz=v.size(),r=0;
    for(int i=0;i<siz;i++){
        ans+=v[i].se-v[i].fi-1,r=v[i].se;
        while(true){
            int i1=i;
            while(i1<siz&&v[i1].fi<=v[i].se) i1++;
            i1--;
            if(i1>i) ans+=v[i1].se-r-1,r=v[i1].se,i=i1;
            else break;
        }
    }
    cout<<ans<<endl;
    return 0;
}