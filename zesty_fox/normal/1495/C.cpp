#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>

#include <algorithm>
#include <vector>
#include <set>
#include <queue>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-') f=-1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}

#define rdi read<int>
#define rdl read<ll>
#define fi first
#define sec second
#define pb push_back
#define mp make_pair

#define id(x,y) ((x-1)*m+y)
const int M=510;
int n,m,T;
char s[M][M];

void solve(){
    n=rdi(),m=rdi();
    for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
    if(m%3!=1){
        for(int j=2;j<=m;j+=3){
            for(int i=1;i<=n;i++) s[i][j]='X';
        }
        for(int j=3;j<=m;j+=3){
            for(int i=1;i<=n;i++){
                if(s[i][j]=='X'||(j+1<=m&&s[i][j+1]=='X')){
                    s[i][j]=s[i][j+1]='X';
                    goto nxt1;
                }    
            }
            s[1][j]=s[1][j+1]='X';
            nxt1:;
        }
    }
    else{
        for(int j=1;j<=m;j+=3){
            for(int i=1;i<=n;i++) s[i][j]='X';
        }
        for(int j=2;j<=m;j+=3){
            for(int i=1;i<=n;i++){
                if(s[i][j]=='X'||(j+1<=m&&s[i][j+1]=='X')){
                    s[i][j]=s[i][j+1]='X';
                    goto nxt2;
                }   
            }
            s[1][j]=s[1][j+1]='X';
            nxt2:;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++) putchar(s[i][j]);
        puts("");
    }
}

int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}