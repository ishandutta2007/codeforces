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
#define taskname "B"
int x;
vector <int> ans;
int op=0;
void output(){
    writeln(op);
    for(int x: ans){
        write(x);
        putchar(' ');
    }
    exit(0);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(x);
//    bug(bitset<8>(x));
    if((x==0)||(builtin_popcount(x)==__lg(x)+1)) output();
    DFOR(i, __lg(x), 0){
        if(bit(x, i)){
            x^=mask(i+1)-1;
            ans.pb(i+1);
            op++;
//            bug(bitset<8>(x));
            if((x==0)||(builtin_popcount(x)==__lg(x)+1)) output();
            x++;
//            bug(bitset<8>(x));
            op++;
            if((x==0)||(builtin_popcount(x)==__lg(x)+1)) output();
        }
    }
}