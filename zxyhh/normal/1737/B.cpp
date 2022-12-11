#include<bits/stdc++.h>
#define ll long long 
inline ll rd() {
    ll _x=0;int _ch=getchar(),_f=1;
    for(;!isdigit(_ch)&&(_ch!='-')&&(_ch!=EOF);_ch=getchar());
    if (_ch=='-'){_f=-1;_ch=getchar();}
    for(;isdigit(_ch);_ch=getchar()) _x=_x*10+_ch-'0';
    return _f*_x;
}
#define maxn 100005
ll l,r;

ll solve(ll x){
    if(x==0) return 0;
    ll t=std::sqrt(x);
    while((t+1)*(t+1)<=x) t++;
    while(t*t>x) t--;
    ll q=t*t;
    ll ans=(t-1)*3;
    if(x>=q)
        ans++;
    if(x>=q+t)
        ans++;
    if(x>=q+t+t)
        ans++;
    return ans;
}
int main() {
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%lld%lld",&l,&r);
        printf("%lld\n",solve(r)-solve(l-1));
    }
}