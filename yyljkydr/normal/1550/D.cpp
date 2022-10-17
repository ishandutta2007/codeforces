#include<bits/stdc++.h>
using namespace std;

const int N=2e5+1e3+7,P=1e9+7;
 
#define int long long
 
int fac[N],inv[N];
 
int qpow(int a,int b)
{
	int ret=1;
	while(b)
	{
		if(b&1)
			ret=ret*a%P;
		b>>=1;
		a=a*a%P;
	}
	return ret;
}
 
void pre(int n)
{
	fac[0]=1;
	for(int i=1;i<=n;i++)
		fac[i]=fac[i-1]*i%P;
	inv[n]=qpow(fac[n],P-2);
	for(int i=n-1;i>=0;i--)
		inv[i]=inv[i+1]*(i+1)%P;
}
 
int C(int n,int m)
{
	if(n<m||n<0||m<0)
		return 0;
	return fac[n]*inv[m]%P*inv[n-m]%P;
}

typedef pair<int,int> pii;
#define fs first
#define sd second
#define mp make_pair

map<int,pii>c;

map<int,int>d;

int T;

int n,l,r;

pii operator +(pii a,pii b)
{
    return mp(a.fs+b.fs,a.sd+b.sd);
}

int solve(int t)
{
    int f1=0,f2=0,last=1;
    int tf=0;
    int ret=0;
    auto it=d.begin();
    for(auto [x,y]:c)
    {
        int L=t-(f1-tf),R=t+f2-n;
        if(x-1>0&&f1+f2-tf==n)
            ret=(ret+(x-last)*C(tf,L)%P)%P;
        if(x-1>0)
            last=x;
        // if(x>0)
        f1+=y.fs,f2+=y.sd;
        while(it!=d.end()&&it->fs<=x)
            tf+=it->sd,it++;
    }
    return ret;
}

signed main()
{
    scanf("%lld",&T);
    while(T--)
    {
        c.clear();
        d.clear();
        scanf("%lld%lld%lld",&n,&l,&r);
        pre(n);
        for(int i=1;i<=n;i++)
        {
            c[l-i]=c[l-i]+mp(1,0);
            c[r-i+1]=c[r-i+1]+mp(-1,0);
            c[i-r]=c[i-r]+mp(0,1);
            c[i-l+1]=c[i-l+1]+mp(0,-1);
            if(max(l-i,i-r)<=min(r-i,i-l))
                d[max(l-i,i-r)]++,d[min(r-i,i-l)+1]--;
        }
        if(n%2==0)
            printf("%lld\n",solve(n/2));
        else
            printf("%lld\n",(solve(n/2)+solve(n/2+1))%P);
    }
}