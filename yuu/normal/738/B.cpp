#include <stdio.h>
#include <locale>
using namespace std;
bool a[1001][1001];
int cnt=0;
template <typename T> inline void read(T &x){
    char c;
    bool negative=0;
    while(!isdigit(c=getchar()));
    if(c=='-'){
        negative=1;
        c=getchar();
    }
    x=c-48;
    while(isdigit(c=getchar()))
        x=10*x+c-48;
    if(negative) x=-x;
}
template <typename T> inline void write(T x){
    if(x<0){
        putchar('-');
        x=-x;
    }
    if(x>9) write(x/10);
    putchar(x%10+48);
}
int main(){
    //freopen("B.INP", "r", stdin);
    int n, m;
    read(n);
    read(m);
    for(int i=1; i<=n; i++)
        for(int j=1; j<=m; j++)
            read(a[i][j]);
    bool d;
    for(int i=1; i<=n; i++){
        d=0;
        for(int j=1; j<=m; j++){
            d=d||a[i][j];
            cnt+=d*(1-a[i][j]);
        }
        d=0;
        for(int j=m; j>=1; j--){
            d=d||a[i][j];
            cnt+=d*(1-a[i][j]);
        }
    }
    for(int i=1; i<=m; i++){
        d=0;
        for(int j=1; j<=n; j++){
            d=d||a[j][i];
            cnt+=d*(1-a[j][i]);
        }
        d=0;
        for(int j=n; j>=1; j--){
            d=d||a[j][i];
            cnt+=d*(1-a[j][i]);
        }
    }
    write(cnt);
}