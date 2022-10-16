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
int n;
int p[1000001];
int pos[1000001];
int c[1000001];
ll ft[1000001];
ll get(){
    int u=n; ll res=0;
    for(; u>0; u-=u&-u) res+=ft[u];
    return res;
}
void update(int u, int x){
    for(; u<=n; u+=u&-u) ft[u]+=x;
}
deque <pair <int, int> > dq;
void assign(int u, int x){
    update(u+1, x-c[u]);
    c[u]=x;
}
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    ll ans=0;
    FFOR(i, 0, n){
        read(p[i]);
        p[i]--;
        pos[p[i]]=i;
        ans+=abs(p[i]-i);
        dq.pb(mp((n+i-p[i])%n, p[i]));
        if(i>p[i]) assign(p[i], -1);
        else assign(p[i], 1);
    }
    sort(dq.begin(), dq.end());
    while(!dq.empty()&&dq.front().first==0) dq.pop_front();
    ll now=ans;
    int best=0;
    FFOR(k, 1, n){
        int pos0=k-1;
        if(p[pos0]!=n-1){
            now+=n-p[pos0]-p[pos0];
            assign(p[pos0], -1);
        }
        else{
            now-=1+p[pos0];
            assign(p[pos0], 1);
        }
        now+=get();
        if(now<ans){
            ans=now;
            best=n-k;
        }
        while(!dq.empty()&&dq.front().first==k){
            if(dq.front().second) assign(dq.front().second, 1);
            dq.pop_front();
        }
    }
    write(ans);
    putchar(' ');
    write(best);
}