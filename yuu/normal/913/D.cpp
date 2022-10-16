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
#define time _time
int n;
ll t;
class problem{
    public: int id, a, t;
} p[200001];
int time[200001];
int id[200001];
int pos[200001];
pair <int, ll> it[800001];
pair <int, ll> operator + (pair <int, ll> a, pair <int, ll> b){
    return mp(a.first+b.first, a.second+b.second);
}
void update(int i, int l, int r, int u){
    if(l==r) it[i]=mp(1, time[u]);
    else{
        int m=(l+r)/2;
        if(m>=u) update(2*i, l, m, u);
        else update(2*i+1, m+1, r, u);
        it[i]=it[2*i]+it[2*i+1];
    }
}
int get(int i, int l, int r, int maxe, ll maxt){
    if(l==r){
        return (maxe>0)&&(it[i].first>0)&&(maxt>=it[i].second);
    }
    else{
        int m=(l+r)/2;
        if((it[2*i].first>maxe)||(it[2*i].second>maxt)) return get(2*i, l, m, maxe, maxt);
        return it[2*i].first+get(2*i+1, m+1, r, maxe-it[2*i].first, maxt-it[2*i].second);
    }
}
vector <int> out;
void track(int i, int l, int r, int maxe, ll maxt){
    if(l==r){
        if((maxe>0)&&(it[i].first>0)&&(maxt>=it[i].second)) out.pb(id[l]);
    }
    else{
        int m=(l+r)/2;
        if((it[2*i].first>maxe)||(it[2*i].second>maxt)){
            track(2*i, l, m, maxe, maxt);
            return;
        }
        track(2*i, l, m, it[2*i].first, it[2*i].second);
        track(2*i+1, m+1, r, maxe-it[2*i].first, maxt-it[2*i].second);
    }
}
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    read(t);
    FOR(i, 1, n){
        read(p[i].a);
        read(p[i].t);
        p[i].id=i;
    }
    sort(p+1, p+n+1, [](problem A, problem B){
        return A.t<B.t;
    });
    FOR(i, 1, n) pos[p[i].id]=i;
    FOR(i, 1, n) id[i]=p[i].id;
    FOR(i, 1, n) time[i]=p[i].t;
    sort(p+1, p+n+1, [](problem A, problem B){
        return A.a>B.a;
    });
    int ans=0;
    int best=0;
    FOR(i, 1, n){
        update(1, 1, n, pos[p[i].id]);
        int res=get(1, 1, n, p[i].a, t);
        if(res>ans){
            ans=res;
            best=i;
        }
    }
    writeln(ans);
    FOR(i, 1, 800000) it[i]=mp(0, 0);
    FOR(i, 1, best) update(1, 1, n, pos[p[i].id]);
    track(1, 1, n, p[best].a, t);
    writeln(out.size());
    for(int v: out) write(v), putchar(' ');
}