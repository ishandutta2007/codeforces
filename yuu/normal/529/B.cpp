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
#define taskname "B"
int n, m;
int w[1001];
int h[1001];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(w[i]), read(h[i]);
    ll ans=1LL<<50;
    int m=n/2;
    FOR(i, 1, 1000){
        vector <int> v;
        ll r=0;
        int cnt=0;
        FOR(j, 1, n){
            if(h[j]>i&&w[j]>i){
                goto line1;
            }
            if(h[j]>i) cnt++;
        }
        if(cnt>n/2) continue;
        cnt=m;
        FOR(j, 1, n){
            if(h[j]<=i){
                r+=w[j];
                if(w[j]<=i){//can swap
                    v.pb(h[j]-w[j]);//if swap then r increase by this amount.
                }
            }
            else{//must swap
                r+=h[j];
                cnt--;
            }
        }
        sort(v.begin(), v.end());
        FFOR(j, 0, cnt){
            if(j==v.size()) break;
            if(v[j]>0) break;
            r+=v[j];
        }
        ans=min(ans, r*i);
        line1:;
    }
    writeln(ans);
}