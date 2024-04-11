#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
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
#define taskname "A"
typedef double ld;
int n, k;
ld L, v1, v2;
bool check(ld t){
    ld s=0;
    ld tt=0;
    ld t1=(L-t*v1)/(v2-v1);
    t1+=t1*(v2-v1)/(v2+v1);
    t-=t1*(n-1);
    s=L-t1*v1*(n-1);
    return t*v2>=s;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>n>>L>>v1>>v2>>k;
    n=(n-1)/k+1;
//    ll ans=(L*(v1+v2)+(L+v1)*v2*(n-1)*2)/(v1+v2+v2*(n-1)*2);
//    cout<<setprecision(10)<<fixed<<ans;
    ld ans=L/v1;
    ld l=0, r=L/v1, m, res=L/v1;
    FOR(i, 1, 100){
        m=(l+r)/2;
        if(check(m)){
            res=m;
            r=m;
        }
        else l=m;
    }
    ans=min(ans, res);
    cout<<setprecision(10)<<fixed<<ans;
}