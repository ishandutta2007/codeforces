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
bool isprime(int x){
    int r=round(sqrt(x));
    FOR(i, 2, r) if(x%i==0) return 0;
    return 1;
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    int n;
    read(n);
    if(isprime(n)){
        writeln(1);
        write(n);
        return 0;
    }
    if(isprime(n-2)){
        writeln(2);
        write(2);
        putchar(' ');
        write(n-2);
        return 0;
    }
    int i=2;
    while(!isprime(n-i)) i++;
    int j=2;
    while(!(isprime(i-j)&&isprime(j))) j++;
    writeln(3);
    write(i-j);
    putchar(' ');
    write(j);
    putchar(' ');
    write(n-i);
}