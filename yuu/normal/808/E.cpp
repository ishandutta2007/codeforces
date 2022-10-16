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
#define taskname "E"
int n, m;
vector <int> a[4];
ll best[300001];
multiset <int> s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(m);
    {
        int w, c;
        FOR(i, 1, n){
            read(w);
            read(c);
            a[w].pb(c);
        }
    }
    FOR(i, 1, 3) sort(a[i].begin(), a[i].end(), greater <int>());
    ll sum=0;
    for(int x: a[2]){
        s.insert(x);
        sum+=x;
    }
    FFOR(i, 1, a[1].size()){
        s.insert(a[1][i]+a[1][i-1]);
        sum+=a[1][i]+a[1][i-1];
        i++;
    }
    DFOR(i, m-m%2, 0){
        while((!s.empty())&&(s.size()*2>i)){
            sum-=(*s.begin());
            s.erase(s.begin());
        }
        best[i]=sum;
        i--;
    }
    if(!a[1].empty()){
        sum=a[1][0];
        s.clear();
        for(int x: a[2]){
            s.insert(x);
            sum+=x;
        }
        FFOR(i, 2, a[1].size()){
            s.insert(a[1][i]+a[1][i-1]);
            sum+=a[1][i]+a[1][i-1];
            i++;
        }
        DFOR(i, (m%2)?m:(m-1), 1){
            while((!s.empty())&&(s.size()*2+1>i)){
                sum-=(*s.begin());
                s.erase(s.begin());
            }
            best[i]=sum;
            i--;
        }
    }
    FOR(i, 1, m) best[i]=max(best[i], best[i-1]);
    ll ans=best[m];
    sum=0;
    for(int x: a[3]){
        if(m<3) break;
        sum+=x;
        m-=3;
        ans=max(ans, sum+best[m]);
    }
    writeln(ans);
}