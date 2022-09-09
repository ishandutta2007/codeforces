#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5,mo=998244353;
const double pi=acos(-1.0);
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
            for(j=0,m=i>>1;j<l;j+=i)
                for(k=0;k<m;++k){
                    v=a[j+k+m]*w[k];
                    a[j+k+m]=a[j+k]-v;
                    a[j+k]=a[j+k]+v;
                }
        }
        if(key==-1)for(i=0;i<l;++i)a[i].y/=l;
    }
}F;
int n,m,q,i,j,a[N],b[N],x,c[8][N],d[8][N];
ll cc[N],dd[N];
inline void mul(int*a,int*b,ll*c){
	static C x[N];
	for(j=0;j<F.l;++j)x[j]=C{a[j],b[j]};
	F.DFT(x,1);for(j=0;j<F.l;++j)x[j]=x[j]*x[j];F.DFT(x,-1);
	for(j=0;j<F.l;++j)c[j]+=ll(abs(x[j].y)/2+0.5)*(x[j].y>0?1:-1);
}
int main(){
	scanf("%d%d%d",&n,&m,&q);F.ini(1<<18);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)++c[0][a[i]];
	for(i=1;i<n;++i)--c[1][min(a[i],a[i+1])];
	for(i=1;i<=n;++i)--c[2][a[i]];
	for(i=1;i<n;++i)++c[3][min(a[i],a[i+1])];
	for(i=1;i<=n;++i)++c[4][a[i]];
	for(i=1;i<n;++i)--c[5][max(a[i],a[i+1])];
	for(i=1;i<=n;++i)--c[6][a[i]];
	for(i=1;i<n;++i)++c[7][max(a[i],a[i+1])];
	for(i=1;i<=m;++i)scanf("%d",b+i);
	for(i=1;i<=m;++i)++d[0][b[i]];
	for(i=1;i<m;++i)++d[2][min(b[i],b[i+1])];
	for(i=1;i<=m;++i)++d[1][b[i]];
	for(i=1;i<m;++i)++d[3][min(b[i],b[i+1])];
	for(i=1;i<=m;++i)++d[4][b[i]];
	for(i=1;i<m;++i)++d[6][max(b[i],b[i+1])];
	for(i=1;i<=m;++i)++d[5][b[i]];
	for(i=1;i<m;++i)++d[7][max(b[i],b[i+1])];
	for(i=0;i<4;++i){
		mul(c[i],d[i],cc);
	}
		for(j=N-2;j>=0;--j)cc[j]+=cc[j+1];
	for(;i<8;++i){
		mul(c[i],d[i],dd);
	}
		for(j=1;j<N;++j)dd[j]+=dd[j-1];
	for(;q--;){
		scanf("%d",&x);
		printf("%lld\n",cc[x]-dd[x-1]);
	}
}