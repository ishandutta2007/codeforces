#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
using ll=long long;
using ld=long double;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar())) x=x*10+c-48;
    if(nega) x=-x;
}
template <typename T> inline void writep(T x){
    if(x>9) writep(x/10);
    putchar(x%10+48);
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    writep(x);
}
template <typename T> inline void writeln(T x){
    write(x);
    putchar('\n');
}
#define taskname "986F"
class query{
public:
    ll n, k;
    int id;
    void input(int id){
        read(n);
        read(k);
        this->id=id;
    }
};
bool ans[10000];
ll k=-1;
ll a;
vector <ll> factors;
void fact(ll n){
    factors.clear();
    if(n%2==0){
        factors.pb(2);
        while(n%2==0) n/=2;
    }
    if(n%3==0){
        factors.pb(3);
        while(n%3==0) n/=3;
    }
    ll i=5;
    int add=2;
    while(i*i<=n){
        if(n%i==0){
            factors.pb(i);
            while(n%i==0) n/=i;
        }
        i+=add;
        add=6-add;
    }
    if(n>1) factors.pb(n);
}
ll f[100001];
vector <ll> g;
class cmp{
public:
    bool operator ()(pair <int, ll> A, pair <int, ll> B){
        return A.second>B.second;
    }
};
priority_queue <pair <int, ll>, vector <pair <int, ll>>, cmp> q;
void make_k(ll newk){
    k=newk;
    fact(k);
    if(factors.size()<=2) return;
    a=factors[0];
    g.clear();
    FFOR(i, 1, factors.size()) g.pb(factors[i]);
    FFOR(i, 0, a) f[i]=2e18;
    f[0]=0;
    q.push(mp(0, 0));
    while(!q.empty()){
        auto p=q.top();
        q.pop();
        if(p.second>f[p.first]) continue;
        for(ll x: g) if(f[(p.first+x)%a]>f[p.first]+x){
            f[(p.first+x)%a]=f[p.first]+x;
            q.push(mp((p.first+x)%a, f[(p.first+x)%a]));
        }
    }
}
ll power(ll a, ll x, ll md){
    if(x==0) return 1;
    ll t=power(a, x/2, md);
    t=(t*t)%md;
    if(x%2) t=(t*a)%md;
    return t;
}
bool have_solution(ll a, ll b, ll n){///a, b is both prime
    ///(b*x)%a==n%a
    ///x==n%a/b;
    ll x=((n%a)*power(b%a, a-2, a))%a;
    return n>=(x*b);
}
void process(query q){
    if(q.k!=k) make_k(q.k);
    if(k==1) ans[q.id]=0;
    else if(factors.size()==1) ans[q.id]=(q.n%factors[0])==0;
    else if(factors.size()==2) ans[q.id]=have_solution(factors[0], factors[1], q.n);
    else ans[q.id]=q.n>=f[q.n%a];
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    vector <query> q;
    q.resize(t);
    FFOR(i, 0, t) q[i].input(i);
    sort(q.begin(), q.end(), [](query A, query B){
        return A.k<B.k;
    });
    for(auto x: q) process(x);
    FFOR(i, 0, t) if(ans[i]) puts("YES"); else puts("NO");
}