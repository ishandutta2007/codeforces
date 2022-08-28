#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
#define SIZE 100005
#define ALP 30

using namespace std;

int rt[ALP][SIZE];
char str[SIZE];
bool use[SIZE];

int get(int s,int t,int c)
{
	return rt[c][t]-(s==0?0:rt[c][s-1]);
}
int main()
{
	int m;
	scanf("%d",&m);
	scanf("%s",&str);
	int n=strlen(str);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<ALP;j++)
		{
			if(i==0) rt[j][i]=0;
			else rt[j][i]=rt[j][i-1];
		}
		rt[str[i]-'a'][i]++;
	}
	int mn=0;
	for(int i=0;i+m<=n;i++)
	{
		for(int j=0;j<ALP;j++)
		{
			if(get(i,i+m-1,j)>0)
			{
				mn=max(mn,j);
				break;
			}
		}
	}
	for(int i=0;i<n;i++) if(str[i]-'a'<mn) use[i]=true;
	vector <int> start;
	for(int i=0;i+m<=n;i++)
	{
		for(int j=0;j<ALP;j++)
		{
			if(get(i,i+m-1,j)>0)
			{
				if(j==mn) start.push_back(i);
				break;
			}
		}
	}
	vector <int> nd;
	for(int i=0;i<n;i++)
	{
		if(str[i]-'a'==mn)
		{
			nd.push_back(i);
		}
	}
	int now=-1;
	for(int i=0;i<start.size();i++)
	{
		int L=start[i],R=start[i]+m-1;
		if(now>=0&&L<=nd[now]) continue;
		now++;
		while(now<nd.size()&&nd[now]<=R) now++;
		now--;
		use[nd[now]]=true;
	}
	string ret="";
	for(int i=0;i<ALP;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(use[j]&&str[j]-'a'==i)
			{
				ret+=str[j];
			}
		}
	}
	printf("%s\n",ret.c_str());
	return 0;
}