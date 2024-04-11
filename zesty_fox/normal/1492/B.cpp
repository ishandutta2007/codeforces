#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using vi=vector<int>;
using pii=pair<int,int>;

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
#define mp make_pair
#define pb push_back

const int N=100010;

int n,p[N],res[N];
set<pii> s;
void solve(){
    n=rdi();s.clear();
    for(int i=1;i<=n;i++) p[i]=rdi(),s.insert(mp(p[i],i));
    int pos=0,last=n+1;
    while(!s.empty()){
        int x=s.rbegin()->se;s.erase(prev(s.end()));
        for(int i=x;i<last;i++) s.erase(mp(p[i],i)),res[++pos]=i;
        last=x;
    }
    for(int i=1;i<=n;i++) printf("%d ",p[res[i]]);
    puts("");
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}