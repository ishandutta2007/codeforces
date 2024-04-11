#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
#define taskname "A"
ll a, b, c;
int n;
ll x[100001];
int lastpos(ll a){
    int l=1, r=n, res=0;
    while(l<=r){
        int m=(l+r)/2;
        if(x[m]<a){
            res=m;
            l=m+1;
        }
        else r=m-1;
    }
    return res;
}
int firstpos(ll a){
    int l=1, r=n, res=n+1;
    while(l<=r){
        int m=(l+r)/2;
        if(x[m]>a){
            res=m;
            r=m-1;
        }
        else l=m+1;
    }
    return res;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(a);
    read(b);
    read(c);
    read(n);
    if(b>c) swap(b, c);
    FOR(i, 1, n)
        read(x[i]);
    sort(x+1, x+n+1);
    int ans=0;
    ans=max(ans, lastpos(c)-firstpos(b)+1);
    writeln(ans);
}