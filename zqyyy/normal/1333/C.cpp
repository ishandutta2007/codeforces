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

const int N=200010;

int n,a[N];
ll sum[N],ans;

set<ll> s;

int main(){
    n=rdi();
    for(int i=1;i<=n;i++) a[i]=rdi(),sum[i]=sum[i-1]+a[i];
    s.insert(0);
    for(int l=1,r=1;l<=n;l++){
        while(r<=n){
            if(s.find(sum[r])!=s.end()) break;
            s.insert(sum[r]),r++;
        }
        ans+=r-l,s.erase(sum[l-1]);
    }
    cout<<ans<<endl;
    return 0;
}