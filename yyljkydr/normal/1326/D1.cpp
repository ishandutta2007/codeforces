#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int N=1e6+1e2+7;

int T,n;

char s[N];

struct HS{
	ll bs,P;
	ll L[N],R[N]; 
	ll b[N];
	void pre()
	{
		b[0]=1;
		for(int i=1;i<=n;i++)
			b[i]=b[i-1]*bs%P;
		for(int i=1;i<=n;i++)
			L[i]=(L[i-1]*bs%P+s[i])%P;
		R[n+1]=0;
		for(int i=n;i>=1;i--)
			R[i]=(R[i+1]*bs%P+s[i])%P;
	}
	
	ll gtl(int l,int r)
	{
		return (L[r]-L[l-1]*b[r-l+1]%P+P)%P;
	}
	
	ll gtr(int l,int r)
	{
		return (R[l]-R[r+1]*b[r-l+1]%P+P)%P;
	}
	
	bool pd(int l,int r)
	{
		ll HL=(1ll*gtl(1,l-1)*b[n-r]%P+gtl(r+1,n))%P;
		ll HR=(1ll*gtr(1,l-1)+gtr(r+1,n)*b[l-1]%P)%P;
		return HL==HR;
	}
	
	bool isp(int l,int r)
	{
		return gtl(l,r)==gtr(l,r);
	}
}h[2];

int al,ar;

bool chk(int x)
{
	for(int i=1;i<=n-x+1;i++)
	{
		if(h[0].pd(i,i+x-1)&&h[1].pd(i,i+x-1))
		{
			al=i,ar=i+x-1;
			return 1;
		}
	}
	return 0;
} 

int main()
{
	scanf("%d",&T);
	while(T--)
	{
		h[0].bs=13131,h[1].bs=1313131;
		h[0].P=1e9+7,h[1].P=998244353;
		scanf("%s",s+1);
		n=strlen(s+1);
		h[0].pre(),h[1].pre();
		if(h[0].L[n]==h[0].R[1]&&h[1].L[n]==h[1].R[1])
		{
			puts(s+1);
			continue;
		}
		int len;
		int ans=0;
		for(int i=1;i<=n/2;i++)
		{
			if(h[0].L[i]==h[0].R[n-i+1]&&h[1].L[i]==h[1].R[n-i+1])
				continue;
			else
			{
				len=i-1;
				break;
			}
		}
		for(int i=len+1;i<=n-len;i++)
		{
			int LL=i-len,RL=n-len+1-i;
			if(h[0].isp(len+1,i)&&h[1].isp(len+1,i))
				if(i+len>ans)
					ans=i+len,al=i,ar=n-len+1;
			if(h[0].isp(i,n-len)&&h[1].isp(i,n-len))
				if(n-i+1+len>ans)
					ans=n-i+1+len,al=len,ar=i;
		}
		for(int i=1;i<=al;i++)
			putchar(s[i]);
		for(int i=ar;i<=n;i++)
			putchar(s[i]);
		puts("");
	}
}