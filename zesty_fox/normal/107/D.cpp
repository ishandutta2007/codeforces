#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MOD=12345,N=155,M=1010;
ll n,m,ans;
int r;
struct Matrix{
    ll s[N][N];
    Matrix(){memset(s,0,sizeof(s));}
    Matrix operator*(const Matrix& a)const{
        Matrix res;
        for(int i=0;i<r;i++){
            for(int j=0;j<r;j++){
                for(int k=0;k<r;k++) (res.s[i][j]+=s[i][k]*a.s[k][j])%=MOD;
            }
        }
        return res;
    }
    Matrix operator^(ll x)const{
        Matrix res=(*this),power=(*this);
        x--;
        while(x){
            if(x&1) (res=res*power);
            power=power*power;x>>=1;
        }
        return res;
    }
}A,Q;

struct Node{
    char ch;
    int k;
}a[M];
void dfs(int now,char ch,int x,int y){
    if(now==m+1){
        Q.s[x][y]++;
        return;
    }
    for(int i=0;i<a[now].k;i++){
        dfs(now+1,ch,x*a[now].k+i,y*a[now].k+(i+(a[now].ch==ch))%a[now].k);
    }
}

bool tag[N],vis[N];
void solve(int now,int s){
    if(now==m+1){
        bool flg=1;
        for(int i='A';i<='Z';i++)
            if(vis[i]&&!tag[i]){flg=0;break;}
        if(flg) (ans+=A.s[0][s])%=MOD;
        return;
    }
    bool tmp=tag[a[now].ch];
    for(int i=1;i<a[now].k;i++) solve(now+1,s*a[now].k+i);
    tag[a[now].ch]=1;
    solve(now+1,s*a[now].k);
    tag[a[now].ch]=tmp;
}

int main(){
    scanf("%lld%lld",&n,&m);r=1;
    if(n==0){
        puts("1");
        return 0;
    }
    for(int i=1;i<=m;i++){
        char s[2];int x;
        scanf("%s%d",s,&x);
        a[i].ch=s[0],a[i].k=x;
        vis[s[0]]=1,r*=x;
    }
    for(int i='A';i<='Z';i++){
        if(vis[i]) dfs(1,i,0,0);
    }
    A.s[0][0]=1;A=A*(Q^n);
    solve(1,0);cout<<ans<<endl;
    return 0;
}