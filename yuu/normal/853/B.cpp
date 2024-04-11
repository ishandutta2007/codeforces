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
int n, m, k;
struct flight{
    int d, f, t, c;
    bool operator < (flight x){
        return d<x.d;
    }
} v[100001];
deque <pair <int, int> > q[100001];
priority_queue <pair <int, int>, vector <pair <int, int> >, greater <pair <int, int> > > pq;
bool good[100001];
ll cost[100001];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(m);
    read(k);
    FOR(i, 1, m){
        read(v[i].d);
        read(v[i].f);
        read(v[i].t);
        read(v[i].c);
    }
    sort(v+1, v+m+1);
    FOR(i, 1, m){
        if(v[i].f==0){
            while(!q[v[i].t].empty()&&q[v[i].t].back().second>=v[i].c) q[v[i].t].pop_back();
            q[v[i].t].pb(mp(v[i].d, v[i].c));
        }
    }
    ll ans=1LL<<50;
    ll res=0;
    FOR(i, 1, n){
        if(q[i].empty()){
            puts("-1");
            return 0;
        }
        pq.push(mp(q[i].front().first, i));
        res+=q[i].front().second;
    }
    int cnt=0, j=1;
    FOR(i, 1, 1000000){///come before i, leave not before i+k
        while((!pq.empty())&&(pq.top().first<i+k)){///get the best way to leave
            int x=pq.top().second;
            pq.pop();
            res-=q[x].front().second;
            q[x].pop_front();
            if(q[x].empty()) goto line1;
            else{
                res+=q[x].front().second;
                pq.push(mp(q[x].front().first, x));
            }
        }
        while(j<=m&&v[j].d<i){/// get the best way to go
            if(v[j].t==0){
                if(!good[v[j].f]){
                    good[v[j].f]=1;
                    res+=(cost[v[j].f]=v[j].c);
                    cnt++;
                }
                else{
                    if(v[j].c<cost[v[j].f]){
                        res-=cost[v[j].f];
                        res+=v[j].c;
                        cost[v[j].f]=v[j].c;
                    }
                }
            }
            j++;
        }
        if(cnt==n) ans=min(ans, res);
    }
    line1:;
    if(ans==1LL<<50) ans=-1;
    writeln(ans);
}