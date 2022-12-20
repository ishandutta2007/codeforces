#include <bits/stdc++.h>
using namespace std;

typedef long long i64;
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

const int N=5010;
const i64 INF=0x3f3f3f3f3f3f3f3f;

int n,s,e;
struct Point{int x,a,b,c,d;}p[N];

i64 f[N][N];

int main(){
#ifdef LOCAL
    freopen(".in","r",stdin);
    freopen(".out","w",stdout);
#endif
    n=rdi(),s=rdi(),e=rdi();
    for(int i=1;i<=n;i++) p[i].x=rdi();
    for(int i=1;i<=n;i++) p[i].a=rdi();
    for(int i=1;i<=n;i++) p[i].b=rdi();
    for(int i=1;i<=n;i++) p[i].c=rdi();
    for(int i=1;i<=n;i++) p[i].d=rdi();

    memset(f,0x3f,sizeof(f));
    f[0][0]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            if(j==1&&(i<n&&i>=max(s,e))) continue;
            if(i==s){
                f[i][j]=min({
                    f[i-1][j]+p[i].x+p[i].c,
                    f[i-1][j-1]-p[i].x+p[i].d
                });
            }
            else if(i==e){
                f[i][j]=min({
                    f[i-1][j]+p[i].x+p[i].a,
                    f[i-1][j-1]-p[i].x+p[i].b
                });
            }
            else{
                f[i][j]=min(f[i-1][j+1]+2*p[i].x+p[i].a+p[i].c,
                            f[i-1][j-1]-2*p[i].x+p[i].b+p[i].d);
                if(!(j==1&&i>=s)) f[i][j]=min(f[i][j],f[i-1][j]+p[i].c+p[i].b);
                if(!(j==1&&i>=e)) f[i][j]=min(f[i][j],f[i-1][j]+p[i].d+p[i].a);
            }
        }
    }
    cout<<f[n][1]<<endl;
    return 0;
}