#include<bits/stdc++.h>
using namespace std;

const int N=1e5+1e3+7;

int n,p[N],q;

set<int>s;

multiset<int>ms;

void ins(int x)
{
	auto it=s.lower_bound(x);
	int p=-1,q=-1;
	if(it!=s.end())
	{
		q=*it;
		ms.insert(q-x);
	}
	if(it!=s.begin())
	{
		it--;
		p=*it;
		ms.insert(x-p);
	}
	s.insert(x);
	if(p!=-1&&q!=-1)
		ms.erase(ms.find(q-p));
}

void del(int x)
{
	s.erase(x);
	auto it=s.lower_bound(x);
	int p=-1,q=-1;
	if(it!=s.end())
	{
		q=*it;
		ms.erase(ms.find(q-x));
	}
	if(it!=s.begin())
	{
		it--;
		p=*it;
		ms.erase(ms.find(x-p));
	}
	if(p!=-1&&q!=-1)
		ms.insert(q-p);
}

int ask()
{
	if(!s.size())
		return 0;
	if(!ms.size())
		return *s.rbegin()-*s.begin();
	return *s.rbegin()-*s.begin()-*ms.rbegin();
}

int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&p[i]),ins(p[i]);
	printf("%d\n",ask());
	while(q--)
	{
		int op,x;
		scanf("%d%d",&op,&x);
		if(!op)
			del(x);
		else
			ins(x);
		printf("%d\n",ask());
	}
}