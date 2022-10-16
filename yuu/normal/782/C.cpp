#include <bits/stdc++.h>
using namespace std;
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
int n, x, y;
vector <int> adj[200001];
int c[200001];
void color(int u, int mau, int mauchau){
    int mauhientai=1;
    for(int v: adj[u]){
        if(!c[v]){
            while(mauhientai==mau||mauhientai==mauchau)
                mauhientai++;
            c[v]=mauhientai;
            color(v, mauhientai, mau);
            mauhientai++;
        }
    }
}
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(n);
    FOR(i, 2, n){
        read(x);
        read(y);
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    c[1]=1;
    color(1, 1, 0);
    int ans=0;
    FOR(i, 1, n)
        ans=max(ans, c[i]);
    writeln(ans);
    FOR(i, 1, n){
        write(c[i]);
        putchar(' ');
    }
}