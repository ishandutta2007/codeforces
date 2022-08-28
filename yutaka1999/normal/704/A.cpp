#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <iostream>
#include <string>
#include <cmath>
#define SIZE 300005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

vector <int> all;
vector <int> nd[SIZE];
set <int> zan;

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	int now=0;
	for(int i=0;i<q;i++)
	{
		int tp,x;
		scanf("%d %d",&tp,&x);
		if(tp==1)
		{
			x--;
			nd[x].push_back(i);
			all.push_back(i);
			zan.insert(i);
		}
		else if(tp==2)
		{
			x--;
			for(int j=0;j<nd[x].size();j++) zan.erase(nd[x][j]);
			nd[x].clear();
		}
		else
		{
			while(now<x)
			{
				zan.erase(all[now]);
				now++;
			}
		}
		printf("%d\n",zan.size());
	}
	return 0;
}