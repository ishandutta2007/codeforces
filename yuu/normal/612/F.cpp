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
using ll=long long;
using ld=long double;
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
int n, s;
int a[2000];
deque <int> pos[2001];
map <int, int> m;
int f[2001];
int trace[2001];
int g[2001];
int dist_inc(int u, int v){
    if(v>=u) return v-u;
    return v+n-u;
}
int dist_dec(int u, int v){
    if(v<=u) return u-v;
    return u+n-v;
}
int dist(int u, int v){
    return min(abs(u-v), n-abs(u-v));
}
void output(int x){
    putchar("+-"[x<0]);
    writeln(abs(x));
}
void rebuild(int u){
    if(a[u]>1) rebuild(trace[u]);
    if((a[u]==1)&&(a[s]==1)){
        output(0);
        return;
    }
    int x=a[u];
    int sz=pos[x].size();
    int i=trace[u];
    if(pos[x].size()==1){
        if(dist(i, u)==dist_inc(i, u)){
            output(dist(i, u));
        }
        else{
            output(-dist(trace[u], u));
        }
    }
    else{
        while(dist_inc(pos[x].back(), i)+dist_inc(i, pos[x].front())!=dist_inc(pos[x].back(), pos[x].front())){
            pos[x].pb(pos[x].front());
            pos[x].pop_front();
        }
        if(i==s){
            if(a[s]==0) g[s]=0;
            else g[s]=f[s];
        }
        int maxs=dist_inc(i, pos[x].front());
        int tmax=pos[x].front();
        FFOR(j, 0, sz){
            if(j){
                if(maxs<dist_inc(pos[x][j-1], pos[x][j])){
                    maxs=dist_inc(pos[x][j-1], pos[x][j]);
                    tmax=pos[x][j];
                }
            }
            if(pos[x][j]==u) break;
        }
        if(f[u]==g[i]+n+dist_inc(i, u)-maxs*2){
            int last=i;
            FFOR(j, 0, sz){
                if(pos[x][j]==tmax) break;
                last=pos[x][j];
                output(dist_inc((j==0)?i:pos[x][j-1], pos[x][j]));
            }
            DFOR(j, sz-1, 0){
                output(-dist_dec((j==sz-1)?last:pos[x][j+1], pos[x][j]));
                if(pos[x][j]==tmax){
                    if(tmax==u) break;
                    output(dist_inc(tmax, u));
                    break;
                }
            }
            return;
        }
        maxs=dist_dec(i, pos[x].back());
        tmax=pos[x].back();
        DFOR(j, sz-1, 0){
            if(j<sz-1){
                if(maxs<dist_dec(pos[x][j+1], pos[x][j])){
                    maxs=dist_dec(pos[x][j+1], pos[x][j]);
                    tmax=pos[x][j];
                }
            }
            if(pos[x][j]==u) break;
        }
        if(f[u]==g[i]+n+dist_dec(i, u)-maxs*2){
            int last=i;
            DFOR(j, sz-1, 0){
                if(pos[x][j]==tmax) break;
                last=pos[x][j];
                output(-dist_dec((j==sz-1)?i:pos[x][j+1], pos[x][j]));
            }
            FFOR(j, 0, sz){
                output(dist_inc((j==0)?last:pos[x][j-1], pos[x][j]));
                if(pos[x][j]==tmax){
                    if(tmax==u) break;
                    output(-dist_dec(tmax, u));
                    break;
                }
            }
            return;
        }
    }
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(s);
    s--;
    FFOR(i, 0, n) read(a[i]);
    if(a[s]==*min_element(a, a+n)){
        a[s]--;
    }
    FFOR(i, 0, n) m[a[i]]=0;
    {
        int cnt=0;
        for(auto &t: m) t.second=++cnt;
    }
    FFOR(i, 0, n){
        a[i]=m[a[i]];
        pos[a[i]].pb(i);
    }
    if(a[s]!=1) pos[0].pb(s);
    FOR(x, 1+(a[s]==1), m.size()){
        for(int i: pos[x-1]) g[i]=f[i];
        for(int i: pos[x]) f[i]=1e9;
        int sz=pos[x].size();
//        sort(pos[x-1].begin(), pos[x-1].end());
        for(int i: pos[x-1]){
            if(pos[x].size()==1){
                if(f[pos[x][0]]>g[i]+dist(i, pos[x][0])){
                    f[pos[x][0]]=g[i]+dist(i, pos[x][0]);
                    trace[pos[x][0]]=i;
                }
            }
            else{
                while(dist_inc(pos[x].back(), i)+dist_inc(i, pos[x].front())!=dist_inc(pos[x].back(), pos[x].front())){
                    pos[x].pb(pos[x].front());
                    pos[x].pop_front();
                }
                int maxs=dist_inc(i, pos[x].front());
                FFOR(j, 0, sz){
                    if(j) maxs=max(maxs, dist_inc(pos[x][j-1], pos[x][j]));
                    if(f[pos[x][j]]>g[i]+n+dist_inc(i, pos[x][j])-maxs*2){
                        f[pos[x][j]]=g[i]+n+dist_inc(i, pos[x][j])-maxs*2;
                        trace[pos[x][j]]=i;
                    }
                }
                maxs=dist_dec(i, pos[x].back());
                DFOR(j, sz-1, 0){
                    if(j+1<sz) maxs=max(maxs, dist_dec(pos[x][j+1], pos[x][j]));
                    if(f[pos[x][j]]>g[i]+n+dist_dec(i, pos[x][j])-maxs*2){
                        f[pos[x][j]]=g[i]+n+dist_dec(i, pos[x][j])-maxs*2;
                        trace[pos[x][j]]=i;
                    }
                }
            }
        }
    }
    int best=pos[m.size()][0];
    for(int i: pos[m.size()]) if(f[i]<f[best]) best=i;
    writeln(f[best]);
    rebuild(best);
}