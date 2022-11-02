#include<bits/stdc++.h>
using namespace std;
const int N=200020,Inf=1<<30;
struct people
{
	int x,v,pos;
}p[N]={};
bool cmp(const people &p1,const people &p2)
{
	return p1.v>p2.v;
}
int n,ans[N]={};
int main()
{
	scanf("%d",&n);
	for(int i=n;i>=1;--i)
		scanf("%d",&p[i].x);
	for(int i=1;i<=n;++i)
		p[i].v=p[i].x-i+1,p[i].pos=i;
	sort(p+1,p+n+1,cmp);
	//for(int i=1;i<=n;++i)
	//	cout<<p[i].x<<' '<<p[i].v<<' '<<p[i].pos<<endl;
	for(int i=1;i<=n;++i)
		ans[i]=p[i].x+i-p[i].pos;
	for(int i=1;i<n;++i)
		if(ans[i]<ans[i+1])
		{
			puts(":(");
			return 0;
		}
	for(int i=n;i>=1;--i)
		printf("%d%c",ans[i]," \n"[i==1]);
	return 0;
}