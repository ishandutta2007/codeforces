/*ndcoutinho*/
#include <bits/stdc++.h>
using namespace std;
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
#define NMAX 10005
typedef long long ll;
ll n,a[NMAX];
void enter(){
    read(n);
    for(int i=1;i<=n;i++) read(a[i]);
}
void solve(){
    ll tmp=a[2]-a[1];
    for(int i=3;i<=n;i++){
        if(a[i]-a[i-1]!=tmp){
            writeln(a[n]);
            exit(0);
        }
    }
    writeln(a[n]+tmp);
}
int main(){
    enter();
    solve();
}