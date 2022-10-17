//CF1151F
#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mk make_pair
#define pii pair<int,int>
#define fst first
#define scd second
using namespace std;
inline ll read() {
    ll f=1,x=0;char ch=getchar();
    while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
    while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
const int MOD=1e9+7;
const int N=100;
const int MAXN=N+5;
int pow_mod(int x,int i) {
    int res=1;
    while(i) {
        if(i&1) res=(ll)res*x%MOD;
        x=(ll)x*x%MOD;
        i>>=1;
    }
    return res;
}
int n,k,a[MAXN],c;
struct Matrix {
    int a[MAXN][MAXN];
    Matrix(){memset(a,0,sizeof(a));}
}A,B;
Matrix operator * (Matrix X,Matrix Y) {
    Matrix Z;
    for(int i=0;i<=N;++i) {
        for(int j=0;j<=N;++j) {
            for(int k=0;k<=N;++k) {
                Z.a[i][j]=((ll)Z.a[i][j]+(ll)X.a[i][k]*Y.a[k][j]%MOD)%MOD;
            }
        }
    }
    return Z;
}
Matrix matrix_pow(Matrix X,int i) {
    Matrix Y;
    for(int i=0;i<=N;++i) Y.a[i][i]=1;
    while(i) {
        if(i&1) Y=Y*X;
        X=X*X;
        i>>=1;
    }
    return Y;
}
void Print(Matrix X) {
    for(int i=0;i<=10;++i) {
        for(int j=0;j<=10;++j) {
            cout<<X.a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}
int main() {
//  freopen("","r",stdin);
//  freopen("","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);/*syn*/
    n=read();k=read();
    for(int i=1;i<=n;++i) a[i]=read(),c+=(a[i]==0);
    int t=0;
    for(int i=1;i<=c;++i) t+=(a[i]==0);
    A.a[0][t]=1;

    for(int i=0;i<=c;++i) {
        if(i!=0) B.a[i-1][i]=1LL*(c-(i-1))*(c-(i-1))%MOD;
        B.a[i][i]=1LL*(1LL*i*(c-i)%MOD+1LL*(c-i)*(n-c-c+i))%MOD;
        B.a[i][i]=(B.a[i][i]+1LL*c*(c-1)/2%MOD)%MOD;
        B.a[i][i]=(B.a[i][i]+1LL*(n-c)*(n-c-1)/2%MOD)%MOD;
        if(i!=c) B.a[i+1][i]=1LL*(i+1)*(n-c-c+i+1)%MOD;
    }

    B=matrix_pow(B,k);
    A=A*B;

    int ans=A.a[0][c]; t=0;
    for(int i=0;i<=c;++i)t=((ll)t+A.a[0][i])%MOD;
    ans=((ll)ans*pow_mod(t,MOD-2))%MOD;
    cout<<ans<<endl;
    return 0;
}