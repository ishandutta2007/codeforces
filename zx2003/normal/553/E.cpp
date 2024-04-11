#include<bits/stdc++.h>
using namespace std;
char ibuf[1<<23],*ih=ibuf;
inline void read(int&x){
	for(;!isdigit(*ih);++ih);
	for(x=0;isdigit(*ih);x=x*10+*ih++-48);
}
const double pi=acos(-1.0);
const int N=33e3,E=105;
struct C{
    double x,y;
    C(double _x=0,double _y=0):x(_x),y(_y){}
    C operator+(const C&rhs){return C(x+rhs.x,y+rhs.y);}
    C operator-(const C&rhs){return C(x-rhs.x,y-rhs.y);}
    C operator*(const C&rhs){return C(x*rhs.x-y*rhs.y,x*rhs.y+y*rhs.x);}
};
struct FFT{
    int b[N],l;
    C wn[N];
    inline void ini(int n){
        int i,j,k,m;l=n;static int c[N];
        for(i=0;i<n;++i)b[i]=i;
        for(i=n;i>1;i>>=1){
            memcpy(c,b,l<<2);
            for(j=0,m=i>>1;j<n;j+=i)
                for(k=0;k<m;++k)b[j+k]=c[j+(k<<1)],b[j+k+m]=c[j+(k<<1|1)];
        }
        for(i=0;i<=l;++i)wn[i]=C(cos(pi*2*i/l),sin(pi*2*i/l));
    }
    inline void DFT(C*a,int key){
        register int i,j,k,m;static C c[N];memcpy(c,a,l<<4);
        static C w[N];
        for(i=0;i<l;++i)a[b[i]]=c[i];register C v;
        for(i=2;i<=l;i<<=1){
        	m=i>>1;
        	if(key==1)for(j=k=0;j<m;++j,k+=l/i)w[j]=wn[k];
        		else for(j=0,k=l;j<m;++j,k-=l/i)w[j]=wn[k];
            for(j=0,m=i>>1;j<l;j+=i)for(k=0;k<m;++k)v=a[j+k+m]*w[k],a[j+k+m]=a[j+k]-v,a[j+k]=a[j+k]+v;
        }
        if(key==-1)for(i=0;i<l;++i)a[i].x/=l;
    }
}F[16];
int lo[N];
int n,m,T,x,a[E],b[E],c[E],i,j,k,d[55][55];
double f[55][20005],p[E][20005],ff[E][20005];
void solve(int l,int r){
	if(l==r){
		if(r<=T)for(i=1;i<=m;++i)if(d[b[i]][n]<(1<<28))f[a[i]][l]=min(f[a[i]][l],ff[i][l]);
		return;
	}
	int m=l+r>>1;
	solve(m+1,r);
	for(i=1;i<=::m;++i)if(a[i]!=n){
if(l==0 && r==6 && i==4)
++l,--l;
		static C A[N],B[N];static double D[N];
		memset(D+l,0,m-l+1<<3);
		int L=lo[r-l+r-m];
		memset(A,0,16<<L);memset(B,0,16<<L);
		for(j=0;j<=r-m-1;++j)A[j]=f[b[i]][r-j]+c[i];
		for(j=1;j<=r-l;++j)B[j]=p[i][j];
		if(r==T+1){
			double s=1;A[0]=C(0,0);
			for(j=m,k=1;j>=l;--j){
if(l==0 && r==6 && i==4 && j==1)
++l,--l;
				for(;j+k<=T;)s-=p[i][k++];
				D[j]+=s*(f[b[i]][T+1]+c[i]);
			}
		}
		F[L].DFT(A,1);F[L].DFT(B,1);for(j=0;j<1<<L;++j)A[j]=A[j]*B[j];F[L].DFT(A,-1);
		for(j=r-m;j<=r-l;++j)D[r-j]+=A[j].x;
		for(j=l;j<=m;++j)ff[i][j]+=D[j];
	}
	solve(l,m);
}
int main(){
	for(i=1;i<N;++i)lo[i+1]=lo[i]+(i==(i&-i));for(i=0;i<16;++i)F[i].ini(1<<i);
	fread(ibuf,1,1<<23,stdin);
	read(n);read(m);read(T);read(x);
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)d[i][j]=i==j?0:1<<28;
	for(i=1;i<=m;++i)for(read(a[i]),read(b[i]),read(c[i]),d[a[i]][b[i]]=c[i],j=1;j<=T;++j)read(k),p[i][j]=k*1e-5;
	for(i=1;i<=n;++i)for(j=1;j<=n;++j)for(k=1;k<=n;++k)d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
	for(j=1;j<=n;++j)for(i=0;i<=T;++i)f[j][i]=j==n?0:1e8;
	for(i=1;i<=n;++i)f[i][T+1]=d[i][n]+x;
	solve(0,T+1);
	printf("%.8f\n",f[1][0]);
	return 0;
}