#include <algorithm>
#include <bits/stdc++.h>
#include <cstdlib>
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
#define rdll read<ll>
#define fi first
#define se second
#define mp make_pair
#define pb push_back


const int N=310;
int n,m,e[N][N],f[N][N],ans=-1,rt;

void GG(){
    puts("NO");
    exit(0);
}

int main(){
#ifdef LOCAL
    freopen("data.in","r",stdin);
    freopen("data.out","w",stdout);
#endif
    n=rdi(),m=rdi();

    memset(e,0x3f,sizeof(e));
    for(int i=1;i<=n;i++) e[i][i]=0;
    for(int i=1;i<=m;i++){
        int x=rdi(),y=rdi(),typ=rdi();
        if(typ) e[x][y]=1,e[y][x]=-1;
        else e[x][y]=e[y][x]=1;
    }
    memcpy(f,e,sizeof(e));
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
        }
    }
    for(int i=1;i<=n;i++) if(f[i][i]<0) GG();
    for(int st=1;st<=n;st++){
        int flg=1;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if((e[i][j]==1||e[i][j]==-1)&&f[st][i]==f[st][j]) {flg=0;break;}
            }
        }
        if(!flg) continue;
        auto tmp=minmax_element(f[st]+1,f[st]+n+1);
        if(*tmp.se-*tmp.fi>ans) ans=*tmp.se-*tmp.fi,rt=st;
    }
    if(ans<0) GG();
    printf("YES\n%d\n",ans);int tmp=*min_element(f[rt]+1,f[rt]+n+1);
    for(int i=1;i<=n;i++) printf("%d ",f[rt][i]-tmp);
    puts("");
    return 0;
}