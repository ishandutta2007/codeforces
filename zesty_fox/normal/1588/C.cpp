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

const int N=300010;

int n;
map<ll,int> m;
void solve(){
    n=rdi();m.clear();
    ll sum=0,ans=0;m[0]=1;
    for(int i=1;i<=n;i++){
        int x=rdi();sum=x-sum;
        if(i&1){
            while(!m.empty()&&m.rbegin()->fi>sum) m.erase(m.rbegin()->fi);
            ans+=m[sum],m[sum]++;
        }
        else{
            while(!m.empty()&&(-(m.begin()->fi)>sum)) m.erase(m.begin()->fi);
            ans+=m[-sum],m[-sum]++;
        }
    }
    printf("%lld\n",ans);
}

int T;
int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}