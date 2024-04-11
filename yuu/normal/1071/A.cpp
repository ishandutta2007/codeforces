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
#define taskname "A"
ll a, b;
vector <int> p;
vector <int> q;
bool done[100001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(a);
    read(b);
    int i=1;
    while(a>=i){
        p.pb(i);
        a-=i;
        done[i]=1;
        i++;
    }
    FOR(i, 1, a){
        done[p[p.size()-i]]=0;
        p[p.size()-i]++;
        done[p[p.size()-i]]=1;
    }
    i=1;
    while(b>=i){
        if(!done[i]){
            q.pb(i);
            b-=i;
        }
        i++;
    }
    writeln(p.size());
    for(int x: p){
        write(x);
        putchar(' ');
    }
    putchar('\n');
    writeln(q.size());
    for(int x: q){
        write(x);
        putchar(' ');
    }
    putchar('\n');
}