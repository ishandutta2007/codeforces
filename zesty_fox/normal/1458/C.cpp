#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

const int N=1010;
int T,n,m,a[N][N],b[N*N][3],cnt,d[3];
char op[N*N];
void solve(){
    n=rdi(),m=rdi();
    cnt=d[0]=d[1]=d[2]=0;int pos[3]={0,1,2};
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) b[++cnt][0]=i,b[cnt][1]=j,b[cnt][2]=rdi()-1;
    }
    scanf("%s",op+1);
    for(int i=1;i<=m;i++){
        if(op[i]=='D') d[0]++;
        if(op[i]=='U') d[0]--;
        if(op[i]=='L') d[1]--;
        if(op[i]=='R') d[1]++;
        if(op[i]=='I') swap(pos[1],pos[2]),swap(d[1],d[2]);
        if(op[i]=='C') swap(pos[0],pos[2]),swap(d[0],d[2]);
    }
    for(int i=0;i<3;i++) d[i]=(d[i]%n+n)%n;
    for(int i=1;i<=cnt;i++){
        int p[3];
        for(int j=0;j<3;j++) p[j]=(b[i][pos[j]]+d[j])%n;
        a[p[0]][p[1]]=p[2];
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++) printf("%d ",a[i][j]+1);
        puts("");
    }
}

int main(){
    T=rdi();
    while(T--) solve();
    return 0;
}