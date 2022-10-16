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
#define taskname "F"
int n;
pair <ll, ll> p[200001];
ll dist(pair <ll, ll> u, pair <ll, ll> v){
    return abs(u.first-v.first)+abs(u.second-v.second);
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    read(n);
    FOR(i, 1, n){
        read(p[i].first);
        read(p[i].second);
    }
    sort(p+1, p+n+1, [](pair <ll, ll> A, pair <ll, ll> B){
        if(max(A.first, A.second)!=max(B.first, B.second)) return max(A.first, A.second)<max(B.first, B.second);
        if(A.first!=B.first) return A.first<B.first;
        return A.second>B.second;
    });
    int l=0, r=0;
    ll ansl=0, ansr=0;
    ll templ, tempr;
    FOR(i, 1, n){
        int j=i;
        while((j<n)&&(max(p[j+1].first, p[j+1].second)==max(p[i].first, p[i].second))) j++;
        templ=ansl;
        tempr=ansr;
        ansl=dist(p[j], p[i])+min(templ+dist(p[l], p[j]), tempr+dist(p[r], p[j]));
        ansr=dist(p[i], p[j])+min(templ+dist(p[l], p[i]), tempr+dist(p[r], p[i]));
        l=i;
        r=j;
        i=j;
    }
    writeln(min(ansl, ansr));
}