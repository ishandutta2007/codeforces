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
int n;
int a[100001];
int cnt[100001];
int p[100001];
int ans=0;
int p2[100001];
const int base=1000000007;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    FOR(i, 2, 100000) if(p[i]==0) for(int j=i; j<=100000; j+=i) if(!p[j]) p[j]=i;
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) cnt[a[i]]++;
    p2[0]=1;
    FOR(i, 1, n) p2[i]=(p2[i-1]*2)%base;
    FOR(i, 1, 100000){
        int mobius=1;
        int c=0;
        int u=i;
        while(u>1){
            int x=p[u];
            u/=x;
            if(x==p[u]) goto line0;
            mobius=-mobius;
        }
        for(int j=i; j<=100000; j+=i) c+=cnt[j];
        ans=(ans+mobius*(p2[c]-1))%base;
        line0:;
    }
    ans=(ans+base)%base;
    writeln(ans);

}