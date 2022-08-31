#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <functional>
#include <string>
#include <set>
#include <map>
#define SIZE 200005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

char str[SIZE];
int back[SIZE];
bool use[SIZE];

int main()
{
	scanf("%s",&str);
	int n=strlen(str);
	queue <int> one,zero;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='0')
		{
			if(one.empty()) back[i]=-1;
			else
			{
				int v=one.front();one.pop();
				back[i]=v;
			}
			zero.push(i);
		}
		else
		{
			if(zero.empty())
			{
				puts("-1");
				return 0;
			}
			int v=zero.front();zero.pop();
			back[i]=v;
			one.push(i);
		}
	}
	if(!one.empty())
	{
		puts("-1");
		return 0;
	}
	vector < vector <int> > ans;
	while(!zero.empty())
	{
		int v=zero.front();zero.pop();
		vector <int> vec;
		while(v>=0)
		{
			vec.push_back(v);
			v=back[v];
		}
		ans.push_back(vec);
	}
	printf("%d\n",ans.size());
	for(int i=0;i<ans.size();i++)
	{
		vector <int> vec=ans[i];
		printf("%d",vec.size());
		for(int j=0;j<vec.size();j++)
		{
			printf(" %d",vec[vec.size()-j-1]+1);
		}puts("");
	}
	return 0;
}