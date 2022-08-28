#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 100005

using namespace std;

int in[SIZE];
int to[SIZE];
bool use[SIZE];
int ft[SIZE][6];
int sc[SIZE][6];
int cnt[SIZE];
vector < vector <int> > zan[6];
int nd[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);in[i]--;
		to[in[i]]=i;
	}
	int sz=0;
	for(int i=0;i<n;i++)
	{
		if(!use[i])
		{
			int now=i,s=0;
			do
			{
				use[now]=true;
				nd[s++]=now;
				now=to[now];
			}while(now!=i);
			int f=i;
			for(int j=1;j<s;)
			{
				if(j+3<s)
				{
					ft[sz][0]=f;
					for(int k=j;k<j+4;k++) ft[sz][k-j+1]=nd[k];
					sc[sz][0]=nd[j+3];
					sc[sz][1]=f;
					for(int k=j;k<j+3;k++) sc[sz][k-j+2]=nd[k];
					f=nd[j+3];
					j=j+4;
					cnt[sz]=5;
					sz++;
				}
				else
				{
					int t=1;
					for(int k=j;k<s;k++) t++;
					vector <int> v;
					v.push_back(f);
					for(int k=j;k<s;k++) v.push_back(nd[k]);
					zan[t].push_back(v);
					break;
				}
			}
		}
	}
	int f=min(zan[2].size(),zan[3].size());
	for(int i=0;i<f;i++)
	{
		for(int j=0;j<2;j++) ft[sz][j]=zan[2][i][j];
		for(int j=0;j<3;j++) ft[sz][j+2]=zan[3][i][j];
		sc[sz][1]=ft[sz][0];
		sc[sz][0]=ft[sz][1];
		sc[sz][3]=ft[sz][2];
		sc[sz][4]=ft[sz][3];
		sc[sz][2]=ft[sz][4];
		cnt[sz++]=5;
	}
	for(int i=f;i<zan[2].size();)
	{
		if(i+1<zan[2].size())
		{
			ft[sz][0]=zan[2][i][0];
			ft[sz][1]=zan[2][i][1];
			ft[sz][2]=zan[2][i+1][0];
			ft[sz][3]=zan[2][i+1][1];
			sc[sz][1]=ft[sz][0];
			sc[sz][0]=ft[sz][1];
			sc[sz][3]=ft[sz][2];
			sc[sz][2]=ft[sz][3];
			cnt[sz++]=4;
			i=i+2;
		}
		else
		{
			ft[sz][0]=zan[2][i][0];
			ft[sz][1]=zan[2][i][1];
			sc[sz][1]=ft[sz][0];
			sc[sz][0]=ft[sz][1];
			cnt[sz++]=2;
			break;
		}
	}
	for(int i=f;i<zan[3].size();)
	{
		if(i+2<zan[3].size())
		{
			for(int j=0;j<3;j++) ft[sz][j]=zan[3][i][j];
			sc[sz][1]=ft[sz][0];
			sc[sz][2]=ft[sz][1];
			sc[sz][0]=ft[sz][2];
			ft[sz][3]=zan[3][i+2][0];
			ft[sz][4]=zan[3][i+2][1];
			sc[sz][3]=zan[3][i+2][1];
			sc[sz][4]=zan[3][i+2][0];
			cnt[sz++]=5;
			
			for(int j=0;j<3;j++) ft[sz][j]=zan[3][i+1][j];
			sc[sz][1]=ft[sz][0];
			sc[sz][2]=ft[sz][1];
			sc[sz][0]=ft[sz][2];
			ft[sz][3]=zan[3][i+2][1];
			ft[sz][4]=zan[3][i+2][2];
			sc[sz][3]=zan[3][i+2][2];
			sc[sz][4]=zan[3][i+2][1];
			cnt[sz++]=5;
			i=i+3;
		}
		else
		{
			for(int j=0;j<3;j++) ft[sz][j]=zan[3][i][j];
			sc[sz][1]=ft[sz][0];
			sc[sz][2]=ft[sz][1];
			sc[sz][0]=ft[sz][2];
			cnt[sz++]=3;
			i=i+1;
		}
	}
	for(int i=0;i<zan[4].size();i++)
	{
		for(int j=0;j<4;j++) ft[sz][j]=zan[4][i][j];
		sc[sz][1]=ft[sz][0];
		sc[sz][2]=ft[sz][1];
		sc[sz][3]=ft[sz][2];
		sc[sz][0]=ft[sz][3];
		cnt[sz++]=4;
	}
	printf("%d\n",sz);
	for(int i=0;i<sz;i++)
	{
		printf("%d\n",cnt[i]);
		for(int j=0;j<cnt[i];j++)
		{
			if(j!=0) printf(" ");
			printf("%d",ft[i][j]+1);
		}puts("");
		for(int j=0;j<cnt[i];j++)
		{
			if(j!=0) printf(" ");
			printf("%d",sc[i][j]+1);
		}puts("");
	}
	return 0;
}