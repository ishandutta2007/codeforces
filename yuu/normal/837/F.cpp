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
#define taskname "F"
int n;
ll k;
ll a[200001];
int first;
bool check(ll m){
    ld an=0, as=1;
    DFOR(i, n, first){
        an+=as*a[i];
        if(an>=k) return 1;
        as*=(m+n-i);
        as/=n-i+1;
    }
    return 0;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    first=0;
    FOR(i, 1, n){
        read(a[i]);
        if(a[i]>=k){
            puts("0");
            return 0;
        }
        if(!first&&a[i]>0) first=i;
    }
    if(n-first<=15){
        ll l=1, r=k;
        ll m, ans;
        while(l<=r){
            ll m=(l+r)/2;
            if(check(m)){
                ans=m;
                r=m-1;
            }
            else l=m+1;
        }
        write(ans);
        return 0;
    }
    int ans=0;
    ll sum;
    while(a[n]<k){
        ans++;
        sum=0;
        FOR(i, first, n){
            sum+=a[i];
            if(sum>=k) goto line1;
            a[i]=sum;
        }
    }
    line1:;
    writeln(ans);
}