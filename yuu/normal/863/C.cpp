#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(ll i=j; i<=k; i++)
#define FFOR(i, j, k) for(ll i=j; i<k; i++)
#define DFOR(i, j, k) for(ll i=j; i>=k; i--)
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
ll k, a, b;
ll A[4][4];
ll B[4][4];
pair <ll, ll> f[101];
ll done[4][4];
bool win[4][4];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    win[3][2]=win[2][1]=win[1][3]=1;
    read(k);
    read(a);
    read(b);
    FOR(i, 1, 3) FOR(j, 1, 3) read(A[i][j]);
    FOR(i, 1, 3) FOR(j, 1, 3) read(B[i][j]);
    f[1]=mp(win[a][b], win[b][a]);
    done[a][b]=1;
    ll ans=0;
    FOR(i, 2, k){
        ll na=A[a][b];
        ll nb=B[a][b];
        a=na;
        b=nb;
        f[i]=f[i-1];
        f[i].first+=win[a][b];
        f[i].second+=win[b][a];
        if(done[a][b]){
            ll cyc=(i-done[a][b]);
            ll cycstart=done[a][b];
            pair <ll, ll> poll=mp(f[i].first-f[cycstart].first, f[i].second-f[cycstart].second);
            pair <ll, ll> ans=mp((k-cycstart+1)/cyc*poll.first, (k-cycstart+1)/cyc*poll.second);
            ans.first+=f[cycstart-1].first;
            ans.second+=f[cycstart-1].second;
            ans.first+=f[(k-cycstart+1)%cyc+cycstart-1].first-f[cycstart-1].first;
            ans.second+=f[(k-cycstart+1)%cyc+cycstart-1].second-f[cycstart-1].second;
            cout<<ans.first<<' '<<ans.second;
            return 0;
        }
        else done[a][b]=i;
    }
    cout<<f[k].first<<' '<<f[k].second;
}