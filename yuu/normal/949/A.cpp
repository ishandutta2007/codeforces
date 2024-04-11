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
#define taskname "A"
string s;
vector <vector <int> > v;
set <int> pos0, pos1;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>s;
    s='p'+s;
    FFOR(i, 1, s.size()) if(s[i]=='0') pos0.insert(i); else pos1.insert(i);
    while(pos0.size()+pos1.size()){
        if(pos0.empty()){
            writeln(-1);
            return 0;
        }
        vector <int> now;
        now.pb(*pos0.begin());
        pos0.erase(pos0.begin());
        while(true){
            if(pos1.empty()||pos0.empty()) break;
            set <int>::iterator it1=pos1.upper_bound(now.back());
            if(it1==pos1.end()) break;
            set <int>::iterator it0=pos0.upper_bound(*it1);
            if(it0==pos0.end()) break;
            now.pb(*it1);
            now.pb(*it0);
            pos0.erase(it0);
            pos1.erase(it1);
        }
        v.pb(now);
    }
    writeln(v.size());
    for(vector <int> &a: v){
        write(a.size());
        for(int x: a) putchar(' '), write(x);
        putchar('\n');
    }
}