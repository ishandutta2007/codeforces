#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
typedef double db;
typedef vector<int> vi;
typedef pair<int,int> pii;

template<typename T>
inline T read(){
    T x=0,f=0;char ch=getchar();
    while(!isdigit(ch)) f|=(ch=='-'),ch=getchar();
    while(isdigit(ch)) x=x*10+(ch^48),ch=getchar();
    return f?-x:x;
}

#define rdi read<int>
#define rdi64 read<i64>
#define fi first
#define se second
#define pb push_back
#define mp make_pair

const int N=245;

i64 t,n1[N][N],n2[N][N];
int x,y;

void simu(i64 x,int d,i64 num[][N]){
    num[0][0]=x;
    for(int i=0;i<d;i++){
        for(int j=0;j<=i;j++){
            num[j][i-j+1]+=(num[j][i-j]+1)/2;
            num[j+1][i-j]+=num[j][i-j]/2;
        }
    }
}

void solve(){
    t=rdi64(),x=rdi(),y=rdi();
    if(!x&&!y) {puts("YES");return;}
    if(t<x+y) {puts("NO");return;}
    for(int i=0;i<=x+y;i++)
        for(int j=0;j<=i;j++) n1[j][i-j]=n2[j][i-j]=0;
    simu(t-x-y,x+y,n1),simu(t-x-y+1,x+y,n2);
    if(n1[x][y]!=n2[x][y]) puts("YES");
    else puts("NO");
}

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    int q=rdi();
    while(q--) solve();
    return 0;
}