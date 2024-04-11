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
#define __and _and
#define __or _or
#define __xor _xor
int n;
struct operation{
    char type;
    int value;
} o[500001];
int __xor=0, __or=0, __and=1023;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    cin>>n;
    FOR(i, 1, n) cin>>o[i].type>>o[i].value;
    int b0=0, b1=1023;
    FOR(j, 1, n){
        if(o[j].type=='|'){
            b0|=o[j].value;
            b1|=o[j].value;
        }
        else if(o[j].type=='^'){
            b0^=o[j].value;
            b1^=o[j].value;
        }
        else{
            b0&=o[j].value;
            b1&=o[j].value;
        }
    }
    FFOR(i, 0, 10){
        if(bit(b0, i)==1){
            if(bit(b1, i)==0) __xor|=mask(i);
            else __or|=mask(i);
        }
        else if(bit(b1, i)==0) __and^=mask(i);
    }
    writeln(3);
    cout<<"& ";
    writeln(__and);
    cout<<"| ";
    writeln(__or);
    cout<<"^ ";
    writeln(__xor);
}