#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll f=1,r=0;char c=getchar();
    while(!isdigit(c))f^=c=='-',c=getchar();
    while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
    return f?r:-r;
}
const int N=1e6+7;
vector<ll>d;
int m,a[N];
inline void init(ll n){
    m=1e6;
    for(int i=1;i*i<=m;i++)a[i*i]=1;
    for(int i=2;i<=m;i++)
	if(!a[i]){
	    ll res=i,tmp=1ll*i*i;
	    while(((__int128)res*tmp)<=n)res*=tmp,d.push_back(res);
	}
    sort(d.begin(),d.end()),d.erase(unique(d.begin(),d.end()),d.end());
}
ll L,R,ans;
inline void work(){
    L=read(),R=read(),ans=0;
    if(L==1)L++,ans++;
    ans+=floorl(sqrtl(R))-floorl(sqrtl(L-1));
    ll l=lower_bound(d.begin(),d.end(),L)-d.begin();
    ll r=upper_bound(d.begin(),d.end(),R)-d.begin()-1;
    ans+=r-l+1;
    printf("%lld\n",ans);
}
int main(){
    init(1e18);int Q=read();
    while(Q--)work();
    return 0;
}