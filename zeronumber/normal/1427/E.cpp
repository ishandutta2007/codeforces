#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef vector<int> vi;
typedef long long ll;
typedef pair<int,int> pi;
const int maxn=111;
struct node{
    int op;
    ll x,y;
};
vector<node> ans;
ll n,m;
void mut(ll x,ll y){
    int p=31-__builtin_clz(int(y));
    for (int i=0;i<p;i++) ans.pb((node){0,x<<i,x<<i});
    ll res=1<<p;
    for (int i=0;i<p;i++) if ((y>>i)&1){
        ans.pb((node){0,x*res,x<<i});
        res|=1<<i;
    }
}
int main(){
    cin >> n;
    if (n%4==1) m=n;
    else {
        ans.pb((node){0,n,n});
        ans.pb((node){1,n,n<<1});
        m=n^(n<<1);
    }
    int p=31-__builtin_clz((int)m);
    mut(m,(1<<p)+1);
    ans.pb((node){1,m,m<<p});
    ans.pb((node){1,m^(m<<p),m*((1<<p)+1)});
    ll pr=1<<(p+1),h=1;
    while ((h*pr+1)%n) ++h;
    mut(pr,h);
    mut(n,(pr*h+1)/n);
    ans.pb((node){1,pr*h,pr*h+1});
    cout << ans.size() << endl;
    for (auto x:ans){
        if (x.op) printf("%lld ^ %lld\n",x.x,x.y);
        else printf("%lld + %lld\n",x.x,x.y);
    }
    return 0;
}