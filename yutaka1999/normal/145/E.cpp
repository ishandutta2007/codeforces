#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
#define SIZE 1024*1024

using namespace std;

struct segtree
{
	int f[SIZE*2],s[SIZE*2],fs[SIZE*2],sf[SIZE*2];
	bool add[SIZE*2];
	int n,mum;
	
	void init(int m)
	{
		n=m;
		mum=1;
		while(mum<n) mum<<=1;
		memset(f,0,sizeof(f));
		memset(s,0,sizeof(s));
		memset(fs,0,sizeof(fs));
		memset(sf,0,sizeof(sf));
		memset(add,false,sizeof(add));
	}
	void in(int k,int x)
	{
		k+=mum-1;
		if(x==7)
		{
			s[k]=1;
			sf[k]=1;
		}
		else
		{
			f[k]=1;
			fs[k]=1;
		}
	}
	void make(int k)
	{
		int l=k*2+1,r=k*2+2;
		f[k]=f[l]+f[r];
		s[k]=s[l]+s[r];
		fs[k]=max(f[l]+max(fs[r],s[r]),fs[l]+s[r]);
		sf[k]=max(s[l]+max(sf[r],f[r]),sf[l]+f[r]);
	}
	void maketree()
	{
		for(int i=mum-2;i>=0;i--) make(i);
	}
	void flip(int k)
	{
		swap(s[k],f[k]);
		swap(fs[k],sf[k]);
		add[k]=!add[k];
	}
	void tell(int k)
	{
		if(add[k])
		{
			flip(k*2+1);
			flip(k*2+2);
			add[k]=false;
		}
	}
	void updata(int a,int b,int k,int l,int r)
	{
		if(r<=a||b<=l) return;
		if(a<=l&&r<=b) flip(k);
		else
		{
			tell(k);
			updata(a,b,k*2+1,l,(l+r)/2);
			updata(a,b,k*2+2,(l+r)/2,r);
			make(k);
		}
	}
	void updata(int a,int b)
	{
		updata(a,b,0,0,mum);
	}
	void see()
	{
		for(int i=0;i<mum+n-1;i++)
		{
			printf("[%d]%d %d %d %d\n",i,s[i],f[i],sf[i],fs[i]);
		}
	}
	int len()
	{
		//printf("%d %d %d\n",s[0],f[0],fs[0]);
		return max(max(s[0],f[0]),fs[0]);
	}
};
segtree seg;
char str[SIZE];
char op[10];

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",&str);
	seg.init(n);
	for(int i=0;i<n;i++) seg.in(i,str[i]-'0');
	seg.maketree();
	//seg.see();
	for(int i=0;i<m;i++)
	{
		scanf("%s",&op);
		if(op[0]=='s')
		{
			int a,b;
			scanf("%d %d",&a,&b);a--;b--;
			seg.updata(a,b+1);
			//seg.see();
		}
		else
		{
			printf("%d\n",seg.len());
		}
	}
	return 0;
}