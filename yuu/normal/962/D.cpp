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
int n;
int a[150001];
int b[150001];
map <int, int> m;
vector <pair <int, int> > v[150001];
set <int> s[60];
ll ans[150001];
int cnt=0;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(a[i]);
        int temp=a[i]>>__builtin_ctz(a[i]);
        if(m.find(temp)==m.end()){
            m[temp]=m.size();
            b[m.size()]=temp;
        }
        v[m[temp]].pb(mp(__builtin_ctz(a[i]), i));
    }
    FOR(t, 1, m.size()){
        int maxb=0;
        for(pair <int, int> p: v[t]){
            s[p.first].insert(p.second);
            maxb=max(maxb, p.first);
        }
        FOR(i, 0, maxb){
            while(s[i].size()>=2){
                s[i].erase(s[i].begin());
                s[i+1].insert(*s[i].begin());
                maxb=max(maxb, i+1);
                s[i].erase(s[i].begin());
            }
            if(s[i].size()){
                cnt++;
                ans[*s[i].begin()]=mask(i)*b[t];
                s[i].clear();
            }
        }
    }
    writeln(cnt);
    FOR(i, 1, n) if(ans[i]) write(ans[i]), putchar(' ');
}