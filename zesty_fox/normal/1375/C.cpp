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

const int N=300010,INF=0x3f3f3f3f;
int n;
map<int,int> a,pos;

void solve(){
    n=rdi();pos.clear(),a.clear();
    for(int i=1;i<=n;i++) a[i]=rdi(),pos[a[i]]=i;
    for(int i=1;i<=n;i++){
        map<int,int>::iterator it;
        if((it=pos.find(i))==pos.end()) continue;
        it=a.find(it->se);
        if(next(it)==a.end()) break;
        while(next(next(it))!=a.end()){
            auto tmp=next(it);
            pos.erase(tmp->se),a.erase(tmp);
        }
        it=pos.find(i);
        a.erase(it->se),pos.erase(it);
    }
    puts(a.size()==1?"YES":"NO");
}

int T;
int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    T=rdi();
    while(T--) solve();
    return 0;
}