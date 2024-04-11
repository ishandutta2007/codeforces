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
#define __builtin_popcount __builtin_popcountll
using ll=long long; using ld=long double;
mt19937_64 rng(chrono::high_resolution_clock::now().time_since_epoch().count()); const ld pi=acos(0)*2;
template <typename T> inline void read(T &x){char c; bool nega=0; while((!isdigit(c=getchar()))&&(c!='-')); if(c=='-'){nega=1; c=getchar();} x=c-48; while(isdigit(c=getchar())) x=x*10+c-48; if(nega) x=-x;}
template <typename T> inline void writep(T x){if(x>9) writep(x/10); putchar(x%10+48);}
template <typename T> inline void write(T x){if(x<0){ putchar('-'); x=-x;} writep(x);}
template <typename T> inline void writeln(T x){write(x); putchar('\n');}
#define taskname "A"
int n;
deque <int> a;
deque <int> b;
bool h[200001];
bool check(int d){
    ///delay for d turn before making the first move
    FOR(i, 1, n) h[i]=0;
    for(int x: a) if(x) h[x]=1;
    int x=0;
    FOR(i, 1, d){
        h[b[x]]=1;
        x++;
    }
    FOR(i, 1, n){
        if(h[i]==0) return 0;
        if(x<n) h[b[x]]=1;
        x++;
    }
    return 1;
}
deque <int> rb;
void output(){
    int pos=-1;
    FFOR(i, 0, n) if(b[i]==1){
        pos=i;
        break;
    }
    if(pos==-1) return;
    FFOR(i, pos, n) if(b[i]!=i-pos+1) return;
    for(int x: a) h[x]=1;
    int ans=0;
    int x=0;
    FOR(i, b.back()+1, n){
        if(h[i]==0) return;
        if(x<n) h[b[x]]=1;
        x++;
        ans++;
    }
    writeln(ans);
    exit(0);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    read(n);
    a.resize(n);
    b.resize(n);
    for(int &x: a) read(x);
    for(int &x: b) read(x);
    output();
    int low=0, high=n-1, mid, res=n;
    while(low<=high){
        mid=(low+high)/2;
        if(check(mid)){
            res=mid;
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    writeln(res+n);
}