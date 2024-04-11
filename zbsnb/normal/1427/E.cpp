#include<bits/stdc++.h>
using namespace std;
#define ll long long
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0)x = 1, y = 0;
	else {
		exgcd(b, a%b, y, x);
		y -= a / b * x;
	}
}
vector<pair<int,pair<ll,ll> > > vec;
void mypow(ll a,ll b){
    ll ret=a;b--;
    while(b){
        if(b&1){
            vec.push_back({0,{ret,a}});
            ret=ret+a;
        }
        vec.push_back({0,{a,a}});
        a=a+a;

        b>>=1;
    }
}
ll work(ll n){
    ll len=1<<(63-__builtin_clzll(n));
    ll m=n*len;mypow(n,len);
    ll c=n^m;vec.push_back({1,{n,m}});
    ll x,y;
    exgcd(n,c,x,y);

    // cout<<n<<" "<<c<<" "<<x<<" "<<y<<endl;

    if(x==0||y==0) return 1;

    mypow(n,abs(x));
    mypow(c,abs(y));
    vec.push_back({1,{abs(n*x),abs(c*y)}});

    return abs(n*x)^abs(c*y);
}
void work2(ll n){
    ll len=1ll<<(63-__builtin_clzll(n));
    ll m=n*len;mypow(n,len);
    ll c=n^m;vec.push_back({1,{n,m}});
    vec.push_back({0,{n,m}});
    vec.push_back({0,{n,c}});
    vec.push_back({1,{n+m,n+c}});
}

int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    ll n;cin>>n;
    ll tmp=work(n);
   
    if(tmp!=1){
        work2(tmp);
    }

    cout<<vec.size()<<endl;
    for(auto &it:vec){
        ll a=it.second.first,b=it.second.second;
        if(it.first==0){
            cout<<a<<" + "<<b<<endl;
        }
        else{
            cout<<a<<" ^ "<<b<<endl;
        }
    }
}