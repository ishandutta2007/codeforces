#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
typedef long long ll;
template <typename T> inline void read(T &x){
    char c;
    bool nega=0;
    while((!isdigit(c=getchar()))&&(c!='-'));
    if(c=='-'){
        nega=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=x*10+c-48;
    if(nega)
        x=-x;
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
ll n;
string s;
int q;
ll u;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>q;
    while(q--){
        cin>>u>>s;
        for(int i=0; i<s.size(); i++){
            if(s[i]=='L')
                u-=(u&-u)>>1;
            else if(s[i]=='R')
                u+=(u&-u)>>1;
            else{
                ll v=u-(u&-u);
                ll t=u+(u&-u);
                ll p;
                if(v==0)
                    p=t;
                else if((v&-v)<(t&-t))
                    p=v;
                else p=t;
                if(p<=n)
                    u=p;
            }
        }
        cout<<u<<'\n';
    }

}