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
#define taskname "B"
#include <iostream>
using namespace std;
int f[501][501];
int k[100001];
string s;
int x, y, x0, y0;
int main(){
    #ifdef I_have_no_girlfriend
        if(fopen(taskname".inp", "r"))
            freopen(taskname".inp", "r", stdin);
    #endif // I_have_no_girlfriend
    read(x);
    read(y);
    read(x0);
    read(y0);
    cin>>s;
    FOR(i, 1, x)
        FOR(j, 1, y)
            f[i][j]=-1;
    f[x0][y0]=0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='U'){
            if(x0!=1){
                if(f[x0-1][y0]==-1)
                    f[x0-1][y0]=i+1;
                x0--;
            }
        }
        else if(s[i]=='D'){
            if(x0!=x){
                if(f[x0+1][y0]==-1)
                    f[x0+1][y0]=i+1;
                x0++;
            }
        }
        else if(s[i]=='L'){
            if(y0!=1){
                if(f[x0][y0-1]==-1)
                    f[x0][y0-1]=i+1;
                y0--;
            }
        }
        else if(s[i]=='R'){
            if(y0!=y){
                if(f[x0][y0+1]==-1)
                    f[x0][y0+1]=i+1;
                y0++;
            }
        }
    }
    FOR(i, 1, x){
        FOR(j, 1, y){
            if(f[i][j]!=-1)
                k[f[i][j]]++;
            else k[s.size()]++;
        }
    }
    FOR(i, 0, s.size()){
        write(k[i]);
        putchar(' ');
    }
}