#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=(j); i<=(k); i++)
#define FFOR(i, j, k) for(int i=(j); i<(k); i++)
#define DFOR(i, j, k) for(int i=(j); i>=(k); i--)
#define bug(x) cerr<<#x<<" = "<<(x)<<'\n'
#define pb push_back
#define mp make_pair
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
int n;
void answer(int x1, int y1, int x2, int y2){
    printf("! %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    exit(0);
}
bool query(int x1, int y1, int x2, int y2){
    printf("? %d %d %d %d\n", x1, y1, x2, y2);
    fflush(stdout);
    int res;
    read(res);
    return res%2;
}
int find_x(int y){
    int l=1, r=n, m;
    while(l<r){
        m=(l+r)/2;
        if(query(l, y, m, y)) r=m;
        else l=m+1;
    }
    return l;
}
int find_y(int x){
    int l=1, r=n, m;
    while(l<r){
        m=(l+r)/2;
        if(query(x, l, x, m)) r=m;
        else l=m+1;
    }
    return l;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    vector <int> x;
    int now=0;
    FFOR(i, 1, n){
        if(query(1, 1, i, n)!=now){
            x.pb(i);
            now=1-now;
        }
    }
    if(x.size()==1) x.pb(n);
    if(x.empty()){
        vector <int> y;
        FFOR(i, 1, n){
            if(query(1, 1, n, i)!=now){
                y.pb(i);
                now=1-now;
            }
        }
        if(y.size()==1) y.pb(n);
        assert(y.size()==2);
        int x1=find_x(y[0]);
        int x2=find_x(y[1]);
        answer(x1, y[0], x2, y[1]);
    }
    else{
        int y1=find_y(x[0]);
        int y2=find_y(x[1]);
        answer(x[0], y1, x[1], y2);
    }
}