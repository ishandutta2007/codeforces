#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
vector<int> a[110000];
int Ans[110000];
int cnt[110000];
int main()
{
	int t;scanf("%d",&t);
	while(t--)
	{
		int n,m;scanf("%d%d",&n,&m);
		for(int i=1;i<=n;i++)cnt[i]=0;
		for(int i=1;i<=m;i++)
		{
			Ans[i]=0;
			int k;scanf("%d",&k);
			a[i].resize(k);
			for(int j=0;j<k;j++)
			{
				scanf("%d",&a[i][j]);
				cnt[a[i][j]]++;
			}
		}
		int x=0;
		for(int i=1;i<=n;i++)
		{
			if(cnt[i]>(m+1)/2){x=i;break;}
		}
		if(x==0)
		{
			puts("YES");
			for(int i=1;i<m;i++)printf("%d ",a[i][0]);
			printf("%d\n",a[m][0]);
		}
		else
		{
			int ss=(m+1)/2;
			for(int i=1;i<=m;i++)
			{
				if(a[i].size()==1&&a[i][0]==x){Ans[i]=x;ss--;}
			}
			if(ss<0)puts("NO");
			else
			{
				puts("YES");
				for(int i=1;i<=m;i++)
				{
					if(ss==0)break;
					if(Ans[i]==0)
					{
						for(int j=0;j<a[i].size();j++)
						{
							if(a[i][j]==x){Ans[i]=x;ss--;break;}
						}
					}
				}
				for(int i=1;i<=m;i++)
				{
					if(Ans[i]==0)
					{
						if(a[i][0]==x)Ans[i]=a[i][1];
						else Ans[i]=a[i][0];
					}
				}
				for(int i=1;i<m;i++)printf("%d ",Ans[i]);
				printf("%d\n",Ans[m]);
			}
		}
	}
	return 0;
}