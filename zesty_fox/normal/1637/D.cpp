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

int n,a[N],b[N];
bitset<N*N> f[N];
void solve(){
    n=rdi();ll ans=0,sum=0;
    for(int i=1;i<=n;i++) a[i]=rdi(),ans+=(n-2)*a[i]*a[i],sum+=a[i];
    for(int i=1;i<=n;i++) b[i]=rdi(),ans+=(n-2)*b[i]*b[i],sum+=b[i];
    
    f[0][0]=1;
    for(int i=1;i<=n;i++) f[i]=(f[i-1]<<a[i])|(f[i-1]<<b[i]);
    
    for(int i=sum/2;i>=0;i--){
        if(f[n][i]){
            ans+=i*i+(sum-i)*(sum-i);
            break;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    int T=rdi();
    while(T--) solve();
    return 0;
}