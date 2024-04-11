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
#define taskname "D"
int n, m, k;
ll s;
ll a[200001];
ll b[200001];
deque <pair <ll, int> > d, p;
vector <pair <int, int> > trace;
bool check(int u){
    int bd=1, bp=1;
    FOR(i, 2, u){
        if(a[bd]>a[i]) bd=i;
        if(b[bp]>b[i]) bp=i;
    }
    vector <int> buyd;
    vector <int> buyp;
    deque <pair <ll, int> > td=d;
    deque <pair <ll, int> > tp=p;
    ll remain=s;
    while(true){
        if(td.empty()){
            if(tp.empty()) break;
            if(tp.front().first*b[bp]<=remain){
                remain-=tp.front().first*b[bp];
                buyp.pb(tp.front().second);
                tp.pop_front();
            }
            else break;
        }
        else{
            if(tp.empty()){
                if(td.front().first*a[bd]<=remain){
                    remain-=td.front().first*a[bd];
                    buyd.pb(td.front().second);
                    td.pop_front();
                }
                else break;
            }
            else{
                if(td.front().first*a[bd]<tp.front().first*b[bp]){
                    if(td.front().first*a[bd]<=remain){
                        remain-=td.front().first*a[bd];
                        buyd.pb(td.front().second);
                        td.pop_front();
                    }
                    else break;
                }
                else{
                    if(tp.front().first*b[bp]<=remain){
                        remain-=tp.front().first*b[bp];
                        buyp.pb(tp.front().second);
                        tp.pop_front();
                    }
                    else break;
                }
            }
        }
        if(buyd.size()+buyp.size()==k) break;
    }
    if(buyd.size()+buyp.size()==k){
        trace.clear();
        for(int x: buyd) trace.pb(mp(x, bd));
        for(int x: buyp) trace.pb(mp(x, bp));
    }
    else return 0;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    read(k);
    read(s);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 1, n) read(b[i]);
    {
        int t, c;
        FOR(i, 1, m){
            read(t);
            read(c);
            if(t==1) d.pb(mp(c, i));
            else p.pb(mp(c, i));
        }
    }
    sort(d.begin(), d.end());
    sort(p.begin(), p.end());
    int low=1, high=n, mid, ans=n+1;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            ans=mid;
            high=mid-1;
        }
        else low=mid+1;
    }
    if(ans==n+1){
        puts("-1");
        return 0;
    }
    writeln(ans);
    for(pair <int, int> p: trace){
        write(p.first);
        putchar(' ');
        writeln(p.second);
    }
}