#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=1e6+11;
const ll inf=1e16;
int n,k,d[maxn];
ll f[maxn],g[maxn],F0,F1,F2,F3,F4,F5,s[3][17][50000];
ll qry(int o,int l,int r){
    if (l>r) return -inf;
    int x=d[r-l+1];
    return max(s[o][x][l],s[o][x][r-(1<<x)+1]);
}
void fdp(int n,int m,ll val){
    memcpy(g,f,sizeof(f));
    for (int i=0;i<n;i++) s[i%3][0][i/3]=g[i]-val*10*i/3;
    for (int p=0;p<3;p++){
        int N=(n+2-p)/3;
        for (int j=1;j<16;j++)
            for (int i=0;i+(1<<j)-1<N;i++)
                s[p][j][i]=max(s[p][j-1][i],s[p][j-1][i+(1<<(j-1))]);
    }
    for (int i=0;i<m;i++){
        f[i]=-inf;
        int l=max((i-9*(k-1)+9)/10,0),r=i/10;
        if (l>0){
            int w=i-10*(l-1);
            if (w<=9*k){
                if (w%3==0) f[i]=max(f[i],g[l-1]+val*(w/3));
                else f[i]=max(f[i],g[l-1]+val*3*(k-1));
            }
        }
        for (int o=0;o<3;o++){
            int w=(i-10*o+30)%3;
            int L=(l+2-o)/3;
            int R=(r+3-o)/3-1;
            f[i]=max(f[i],qry(o,L,R)+val*(i-w)/3);
        }
    }
}
int main(){
    cin >> k;
    cin >> F0 >> F1 >> F2 >> F3 >> F4 >> F5;
    for (int i=2;i<maxn;i++) d[i]=d[i/2]+1;
    fdp(1,10,F5*3);
    fdp(10,100,F4*3);
    fdp(100,1000,F3*3);
    fdp(1000,10000,F2*3);
    fdp(10000,100000,F1*3);
    fdp(100000,1000000,F0*3);
    int q;cin >> q;
    while (q--){
        int x;scanf("%d",&x);
        printf("%lld\n",f[x]/3);
    }
}