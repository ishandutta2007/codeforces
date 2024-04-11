#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define mask(i) ((1LL<<(i)))
#define builtin_popcount __builtin_popcountll
typedef long long ll;
typedef long double ld;
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
#define taskname "E"
int n;
int a, b;
ll hp[200001];
ll dmg[200001];
ll c;
multiset <ll> s;
ll sum;
ll basedmg=0;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(a);
    read(b);
    FOR(i, 1, n){
        read(hp[i]);
        read(dmg[i]);
        basedmg+=dmg[i];
        if(hp[i]>=dmg[i]){
            s.insert(hp[i]-dmg[i]);
            sum+=hp[i]-dmg[i];
            if(s.size()>b){
                sum-=*s.begin();
                s.erase(s.begin());
            }
        }
    }
    if(!b){
        write(basedmg);
        return 0;
    }
    while(s.size()<b) s.insert(0);
    c=mask(a);
    ll ans=basedmg+sum;
    FOR(i, 1, n){
        ll newhp=hp[i]*c;
        if(hp[i]-dmg[i]>=*s.begin()){
            ans=max(ans, basedmg+newhp-dmg[i]+sum-(hp[i]-dmg[i]));
        }
        else{
            ans=max(ans, basedmg+newhp-dmg[i]+sum-(*s.begin()));
        }
    }
    write(ans);
}