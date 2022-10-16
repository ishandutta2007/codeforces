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
string s;
vector <int> p;
int k;
bool check(int maxw){
    int w=0;
    int res=1;
    for(int x: p){
        if(x>maxw) return 0;
        w+=x;
        if(w>maxw){
            w=x;
            res++;
            if(res>k) return 0;
        }
    }
    return 1;
}
int main(){
    #ifdef Uiharu
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Uiharu
    cin>>k;
    cin.ignore();
    getline(cin, s);
    int sz=0;
    for(char c: s){
        sz++;
        if((c=='-')||(c==' ')){
            p.pb(sz);
            sz=0;
        }
    }
    p.pb(sz);
    int l=1, r=s.size(), m, ans=s.size();
    while(l<=r){
        m=(l+r)/2;
        if(check(m)){
            ans=m;
            r=m-1;
        }
        else l=m+1;
    }
    writeln(ans);
}