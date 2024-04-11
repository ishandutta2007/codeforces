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
#define mask(i) ((1LL<<(i)))
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
#define taskname "A"
int h;
int a[100002];
int main(){
    #ifdef Megumin
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // Megumin
    read(h);
    h++;
    int n=0;
    FOR(i, 1, h){
        read(a[i]);
        n+=a[i];
    }
    FOR(i, 2, h) if(a[i]>1&&a[i-1]>1){
        puts("ambiguous");
        ///left leaning tree
        FOR(i, 1, h) a[i]+=a[i-1];
        int j=2;
        write(0);
        FOR(i, 2, n){
            putchar(' ');
            write(a[j-2]+1);
            if(i>=a[j]) j++;
        }
        putchar('\n');
        write(0);
        j=2;
        FOR(i, 2, n){
            putchar(' ');
            if(i==a[j]) write(a[j-1]);
            else write(a[j-2]+1);
            if(i>=a[j]) j++;
        }
        return 0;
    }
    puts("perfect");
}