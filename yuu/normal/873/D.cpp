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
#define taskname "D"
#define fmax FMAX
int fmax[100001];
int a[100001];
int n, k;
void solve(int l, int r, int k){
    if(l==r-1||k==1) return;
    int m=(l+r)/2;
    reverse(a+l, a+r);
    reverse(a+l, a+m);
    reverse(a+m, a+r);
    if(k-2>fmax[m-l]){
        solve(l, m, fmax[m-l]);
        solve(m, r, k-1-fmax[m-l]);
    }
    else{
        solve(l, m, k-2);
        solve(m, r, 1);
    }
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    FOR(i, 1, n) fmax[i]=i*2-1;
    if((fmax[n]<k)||(k%2==0)){
        write(-1);
        return 0;
    }
    if(n==1){
        write(1);
        return 0;
    }
    FFOR(i, 0, n) a[i]=i+1;
    solve(0, n, k);
    FFOR(i, 0, n){
        if(i) putchar(' ');
        write(a[i]);
    }
}