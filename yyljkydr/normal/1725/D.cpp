#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define data dataa
#define rep(i,n) for(int i=1;i<=n;i++)
typedef long long LL;
typedef long double LD;
const int N=100010;
struct data
{
	int x,y;
	friend data operator+(data a,data b)
	{
		if(a.y>b.y)swap(a,b);
		b.x<<=b.y-a.y;
		a.x+=b.x;
		for(;!(a.x&1);a.x>>=1,a.y++);
		return a;
	}
	friend bool operator<(data a,data b)
	{
		if(a.y-b.y>30)return 0;
		if(b.y-a.y>30)return 1;
		LL tmp1=a.x,tmp2=b.x;
		if(a.y>b.y)tmp1<<=a.y-b.y;
		else tmp2<<=b.y-a.y;
		return tmp1<tmp2;
	}
	friend bool operator==(data a,data b)
	{
		if(a.y-b.y>30)return 0;
		if(b.y-a.y>30)return 0;
		LL tmp1=a.x,tmp2=b.x;
		if(a.y>b.y)tmp1<<=a.y-b.y;
		else tmp2<<=b.y-a.y;
		return tmp1==tmp2;
	}
}s[N];
LL cal(int x){return (LL)((x+1)/2)*((x+2)/2);}
int d[N],cnt;
data work(int x,int y)
{
	for(;!(x&1);x>>=1,y++);
	// printf("%d %d\n",x,y);
	return {x,y};
}
void prepare(int x)
{
	d[cnt=1]=1;
	int a=1,b=0;
	for(int i=4;i<=x;i++)
	{
		if(i%2==0)a++;else b++;
		int init_pos=cal(i)-1;
		init_pos+=(x-i)/2*(a+b);
		if((x-i)%2)init_pos+=a;
		d[++cnt]=init_pos;
	}
	d[++cnt]=cal(x)+1;
	s[0]={0,0};
	rep(i,cnt-1)s[i]=s[i-1]+work(d[i+1]-d[i],i-1);
	// rep(i,cnt-1)printf("%d %d %d\n",d[i],s[i].x,s[i].y);
}
data getnum(int id)
{
	int pos=upper_bound(d+1,d+cnt+1,id)-d-1;
	return s[pos-1]+work(id-d[pos]+1,pos-1);
}
int getpos(const data&x)
{
	int l=0,r=d[cnt];
	for(;l<r-1;)
	{
		int mid=(l+r)>>1;
		if(x<getnum(mid))r=mid;else l=mid;
	}
	return l;
}
int n,q,p[N],a[N];
int main()
{
	scanf("%d%d",&n,&q);
	rep(i,q)scanf("%d",&p[i]);
	if(n==1)
	{
		rep(i,q+1)puts("1");
		return 0;
	}
	int pos;
	for(int i=1;;i++)if(cal(i)>=n){pos=i;break;}
	prepare(pos-1);
	// printf("%d\n",pos);
	int rest=n-cal(pos-1);
	LL ans1=(LL)pos*rest;
	rep(i,pos-1)ans1+=(cal(i)-cal(i-1))*i;
	printf("%lld\n",ans1);
	int num=0;
	set<pair<int,int>>s;
	for(int i=pos-1;i>=0;i--)
	{
		data tmp=work(pos-i,i);
		if(s.find(mp(tmp.x,tmp.y))!=s.end())continue;
		s.insert(mp(tmp.x,tmp.y));
		int id=getpos(tmp);
		if(getnum(id)==tmp)continue;
		a[++num]=id;
		// printf("* %d\n",i);
		if(num==rest)break;
	}
	reverse(a+1,a+num+1);
	int now=0;
	rep(i,q)
	{
		for(;now<num&&p[i]>=a[now+1]+now+1;now++);
		if(p[i]==a[now]+now)printf("%d\n",pos);
		else
		{
			data tmp=getnum(p[i]-now);
			printf("%d\n",tmp.x+tmp.y);
		}
	}
	return 0;
}