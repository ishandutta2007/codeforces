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
#define taskname "B"
int t, n, k;
string s[5];
bool f[5][101];
struct train{
    int i, j;
    train (int i, int j){
        this->i=i;
        this->j=j;
    }
    train(){
        i=j=0;
    }
} T[5][26];
int cnt[5];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>t;
    while(t--){
        cin>>n>>k;
        FOR(i, 1, 3) cin>>s[i];
        FOR(i, 1, 3) f[i][0]=cnt[i]=0;
        FOR(i, 1, 3){
            if(s[i][0]=='s'){
                f[i][0]=1;
                if(n>1&&isalpha(s[i][1])) f[i][0]=0;
                s[i][0]='.';
                break;
            }
        }
        FOR(r, 1, 3){
            FOR(i, 0, n-1){
                if(s[r][i]!='.'){
                    int j=i;
                    while(j+1<n&&s[r][j+1]==s[r][i]) j++;
                    FOR(k, i, j) s[r][k]='.';
                    cnt[r]++;
                    T[r][cnt[r]]=train(i, j);
                }
            }
        }
        FOR(i, 1, n-1){
            FOR(r, 1, 3){
                FOR(k, 1, cnt[r]){
                    train t(T[r][k].i-2*i, T[r][k].j-2*i+2);
                    if(t.i<=i+1&&i<=t.j){
                        f[r][i]=0;
                        goto line1;
                    }
                }
                f[r][i]=(f[r-1][i-1]||f[r][i-1]||f[r+1][i-1]);
                line1:;
            }
        }
        if(f[1][n-1]||f[2][n-1]||f[3][n-1]) cout<<"YES\n";
        else cout<<"NO\n";
    }
}