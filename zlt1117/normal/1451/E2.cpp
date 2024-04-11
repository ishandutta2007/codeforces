//#pragma GCC optimize(4)
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define REP(u) for(int i=p[u];i!=-1;i=e[i].nxt)
#define PII pair<int,int>
#define ll long long
#define pb push_back
#define rd (rand()<<16^rand())
#define gc getchar()//(_p1==_p2&&(_p2=(_p1=_buf)+fread(_buf,1,100000,stdin),_p1==_p2)?EOF:*_p1++)
using namespace std;
char _buf[100000],*_p1=_buf,*_p2=_buf;
inline int gi()
{
	int x=0,f=1;
	char ch=gc;
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')f=-1;
		ch=gc;
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<3)+(x<<1)+(ch^48);
		ch=gc;
	}
	return (f==1)?x:-x;
}
inline int max(int a,int b){return a>b?a:b;}
inline int min(int a,int b){return a<b?a:b;}
const int maxn=(1<<16)+1;
int n,a[maxn],sum[maxn],now[maxn];
inline void init()
{
	
}
inline void input()
{
//	memset(a,0,sizeof(a));
//	memset(sum,0,sizeof(sum));
//	memset(now,0,sizeof(now));
	scanf("%d",&n);
//	FOR(i,1,n)scanf("%d",&a[i]);
//	n=128;
//	FOR(i,1,n)a[i]=rd%n;
}
inline int query(int typ,int x,int y)
{
	if(typ==1)printf("AND %d %d\n",x,y);
	else if(typ==2)printf("OR %d %d\n",x,y);
	else printf("XOR %d %d\n",x,y);
	int ret;
	fflush(stdout);
	scanf("%d",&ret);
	return ret;
//	x=a[x],y=a[y];
//	if(typ==1)return x&y;
//	else if(typ==2)return x|y;
//	else return x^y;
}
inline void report()
{
	printf("! ");
	FOR(i,1,n)printf("%d ",now[i]);
	fflush(stdout);
//	FOR(i,1,n)if(now[i]!=a[i])
//	{
//		cerr<<"WA"<<endl;
//		FOR(i,1,n)cout<<a[i]<<' ';
//		exit(0);
//	}
}
int vis[maxn];
inline void solve()
{
	FOR(i,1,n-1)
	{
		sum[i]=query(3,i,i+1);
	}
	int pos=0;
	FOR(i,1,n-1)
	{
		if(sum[i]!=0){pos=i+1;break;}
	}
	if(pos==0)
	{
		int now1=query(1,2,3);
		FOR(i,1,n)now[i]=now1;
	}
	else
	{
		int pos2=0;
		int now1=0;
		FOR(i,pos,n-1)
		{
			now1^=sum[i];
			if((now1==0)||(now1==sum[pos-1]))continue;
			else {pos2=i+1;break;}
		}
		if(pos2==0)
		{
			if(pos==2)
			{
				int val=query(2,pos,pos+1);
				now[pos]=val;
				now[pos-1]=sum[1]^val;
				FOR(i,3,n)now[i]=sum[i-1]^now[i-1];
			}
			else
			{
				int val=query(2,1,2);
				now[1]=now[2]=val;
				FOR(i,3,n)now[i]=sum[i-1]^now[i-1];
			}
		}///1 pos pos2
		else
		{
			int pos1=0,pos2=0;
			now[1]=0;
			FOR(i,2,n)now[i]=now[i-1]^sum[i-1];
			FOR(i,1,n)
			{
				if(vis[now[i]])
				{
					pos1=vis[now[i]];
					pos2=i;
					break;
				}
				else vis[now[i]]=i;
			}
			if(pos1)
			{
				now[pos1]=now[pos2]=query(2,pos1,pos2);
				for(int i=pos1-1;i>=1;--i)now[i]=now[i+1]^sum[i];
				FOR(i,pos1,n-1)now[i+1]=now[i]^sum[i];
			}
			else
			{
				int now1=0,now2=0;
				int pos=vis[1],pos2=vis[2];
				FOR(i,1,pos-1)now1^=sum[i];
				FOR(i,1,pos2-1)now2^=sum[i];
				int val2=query(1,1,pos);
				int val3=query(1,1,pos2);
				FOR(i,0,n-1)
				{
					int posv=i^now1;
					int pos2v=i^now2;
					if((i&posv)==val2&&(i&pos2v)==val3)
					{
						now[1]=i;
						break;
					}
				}
				FOR(i,2,n)now[i]=now[i-1]^sum[i-1];
			}
		}
	}
	report();
}
int main()
{
//	srand(time(NULL));
//	while(1)
//	{
		init();
		input();
		solve();
//	}
	return 0;
}///