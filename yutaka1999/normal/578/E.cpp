#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 100005

using namespace std;
typedef pair <int,vector <int> > PV;

char str[SIZE];
int n;

PV solve(int t)
{
	set <int> st[2];
	set <int>::iterator it;
	for(int i=0;i<n;i++)
	{
		if(str[i]=='L') st[0].insert(i);
		else st[1].insert(i);
	}
	int last=0,cnt=0;
	vector <int> ret;
	for(int i=0;i<n;i++)
	{
		if(st[t].empty()) return PV(SIZE,ret);
		it=st[t].lower_bound(last);
		if(it==st[t].end())
		{
			it=st[t].begin();
			cnt++;
		}
		last=(*it)+1;
		ret.push_back(last);
		st[t].erase(it);
		if(!st[1-t].empty()&&!st[t].empty())
		{
			it=st[1-t].lower_bound(last);
			if(it!=st[1-t].end())
			{
				int v=*it;
				it=st[t].lower_bound(v);
				if(it==st[t].end())
				{
					int f=*(st[t].begin());
					int s=*(st[1-t].begin());
					if(s<f)
					{
						last=0;
						cnt++;
					}
				}
			}
		}
		t=1-t;
	}
	return PV(cnt,ret);
}
int main()
{
	scanf("%s",&str);
	n=strlen(str);
	PV ret=min(solve(0),solve(1));
	printf("%d\n",ret.first);
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ret.second[i]);
	}puts("");
	return 0;
}