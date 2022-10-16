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
int n;
int a[100001];
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 1, n) read(a[i]);
    sort(a+1, a+n+1);
    ll i=1;
    while(i<n&&a[i+1]==a[1]) i++;
    if(i>=3) writeln(i*(i-1)*(i-2)/6);
    else if(i==2){
        i=3;
        while(i<n&&a[i+1]==a[3]) i++;
        writeln(i-2);
    }
    else{
        i=2;
        while(i<n&&a[i+1]==a[2]) i++;
        if(i>2){
            i--;
            writeln(i*(i-1)/2);
        }
        else{
            i=3;
            while(i<n&&a[i+1]==a[3]) i++;
            writeln(i-2);
        }
    }
}