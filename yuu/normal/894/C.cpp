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
#define taskname "C"
int m;
int s[1001];
vector <int> ans;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(m);
    FOR(i, 1, m) read(s[i]);
    if(m==1){
        writeln(1);
        write(s[1]);
        return 0;
    }
    int gcd=s[1];
    FOR(i, 2, m) gcd=__gcd(s[i], gcd);
    if(gcd<s[1]){
        puts("-1");
        return 0;
    }
    FOR(i, 1, m){
        ans.pb(s[i]);
        ans.pb(gcd);
    }
    writeln(ans.size());
    FFOR(i, 0, ans.size()){
        if(i) putchar(' ');
        write(ans[i]);
    }
}