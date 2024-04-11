#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
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
#define taskname "E"
int n, k;
int a[200001];
set <int> s;
vector <int> v;
int done=0;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    read(k);
    FOR(i, 1, n) s.insert(i);
    FOR(i, 1, k){
        read(a[i]);
        s.erase(a[i]);
    }
    FOR(i, 1, k){
        if(v.empty()) v.pb(a[i]);
        else{
            if(a[i]>v.back()){
                write(-1);
                return 0;
            }
            v.pb(a[i]);
        }
        while(!v.empty()&&(v.back()==done+1)){
            done++;
            v.pop_back();
        }
    }
    FOR(i, k+1, n){
        if(v.empty()) a[i]=*s.rbegin();
        else a[i]=*s.lower_bound(v.back()-1);///can't be larger than v.back()
        v.pb(a[i]);
        s.erase(a[i]);
        while(!v.empty()&&(v.back()==done+1)){
            done++;
            v.pop_back();
        }
    }
    FOR(i, 1, n){
        if(i>1) putchar(' ');
        write(a[i]);
    }
}