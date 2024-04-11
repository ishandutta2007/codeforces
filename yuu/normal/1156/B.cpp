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
#define taskname "B"
string s;
int cnt[256];
bool check(string s){
    FFOR(i, 1, s.size()) if(abs(((int)s[i])-((int)s[i-1]))==1) return 0;
    return 1;
}
void solve(){
    cin>>s;
    FOR(c, 'a', 'z') cnt[c]=0;
    for(int x: s) cnt[x]++;
    string a="";
    FOR(c, 'a', 'z') if(cnt[c]) a.pb(c);
    if(a.size()>=4){
        string res="";
        int mid=a.size()/2;
        string left, right;
        FFOR(i, 0, mid) left.pb(a[i]);
        FFOR(i, mid, a.size()) right.pb(a[i]);
        reverse(left.begin(), left.end());
        reverse(right.begin(), right.end());
        while(true){
            if(left.empty()||right.empty()) break;
            res+=right.back();
            res+=left.back();
            right.pop_back();
            left.pop_back();
        }
        if(right.size()) res+=right.back();
        for(char x: res) FFOR(i, 0, cnt[x]) putchar(x);
        putchar('\n');
        return;
    }
    bool good=0;
    do{
        if(check(a)){
            good=1;
            break;
        }
    }
    while(next_permutation(a.begin(), a.end()));
    if(!good){
        puts("No answer");
    }
    else{
        for(char x: a) FFOR(i, 0, cnt[x]) putchar(x);
        putchar('\n');
        return;
    }
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    int t;
    read(t);
    while(t--) solve();
}