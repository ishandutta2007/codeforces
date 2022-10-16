#include <stdio.h>
#include <locale>
#define FOR(i, j, k) for(int i=j; i<=k; i++)
#define DFOR(i, j, k) for(int i=j; i>=k; i--)
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
#define taskname "C"
#include <iostream>
using namespace std;
string s;
int n;
int f[1000001][2][3];
int g[1000001][2][3];
bool donef[1000001][2][3];
bool doneg[1000001][2][3];
int F(int, int, int);
int G(int, int, int);
int G(int i, int j, int k){
//    printf("g %d %d %d\n", i, j, k);
    if(doneg[i][j][k]) return g[i][j][k];
    doneg[i][j][k]=1;
    return g[i][j][k]=max(F(i, j, k), G(i-1, j, k));
}
int F(int i, int j, int k){
//    printf("f %d %d %d\n", i, j, k);
    if(donef[i][j][k]) return f[i][j][k];
    donef[i][j][k]=1;
    if(k==0){
        if(j!=s[i]) return f[i][j][k]=0;
        f[i][j][k]=max(G(i-1, 1-j, k)+1, f[i][j][k]);
    }
    else{
        if(k==1&&j==s[i])
            return f[i][j][k]=0;
        if(k==2&&j!=s[i]) return f[i][j][k]=0;
        f[i][j][k]=max(F(i, 1-j, k-1), f[i][j][k]);
        f[i][j][k]=max(G(i-1, 1-j, k-1)+1, f[i][j][k]);
        f[i][j][k]=max(G(i-1, 1-j, k)+1, f[i][j][k]);
    }
    return f[i][j][k];
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    cin>>n>>s;
    s='0'+s;
    FOR(i, 1, n)
        s[i]-=48;
    FOR(i, 0, 2)
        FOR(j, 0, 1){
            donef[1][j][i]=1;
            doneg[1][j][i]=1;
        }
    f[1][s[1]][0]=1;
    g[1][s[1]][0]=1;
    f[1][s[1]][2]=1;
    g[1][s[1]][2]=1;
    f[1][1-s[1]][1]=1;
    g[1][1-s[1]][1]=1;
    write(max(G(n, 1-s[n], 1), G(n, s[n], 2)));
}