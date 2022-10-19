#include<cstdio>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;

const int N=1e6+1e3+7;

int n,a[N];

char s[N];

priority_queue<pair<int,int> >p1;

priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >p2;



int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),p2.push(make_pair(a[i],i));
	scanf("%s",s+1);
	for(int i=1;i<=n*2;i++)
	{
		int v=s[i]-'0';
		if(v==0)
		{
			pair<int,int> x=p2.top();
			p2.pop();
			printf("%d ",x.second);
			p1.push(x); 
		}
		else
		{
			pair<int,int> x=p1.top();
			p1.pop();
			printf("%d ",x.second);
		}
	}
}