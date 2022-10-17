#include<bits/stdc++.h>
#define ll long long
#define N 150000
#define M 998244353
using namespace std;

ll n,m,x,y,z,er,si,tmp,A[N],B[N],C[N],ans[N];

inline ll po(ll u,ll v)
{
    ll res=1;
    for(;v;)
    {
	if(v&1) res=res*u%M;
	u=u*u%M;
	v>>=1;
    }
    return res;
}

inline void fwt(ll *a,bool dft)
{
    ll i,j,k,x,y;
    for(i=1;i<(1 << m);i<<=1)
    {
	for(j=0;j<(1 << m);j+=(i<<1))
	{
	    for(k=j;k<i+j;k++)
	    {
		x=a[k],y=a[k+i];
		a[k]=(x+y)%M;
		a[k+i]=(M+x-y)%M;
		if(!dft)
		{
		    a[k]=a[k]*er%M;
		    a[k+i]=a[k+i]*er%M;
		}
	    }
	}
    }
}

int main()
{
    er=(M+1)/2,si=po(4,M-2);
    ll i,j,a,b,c,d;
    cin>>n>>m>>x>>y>>z;
    for(i=1;i<=n;i++)
    {
	scanf("%lld%lld%lld",&a,&b,&c);
	tmp^=a,A[a^b]++,B[a^c]++,C[b^c]++;
    }
//    cerr<<" "<<tmp<<endl;
    fwt(A,1),fwt(B,1),fwt(C,1);
    for(i=0;i<(1 << m);i++)
    {
	a=(n+A[i]+B[i]+C[i])*si%M;
	b=(n+A[i]-B[i]-C[i])*si%M;
	c=(n-A[i]+B[i]-C[i])*si%M;
	d=(n-A[i]-B[i]+C[i])*si%M;
	a=(a+M)%M,b=(b+M)%M,c=(c+M)%M,d=(d+M)%M;
//	if((a+b+c+d)%M!=n) puts("gg");
//	if((a+b-c-d+M+M)%M!=A[i]) puts("gg");
//	if((a-b+c-d+M+M)%M!=B[i]) puts("gg");
//	if((a-b-c+d+M+M)%M!=C[i]) puts("gg");
//	cerr<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
	ans[i]=po(x+y+z,a)*po(x+y-z,b)%M*po(x-y+z,c)%M*po(x-y-z,d)%M;
	ans[i]=(ans[i]+M)%M;
//	cerr<<" "<<ans[i]<<endl;
    }
    fwt(ans,0);
    for(i=0;i<(1 << m);i++) printf("%lld ",ans[i^tmp]);
}