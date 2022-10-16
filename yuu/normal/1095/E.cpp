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
#define taskname "E"
int n;
string s;
int cnt[1000000];
int cost[256];
int get(){
    ///flip one '(' to ')'
    cnt[0]=cost[s[0]];
    FFOR(i, 1, n) cnt[i]=cnt[i-1]+cost[s[i]];
    if(cnt[n-1]!=2) return 0;
    DFOR(i, n-2, 0) cnt[i]=min(cnt[i], cnt[i+1]);
    int ans=0;
    FFOR(i, 0, n){
        if((cnt[i]==2)&&(s[i]=='(')) ans++;
        if(cnt[i]<0) break;
    }
    return ans;
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cost['(']=1;
    cost[')']=-1;
    cin>>n>>s;
    int ans=get();
    reverse(s.begin(), s.end());
    for(auto &c: s) c^='('^')';
    ans+=get();
    writeln(ans);
}