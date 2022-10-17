// luogu-judger-enable-o2
#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
#define IT iterator
#define PB(a) push_back(a)
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> pii;
ll g[9000900];int x,y,z;
int n,m,a,b;
ll mat[3030][3030];
ll st[3030][13];
ll f[3030][3030];
ll res=0;
I solve(){
    int ci2=int(log2(double(b)));
    F(i,1,n-a+1){
        F(j,1,m) st[j][0]=f[i][j];
        F(k,1,12){
            F(j,1,m){
                if(j+(1<<k)-1>m) break;
                st[j][k]=min(st[j][k-1],st[j+(1<<(k-1))][k-1]);
            }
        }
        F(j,1,m-b+1){
            res+=min(st[j][ci2],st[j+b-(1<<(ci2))][ci2]);
        }
    }
}
int main(){
    scanf("%d %d %d %d",&n,&m,&a,&b);
    scanf("%I64d %d %d %d",&g[0],&x,&y,&z);
    F(i,1,8999999){
        g[i]=g[i-1]*x;
        g[i]+=y;
        g[i]%=z;
    }
    F(i,1,n){
        F(j,1,m){
            mat[i][j]=g[(i-1)*m+j-1];
        }
    }
    int ci=int(log2(double(a)));
    F(j,1,m){
        F(i,1,n) st[i][0]=mat[i][j];
        F(k,1,12){
            F(i,1,n){
                if((i+(1<<k))-1>n) break;
                st[i][k]=min(st[i][k-1],st[i+(1<<(k-1))][k-1]);
            }
        }
        F(i,1,n-a+1){
            f[i][j]=min(st[i][ci],st[i+a-(1<<ci)][ci]);
        }
    }
    solve();
    printf("%I64d\n",res);
    return 0;
}