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
#define taskname "C"
int n;
ll a[200001];
set <ll> s;
int main(){
    #ifdef Kanikou
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Kanikou
    read(n);
    FOR(i, 1, n) read(a[i]);
    FFOR(i, 1, n) if(abs(a[i]-a[i+1])!=1) s.insert(abs(a[i]-a[i+1]));
    if((s.size()>1)||(s.find(0)!=s.end())){
        puts("NO");
        return 0;
    }
    if(s.empty()){
        puts("YES");
        puts("1000000000 1");
        return 0;
    }
    ll x=1000000000;
    ll y=*s.begin();
    FFOR(i, 1, n) if(abs(a[i]-a[i+1])==1){
        if(a[i+1]>a[i]){///RD
            if(a[i]%y==0){
                puts("NO");
                return 0;
            }
        }
        else{///UL
            if(a[i]%y==1){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    write(x), putchar(' ');
    writeln(y);
}