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
char c[10][10];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    FFOR(i, 0, 10) FFOR(j, 0, 10) cin>>c[i][j];
    FOR(i, 0, 5) FFOR(j, 0, 10){
        int cnt=0;
        FFOR(k, 0, 5){
            if(c[i+k][j]=='O') goto line0;
            else if(c[i+k][j]=='.') cnt++;
        }
        if(cnt==1){
            puts("YES");
            return 0;
        }
        line0:;
    }
    FFOR(i, 0, 10) FOR(j, 0, 5){
        int cnt=0;
        FFOR(k, 0, 5){
            if(c[i][j+k]=='O') goto line1;
            else if(c[i][j+k]=='.') cnt++;
        }
        if(cnt==1){
            puts("YES");
            return 0;
        }
        line1:;
    }
    FOR(i, 0, 5) FOR(j, 0, 5){
        int cnt=0;
        FFOR(k, 0, 5){
            if(c[i+k][j+k]=='O') goto line2;
            else if(c[i+k][j+k]=='.') cnt++;
        }
        if(cnt==1){
            puts("YES");
            return 0;
        }
        line2:;
    }
    FOR(i, 4, 9) FOR(j, 0, 5){
        int cnt=0;
        FFOR(k, 0, 5){
            if(c[i-k][j+k]=='O') goto line3;
            else if(c[i-k][j+k]=='.') cnt++;
        }
        if(cnt==1){
            puts("YES");
            return 0;
        }
        line3:;
    }
    puts("NO");
}