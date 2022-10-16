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
#define taskname "I"
int n, k;
int v[300001];
int f[300001];
int ft[300001];
void update(int u){
    for(; u<=n; u+=u&-u) ft[u]++;
}
int get(int u){
    int res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    FOR(i, 1, n) read(v[i]);
    if(k==1){
        write(0);
        return 0;
    }
    sort(v+1, v+n+1);
    int l=0, r=1e9, m, ans=0;
    while(l<=r){
        m=(l+r)/2;
        FOR(i, 1, n) ft[i]=0;
        int j=1;
        FOR(i, k, n){
            if(v[i]-v[1]<=m) f[i]=1;
            else{
                while(v[i]-v[j]>m) j++;
                if(get(i-k)-get(j-2)>0) f[i]=1;
                else f[i]=0;
            }
            if(f[i]) update(i);
        }
        if(f[n]){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    write(ans);
}