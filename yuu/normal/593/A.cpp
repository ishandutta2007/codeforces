#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
string s;
int cnt[256][256];
int cnt2[256];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    int n;
    cin>>n;
    FOR(i, 1, n){
        cin>>s;
        vector <char> v;
        for(char c='a'; c<='z'; c++){
            if(s.find(c)!=-1) v.pb(c);
        }
        if(v.size()>2) continue;
        if(v.size()==1) cnt2[v[0]]+=s.size();
        else cnt[v[0]][v[1]]+=s.size();
    }
    int ans=0;
    FOR(i, 'a', 'z') FOR(j, i+1, 'z') ans=max(ans, cnt[i][j]+cnt2[i]+cnt2[j]);
    writeln(ans);
}