#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
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
#define taskname "B"
string s, t;
int ans=1001;
vector <int> v;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    int x;
    cin>>x>>x;
    cin>>s>>t;
    FFOR(i, 0, t.size()){
        if(i+s.size()-1>=t.size()) break;
        int res=0;
        FFOR(j, 0, s.size()) res+=(s[j]!=t[i+j]);
        if(res<ans){
            ans=res;
            v.clear();
            FFOR(j, 0, s.size()) if(s[j]!=t[i+j]) v.pb(j);
        }
    }
    writeln(ans);
    for(int x: v){
        write(x+1);
        putchar(' ');
    }
}