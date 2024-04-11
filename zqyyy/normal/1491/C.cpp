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
#define mp make_pair
#define pb push_back

const int N=5010;
int n,s[N],pos;
ll ans;
set<int> wz;
void solve(){
    n=rdi();wz.clear();
    for(int i=1;i<=n;i++){
        s[i]=rdi();
        if(s[i]>1) wz.insert(i);
    }
    ans=0;
    while(!wz.empty()){
        auto it=wz.begin();
        if(s[*it]>=n-(*it)+1) ans+=(s[*it]-(n-(*it)+1)),s[*it]=n-(*it)+1;
        if(s[*it]==1) {wz.erase(it);continue;}
        auto it1=it;vi buf;ans++;
        while(it1!=wz.end()){
            int step=s[*it1];
            s[*it1]=max(s[*it1]-1,1);
            if(s[*it1]==1) buf.pb(*it1);
            it1=wz.lower_bound((*it1)+step);
            if(it1==wz.end()) break;
        }
        for(auto tmp:buf) wz.erase(tmp);
    }
    printf("%lld\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}