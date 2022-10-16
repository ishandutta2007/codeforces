#include <bits/stdc++.h>
using namespace std;
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define FFOR(i, j, k) for(int i=j; i<k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
#define bug(x) cerr<<#x<<" = "<<x<<'\n'
#define pb push_back
#define mp make_pair
#define setbit(s, i) (s|=(1LL<<(i)))
#define bit(s, i) (((s)>>(i))&1LL)
#define builtin_popcount __builtin_popcountll
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
int f[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[25];
int n;
struct month{
    int year;
    int now;
    int count;
    void get_count(){
        count=f[now];
        if(now==2) if((year%400==0)||((year%4==0)&&(year%100))) count++;
    }
    void next_month(){
        now=now%12+1;
        if(now==1) year++;
        get_count();
    }
} m;
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(n);
    FOR(i, 1, n) read(a[i]);
    FOR(i, 0, 2000){
        FOR(j, 1, 12){
            m.year=i;
            m.now=j;
            m.get_count();
            FOR(k, 1, n){
                if(a[k]!=m.count) goto line0;
                m.next_month();
            }
            puts("YES");
            return 0;
            line0:;
        }
    }
    puts("NO");
}