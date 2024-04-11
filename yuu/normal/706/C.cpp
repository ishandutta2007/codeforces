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
#define taskname "C"
const ll inf=1e17;
int n;
int c[100001];
string s[2][100001];
ll f[100001][2];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
//    ios_base::sync_with_stdio(false);
//    cin.tie(NULL);
//    cout.tie(NULL);
    cin>>n;
    FOR(i, 1, n)
        cin>>c[i];
    FOR(i, 1, n){
        cin>>s[0][i];
        s[1][i]=s[0][i];
        reverse(s[1][i].begin(), s[1][i].end());
    }
    FOR(i, 2, n)
        f[i][0]=f[i][1]=inf;
    f[1][1]=c[1];
    n--;
    FOR(i, 1, n){
        FOR(j, 0, 1){
            if(f[i][j]!=inf){
                if(s[0][i+1]>=s[j][i])
                    f[i+1][0]=min(f[i+1][0], f[i][j]);
                if(s[1][i+1]>=s[j][i])
                    f[i+1][1]=min(f[i+1][1], f[i][j]+c[i+1]);
            }
        }
    }
    n++;
    ll ans=inf;
    ans=min(ans, f[n][0]);
    ans=min(ans, f[n][1]);
    if(ans==inf) ans=-1;
    write(ans);
}