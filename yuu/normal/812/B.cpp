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
#define taskname "B"
int f[16][2];
int n, m;
string s[16];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    cin>>n>>m;
    FOR(i, 1, n)
        cin>>s[i];
    FOR(i, 1, n)
        f[i][0]=f[i][1]=100000;
    reverse(s+1, s+n+1);
    f[1][0]=0;
    f[1][1]=m+1;
    FOR(i, 1, n){
        if(s[i].find('1')!=-1){
            int l=s[i].find('1');
            int temp=f[i][1]+m-l+1;
            f[i+1][0]=min(f[i+1][0], temp+l+1);
            f[i+1][1]=min(f[i+1][1], temp+m-l+2);
            l=s[i].rfind('1');
            temp=f[i][0]+l;
            f[i+1][0]=min(f[i+1][0], temp+l+1);
            f[i+1][1]=min(f[i+1][1], temp+m-l+2);
        }
        else{
            f[i+1][0]=min(f[i][0]+1, f[i][1]+m+2);
            f[i+1][1]=min(f[i][1]+1, f[i][0]+m+2);
        }
    }
    int ans=0;
    DFOR(i, n, 1){
        if(s[i].find('1')!=-1){
            int l=s[i].find('1');
            ans=f[i][1]+m-l+1;
            l=s[i].rfind('1');
            ans=min(ans, f[i][0]+l);
            break;
        }
    }
    writeln(ans);
}