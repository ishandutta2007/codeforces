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
#define taskname "D"
int n;
int a[1000001];
int l[1000001];
int r[1000001];
ll ans=0;
vector <int> s;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n) read(a[i]);
    s.pb(1);
    l[1]=1;
    FOR(i, 2, n){
        while(!s.empty()&&a[s.back()]<=a[i]) s.pop_back();
        if(s.empty()) l[i]=1;
        else l[i]=s.back()+1;
        s.pb(i);
    }
    s.clear();
    s.pb(n);
    r[n]=n;
    DFOR(i, n-1, 1){
        while(!s.empty()&&a[s.back()]<a[i]) s.pop_back();
        if(s.empty()) r[i]=n;
        else r[i]=s.back()-1;
        s.pb(i);
    }
    FOR(i, 1, n) ans+=1LL*a[i]*(r[i]-i+1)*(i-l[i]+1);
    s.clear();
    s.pb(1);
    l[1]=1;
    FOR(i, 2, n){
        while(!s.empty()&&a[s.back()]>=a[i]) s.pop_back();
        if(s.empty()) l[i]=1;
        else l[i]=s.back()+1;
        s.pb(i);
    }
    s.clear();
    s.pb(n);
    r[n]=n;
    DFOR(i, n-1, 1){
        while(!s.empty()&&a[s.back()]>a[i]) s.pop_back();
        if(s.empty()) r[i]=n;
        else r[i]=s.back()-1;
        s.pb(i);
    }
    FOR(i, 1, n) ans-=1LL*a[i]*(r[i]-i+1)*(i-l[i]+1);
    writeln(ans);
}