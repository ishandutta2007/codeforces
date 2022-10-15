#include<bits/stdc++.h>
typedef double db;
using namespace std;
int read()
{
	int ret=0;bool f=0;char c=getchar();
	while(c>'9'||c<'0')f|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9')ret=(ret<<3)+(ret<<1)+(c^48),c=getchar();
	return f?-ret:ret;
}
const int maxn=3e3+5;
const double pi=acos(-1.0);
int n;
int ans;
db R;
struct point
{
	db x,y;
	friend double dis(const point &a,const point &b){return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));}
}p[maxn];
bool valid[maxn][maxn];
void work(const point &now,bool ret[],int id)
{
	static pair<double,int>dif[maxn<<2];
	static int top;
	top=0;
	int sum=0;
	sum++;dif[++top]={-pi,1};dif[++top]={pi,-1};
	for(int i=1;i<=n;i++)
	{
		if(dis(now,p[i])<=R)continue;
		double mid=atan2(p[i].y-now.y,p[i].x-now.x);
		double del=asin(R/dis(now,p[i]));
		double l=mid-del,r=mid+del;
		sum++;
		if(l<-pi)
		{
			dif[++top]={l+2*pi,1};
			dif[++top]={-pi,1};
			dif[++top]={r,-1};
		}
		else if(r>pi)
		{
			dif[++top]={-pi,1};
			dif[++top]={r-2*pi,-1};
			dif[++top]={l,1};
		}
		else
		{
			dif[++top]={l,1};
			dif[++top]={r,-1};
		}
	}
	sort(dif+1,dif+top+1);
	vector<pair<double,double>>uni;uni.clear();int val=0;
	for(int i=1;i<=top;i++)
	{
		val+=dif[i].second;
		if(val>=sum&&fabs(dif[i].first-dif[i+1].first)>1e-6)uni.push_back({dif[i].first,dif[i+1].first});
	}
	for(int i=1;i<=n;i++)
	{
		double theta=atan2(p[i].y-now.y,p[i].x-now.x);
		bool flag=0;
		for(auto &j:uni)if(theta>=j.first&&theta<=j.second||fabs(theta-j.first)<1e-6||fabs(theta-j.second)<1e-6){flag=1;break;}
		if(flag)ret[i]=1;
	}
}
int main()
{
	n=read();R=read();
	for(int i=1;i<=n;i++)p[i].x=read(),p[i].y=read();
	for(int i=1;i<=n;i++)work(p[i],valid[i],i);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)if(valid[i][j]&&valid[j][i])ans++;
	printf("%d\n",ans);
	return 0;
}