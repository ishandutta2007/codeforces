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
#define taskname "F"
int n, m;
ll c[3000000];
ll cnt[3000000];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    {
        int a;
        FFOR(i, 0, n){
            read(a);
            c[a]++;
        }
    }
    FOR(i, 1, 3000000) if(c[i]){
        FFOR(j, 1, i){
            if((i*j)>=3000000) break;
            cnt[i*j]+=c[i]*c[j];
        }
        if((ll(i))*i<3000000) cnt[i*i]+=c[i]*(c[i]-1)/2;
    }
    FOR(i, 1, 3000000) cnt[i]+=cnt[i-1];
    FOR(i, 1, 3000000) cnt[i]*=2;
    read(m);
    {
        ll all=(ll(n))*(n-1);
        int p;
        FFOR(i, 0, m){
            read(p);
            writeln(all-cnt[p-1]);
        }
    }
}