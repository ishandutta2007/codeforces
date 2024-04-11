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
#define taskname "D"
int n, m;
int p[100001];
int phi[100001];
ll sum[100001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 2, n) if(!p[i]) for(int j=i; j<=n; j+=i) if(!p[j]) p[j]=i;
    FOR(i, 2, n){
        sum[i]=sum[i-1];
        if(sum[i]>100000) continue;
        int u=i;
        while(u%p[i]==0) u/=p[i];
        if(u>1) phi[i]=phi[u]*phi[i/u];
        else phi[i]=i-i/p[i];
        sum[i]+=phi[i];
    }
    read(m);
    if((m<n-1)||(sum[n]<m)){
        puts("Impossible");
        return 0;
    }
    puts("Possible");
    FFOR(i, 1, n){
        write(i);
        putchar(' ');
        writeln(i+1);
    }
    m-=n-1;
    FOR(i, 1, n){
        if(m==0) break;
        FFOR(j, 1, i-1){
            if(__gcd(i, j)==1){
                write(i);
                putchar(' ');
                writeln(j);
                m--;
                if(m==0) break;
            }
        }
    }
}