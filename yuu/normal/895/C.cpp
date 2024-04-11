#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "C"
int n;
int c[71];
int p[71];
int mask[71];
int a;
ll p2[100001];
int f[71][1<<19];
const ll base=1000000007;
vector <int> pr;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    FOR(i, 2, 70) p[i]=1;
    FOR(i, 2, 70) if(p[i]) for(int j=i+i; j<=70; j+=i) p[j]=0;
    FOR(i, 2, 70) if(p[i]) pr.pb(i);
    FOR(i, 1, 70){
        int u=i;
        FFOR(j, 0, pr.size()){
            while(u%pr[j]==0){
                mask[i]^=1<<j;
                u/=pr[j];
            }
        }
    }
    p2[0]=1;
    FOR(i, 1, 100000) p2[i]=(p2[i-1]*2)%base;
    read(n);
    FOR(i, 1, n){
        read(a);
        c[a]++;
    }
    const int smax=1<<pr.size();
    f[0][0]=1;
    FFOR(i, 0, 70){
        if(c[i+1]){
            FFOR(s, 0, smax) if(f[i][s]) f[i+1][s^mask[i+1]]=(0LL+f[i+1][s^mask[i+1]]+1LL*f[i][s]*p2[c[i+1]-1])%base;
            FFOR(s, 0, smax) if(f[i][s]) f[i+1][s]=(0LL+f[i+1][s]+1LL*f[i][s]*p2[c[i+1]-1])%base;
        }
        else FFOR(s, 0, smax) if(f[i][s]) f[i+1][s]=(f[i+1][s]+f[i][s])%base;
    }
    f[70][0]+=base-1;
    f[70][0]%=base;
    writeln(f[70][0]);
}