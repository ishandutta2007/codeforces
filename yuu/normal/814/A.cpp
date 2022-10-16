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
int n, k;
int a[201], b;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    read(k);
    if(k>1){
        puts("Yes");
        return 0;
    }
    else if(k==0){
        FOR(i, 1, n) read(a[i]);
        FOR(i, 2, n){
            if(a[i]<a[i-1]){
                puts("Yes");
                return 0;
            }
        }
        puts("No");
    }
    else{
        FOR(i, 1, n) read(a[i]);
        read(b);
        FOR(i, 1, n) if(a[i]==0) a[i]=b;
        FOR(i, 2, n){
            if(a[i]<a[i-1]){
                puts("Yes");
                return 0;
            }
        }
        puts("No");
    }
}