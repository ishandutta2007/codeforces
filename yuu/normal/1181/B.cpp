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
int n;
string s;
string ans;
void test(int cut){
    string p, q;
    FFOR(i, 0, cut) p+=s[i];
    FFOR(i, cut, n) q+=s[i];
    reverse(p.begin(), p.end());
    reverse(q.begin(), q.end());
    while(p.size()<q.size()) p.pb('0');
    while(p.size()>q.size()) q.pb('0');
    string res;
    int cr=0;
    FFOR(i, 0, p.size()){
        res+=char((p[i]-48+q[i]-48+cr)%10+48);
        cr=(p[i]-48+q[i]-48+cr)>=10;
    }
    if(cr) res+='1';
    reverse(res.begin(), res.end());
    if(res.size()<ans.size()) ans=res;
    else if(res.size()==ans.size()) ans=min(ans, res);
}
int main(){
    #ifdef Aria
        if(fopen(taskname".in", "r"))
            freopen(taskname".in", "r", stdin);
    #endif // Aria
    cin>>n>>s;
    int a=-1, b=-1;
    FFOR(i, 1, s.size()) if(s[i]!='0'){
        if(i>s.size()-i){
            b=i;
            break;
        }
        else a=i;
    }
    ans=s;
    test(a);
    test(b);
    cout<<ans<<'\n';
}