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
#define taskname "D"
int n, A;
int c[100001];
int cnt[1000001];
bool out[1000001];
set <pair <int, int> > s;
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    read(A);
    FOR(i, 1, n) read(c[i]);
    FOR(i, 1, n) s.insert(mp(0, c[i]));
    s.erase(mp(0, A));
    FOR(i, 1, n){
        if(c[i]!=A){
            if(out[c[i]]) continue;
            s.erase(mp(cnt[c[i]], c[i]));
            cnt[c[i]]++;
            s.insert(mp(cnt[c[i]], c[i]));
        }
        else{
            cnt[c[i]]++;
            while((!s.empty())&&(s.begin()->first<cnt[A])){
                out[s.begin()->second]=1;
                s.erase(s.begin());
            }
            if(s.empty()) break;
        }
    }
    if(s.empty()) s.insert(mp(0, -1));
    writeln(s.begin()->second);
}