#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
void go(int l,int r)
{
	for(int i=l;i<=r;i++)printf(" %d",i);
}
int ss=0;
void get()
{
	putchar('\n');
	fflush(stdout);
	int x;scanf("%d",&x);
	ss^=x;
}
void solve(int v)
{
	if(m<=v+(n-v)/2)
	{
		int vv=(n-v)/2;
		putchar('?');
		go(1,m-vv);
		go(v+1,v+vv);
		get();
		putchar('?');
		go(1,m-vv);
		go(v+vv+1,n);
		get();
		return ;
	}
	int x=n-m;
	putchar('?');
	go(1,v);
	go(v+1,v+x);
	go(v+x*2+1,n);
	get();
	putchar('?');
	go(1,v);
	go(v+x+1,v+x*2);
	go(v+x*2+1,n);
	get();
	solve(v+x*2);
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n%m==0)
	{
		for(int i=1;i<=n/m;i++)
		{
			putchar('?');
			go((i-1)*m+1,i*m);
			get();
		}
		printf("! %d\n",ss);
		fflush(stdout);
		return 0;
	}
	if(n%2==1&&m%2==0)
	{
		puts("-1");
		fflush(stdout);
		return 0;
	}
	else if(n%2==1&&m%2==1)
	{
		int G=n/m;
		int k=n-G*m;
		if(k%2==1)k+=m,G--;
		for(int i=1;i<=G;i++)
		{
			putchar('?');
			go((i-1)*m+1,i*m);
			get();
		}
		int kk=k/2;
		putchar('?');
		go(1,m-kk);
		go(n-k+1,n-kk);
		get();
		putchar('?');
		go(1,m-kk);
		go(n-kk+1,n);
		get();
	}
	else if(n%2==0&&m%2==0)
	{
		int G=n/m;
		int k=n-G*m;
		if(G>1)k+=m,G--;
		for(int i=1;i<=G;i++)
		{
			putchar('?');
			go((i-1)*m+1,i*m);
			get();
		}
		int kk=k/2;
		putchar('?');
		go(1,m-kk);
		go(n-k+1,n-kk);
		get();
		putchar('?');
		go(1,m-kk);
		go(n-kk+1,n);
		get();
	}
	else if(n%2==0&&m%2==1)
	{
		int G=n/m;
		int k=n-G*m;
		if(G==1)
		{
			k=m*2-n;
			int kk=k/2;
			int p=n-k;
			int pp=p/2;
			solve(0);
		}
		else
		{
			if(k%2==1)k+=m,G--;
			for(int i=1;i<=G;i++)
			{
				putchar('?');
				go((i-1)*m+1,i*m);
				get();
			}
			int kk=k/2;
			putchar('?');
			go(1,m-kk);
			go(n-k+1,n-kk);
			get();
			putchar('?');
			go(1,m-kk);
			go(n-kk+1,n);
			get();
		}
	}
	printf("! %d\n",ss);
	fflush(stdout);
	return 0;
}