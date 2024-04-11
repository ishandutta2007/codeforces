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
#define taskname "C"
#define up Toaru
#define down Majutsu
#define left no
#define right Index
int d;
int n, m;
int up[100002];
int down[100002];
int left[100002];
int right[100002];
int cl, cr, cu, cd;
class sofa{
public:
    int x0, y0, x1, y1;
    void input(){
        read(x0);
        read(y0);
        read(x1);
        read(y1);
        if(x0>x1) swap(x0, x1);
        if(y0>y1) swap(y0, y1);
        up[y0]++;
        down[y1]++;
        left[x0]++;
        right[x1]++;
    }
    int to_left(){
        return left[x1-1]-(x0!=x1);
    }
    int to_right(){
        return right[x0+1]-(x0!=x1);
    }
    int to_up(){
        return up[y1-1]-(y0!=y1);
    }
    int to_down(){
        return down[y0+1]-(y0!=y1);
    }
} s[100001];
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(d);
    read(n);
    read(m);
    FOR(i, 1, d) s[i].input();
    read(cl);
    read(cr);
    read(cu);
    read(cd);
    FOR(i, 1, n) left[i]+=left[i-1];
    DFOR(i, n, 1) right[i]+=right[i+1];
    FOR(i, 1, m) up[i]+=up[i-1];
    DFOR(i, m, 1) down[i]+=down[i+1];
    FOR(i, 1, d){
        if(s[i].to_left()==cl){
            if(s[i].to_right()==cr){
                if(s[i].to_up()==cu){
                    if(s[i].to_down()==cd){
                        writeln(i);
                        return 0;
                    }
                }
            }
        }
    }
    writeln(-1);
}