#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define sqr(x) ((x)*(x))
#define mp make_pair
#define ld double
#define poly vector<ll>
inline char gc(){
    static char buf[100000],*p1=buf,*p2=buf;
    return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
#define gc getchar
inline ll read(){
    ll x = 0; char ch = gc(); bool positive = 1;
    for (; !isdigit(ch); ch = gc())	if (ch == '-')	positive = 0;
    for (; isdigit(ch); ch = gc())	x = x * 10 + ch - '0';
    return positive ? x : -x;
}
inline void write(ll a){
    if(a<0){
    	a=-a; putchar('-');
    }
    if(a>=10)write(a/10);
    putchar('0'+a%10);
}
inline void wri(ll a){write(a); putchar(' ');}
inline void writeln(ll a){write(a); puts("");}
struct cp{
    ld x,y;
    cp(): x(0), y(0) { }
    cp(ld xx,ld yy):x(xx),y(yy){}
    void operator =(int xx){
        x=xx; y=0;
    }
};
inline cp operator+(const cp &a, const cp &b) { return cp(a.x + b.x, a.y + b.y); }
inline cp operator-(const cp &a, const cp &b) { return cp(a.x - b.x, a.y - b.y); }
inline cp operator*(const cp &a, const cp &b) { return cp(a.x * b.x - a.y * b.y, a.x * b.y + a.y * b.x); }
inline cp conj(const cp &a) { return cp(a.x, -a.y); }
const double PI=acos(-1);
const int N=1<<16|3;
cp omg[N],inv[N],a[N],b[N];
int rev[N];
void init(int n){
    int len=0; while((1<<len)<n)len++;
    for(int i=0;i<n;i++){
        omg[i]=cp(cos(2*PI*i/n),sin(2*PI*i/n));
        inv[i]=conj(omg[i]);
        rev[i]=rev[i>>1]>>1|((i&1)<<(len-1));
    }
}
void FFT(cp *a,int flag,int n){
    cp *dq;
    if(flag)dq=omg; else dq=inv;
    for(int i=0;i<n;i++)if(rev[i]<i)swap(a[i],a[rev[i]]);
    for(int l=2;l<=n;l*=2){
        int m=l/2;
        for(int p=0;p<n;p+=l){
            for(int i=p;i<p+m;i++){
                cp t=dq[n/l*(i-p)]*a[i+m];
                a[i+m]=a[i]-t; a[i]=a[i]+t;
            }
        }
    }
    if(!flag){
        for(int i=0;i<n;i++)a[i].x/=n;
    }
}
void FFT(cp *a,cp *b,int as,int bs){
    int cs=as+bs-1,len=1;
    while(len<cs)len<<=1;
    init(len);
    for(int i=as;i<len;i++)a[i]=0; for(int i=bs;i<len;i++)b[i]=0;
    FFT(a,1,len); FFT(b,1,len);
    for(int i=0;i<len;i++)a[i]=a[i]*b[i]; 
    FFT(a,0,len);
}
int mod;
void FFT(poly &a,poly &b){
	static cp A[N],B[N];
	int as=a.size(),bs=b.size();
	for(int i=0;i<as;i++){A[i].x=a[i]; A[i].y=0;}
	for(int i=0;i<bs;i++){B[i].x=b[i]; B[i].y=0;}
	FFT(A,B,as,bs);
	for(int i=0;i<as;i++)a[i]=(ll)round(A[i].x)%mod;
}
struct alb{
	int ys;
	poly dp[2];
};
int n,tot,ans;
ll q[100];
alb operator +(alb a,alb b){
	if(a.ys&1){
		swap(b.dp[0],b.dp[1]); swap(b.dp[0][0],b.dp[1][0]);
	}
	b.ys=a.ys+b.ys;
	poly zs(n);
	for(int i=0;i<n;i++)zs[i]=(a.dp[0][i]+a.dp[1][i])%mod;
	FFT(b.dp[0],zs);
	for(int i=0;i<n;i++)zs[i]=(a.dp[0][i]+a.dp[1][i])%mod;
	FFT(b.dp[1],zs);
	for(int i=0;i<n;i++){
		b.dp[1][i]=(b.dp[1][i]-a.dp[0][i])%mod;
		b.dp[0][i]=(b.dp[0][i]+a.dp[0][i])%mod;
	}
	//for(int i=0;i<n;i++)cout<<b.dp[1][i]<<" fjzzq "<<zs[i]<<endl;
	return b;
}
void jy(alb &a){
	a.ys++;
	for(int i=n-1;i;i--)a.dp[1][i]=(a.dp[1][i]+(a.dp[0][i-1]+a.dp[1][i-1]))%mod;
}
int main(){
	//freopen("prophet.in","r",stdin); freopen("prophet.out","w",stdout);
	n=read()+1; ll mx=read(); mod=read();
	mx/=2;
	while(mx){
		q[++tot]=mx; mx/=2;
	}
	alb dq,zs;
	zs.dp[1].resize(n); zs.dp[0].resize(n);
	zs.dp[1][1]=1; zs.dp[1][0]=1; zs.ys=1;
	dq=zs;
	for(int i=tot;i;i--){
		if(i<tot){
			dq=dq+dq; if(q[i]!=2*q[i+1])jy(dq);
		}
		//for(int i=1;i<n;i++)cout<<dq.dp[0][i]<<" "; puts("");
		for(int j=1;j<n;j+=2)ans=(ans+dq.dp[1][j])%mod;
	}
	cout<<(ans+mod)%mod<<endl;
}