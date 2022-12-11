#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
int n,cnt=0,l[55],r[55],x[55],al,ll[55],rr[55],xx[55],bg,lim,rv=0,tot=0;
vector<int>opt;
vector<int>ans[55];
int main()
{
	scanf("%d",&n);al=n;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x[i]);
		l[i]=r[i]=i;
	}
	while(al>1)
	{
		tag:;
		if(al==1)break;
		//for(int i=1;i<=al;i++)printf("!%d %d %d\n",x[i],l[i],r[i]);
		//printf("@");
		for(int i=1;i<al;i++)
		{
			if(x[i]+1==x[i+1])
			{
				r[i]=r[i+1];
				for(int j=i+2;j<=al;j++)
				{
					l[j-1]=l[j];
					r[j-1]=r[j];
					if(x[j]>x[i])x[j-1]=x[j]-1;
					else x[j-1]=x[j];
				}
				for(int j=1;j<i;j++)if(x[j]>x[i])x[j]--;
				al--;
				//printf("@");
				goto tag;
			}
		}
		//printf("#");
		opt.clear();
		if(x[1]!=1)
		{
			opt.push_back(1);
			int i;
			for(i=2;i<=al&&x[i]!=x[1]-1;i++);
			opt.push_back(i);
			if(i+1<=al)opt.push_back(i+1);
		}
		else
		{
			opt.push_back(1);
			opt.push_back(2);
			int i;
			for(i=3;i<=al&&x[i]!=x[2]-1;i++);
			opt.push_back(i);
			if(i+1<=al)opt.push_back(i+1);
		}
		cnt++;
		for(int i=0;i<opt.size();i++)
		{
			if(i+1<opt.size())ans[cnt].push_back(l[opt[i+1]]-l[opt[i]]);
			else ans[cnt].push_back(n+1-l[opt[i]]);
		}
		rv=0;tot=0;
		for(int i=opt.size()-1;i>=0;i--)
		{
			bg=opt[i];
			if(i+1<opt.size())lim=opt[i+1];
			else lim=al+1;
			for(int j=bg;j<lim;j++)
			{
				rv++;
				ll[rv]=tot+1;
				rr[rv]=tot+r[j]-l[j]+1;
				tot+=r[j]-l[j]+1;
				xx[rv]=x[j];
			}
		}
		for(int i=1;i<=al;i++)x[i]=xx[i],l[i]=ll[i],r[i]=rr[i];
	}
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;i++)
	{
		printf("%d ",(int)ans[i].size());
		for(int j=0;j+1<ans[i].size();j++)printf("%d ",ans[i][j]);
		printf("%d\n",ans[i].back());
	}
	return 0;
}