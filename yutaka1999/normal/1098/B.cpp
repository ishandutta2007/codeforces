#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <string>
#include <set>
#include <map>
#include <cmath>
#include <cassert>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <string> ans;
char str[SIZE];
int col[SIZE];
int ord[4],memo[4];
int n,m;

int ctoi(char c)
{
	if(c=='A') return 0;
	if(c=='C') return 1;
	if(c=='G') return 2;
	return 3;
}
char itoc(int d)
{
	if(d==0) return 'A';
	if(d==1) return 'C';
	if(d==2) return 'G';
	return 'T';
}
int solve(vector <string> mp)
{
	int ret=n*m;
	for(int t=0;t<4;t++) ord[t]=t;
	do
	{
		int sum=0;
		for(int x=0;x<n;x++)
		{
			int a=0,b=0;
			for(int y=0;y<m;y++)
			{
				int c=ctoi(mp[x][y]);
				if(ord[c]%2!=x%2) a++,b++;
				else
				{
					if(ord[c]/2!=y%2) a++;
					else b++;
				}
			}
			sum+=min(a,b);
		}
		if(ret>sum)
		{
			ret=sum;
			for(int t=0;t<4;t++) memo[t]=ord[t];
		}
	}while(next_permutation(ord,ord+4));
	for(int t=0;t<4;t++) ord[t]=memo[t];
	for(int t=0;t<4;t++) memo[ord[t]]=t;
	for(int x=0;x<n;x++)
	{
		int a=0,b=0;
		for(int y=0;y<m;y++)
		{
			int c=ctoi(mp[x][y]);
			if(ord[c]%2!=x%2) a++,b++;
			else
			{
				if(ord[c]/2!=y%2) a++;
				else b++;
			}
		}
		if(a>=b)
		{
			string now="";
			for(int y=0;y<m;y++)
			{
				now+=itoc(memo[x%2+(1-y%2)*2]);
			}
			ans.push_back(now);
		}
		else
		{
			string now="";
			for(int y=0;y<m;y++)
			{
				now+=itoc(memo[x%2+(y%2)*2]);
			}
			ans.push_back(now);
		}
	}
	return ret;
}
int main()
{
	scanf("%d %d",&n,&m);
	vector <string> mp;
	for(int i=0;i<n;i++)
	{
		scanf("%s",&str);
		string S=str;
		mp.push_back(S);
	}
	int ret=solve(mp);
	vector <string> now=ans;
	ans.clear();
	vector <string> mp2;
	for(int i=0;i<m;i++)
	{
		string S="";
		for(int j=0;j<n;j++) S+=mp[j][i];
		mp2.push_back(S);
	}
	swap(n,m);
	int t=solve(mp2);
	swap(n,m);
	if(ret>t)
	{
		now.clear();
		for(int i=0;i<n;i++)
		{
			string S="";
			for(int j=0;j<m;j++) S+=ans[j][i];
			now.push_back(S);
		}
	}
	for(int i=0;i<n;i++) printf("%s\n",now[i].c_str());
	return 0;
}