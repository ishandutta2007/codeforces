#include<bits/stdc++.h>
using namespace std;

const int N=1e2+1e1+7;

typedef pair<int,int> pii;

queue<pair<int,int> >can[2];

int n,ok[4],c[2];

void out(int col,int x,int y)
{
	printf("%d %d %d\n",col,x,y);
	fflush(stdout);
}

int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			can[(i+j)&1].push(pii{i,j});
	int a;
	scanf("%d",&a);
	for(int i=1;i<=3;i++)
		if(a!=i)
		{
			c[0]=i;
			break;
		}
	int x=can[0].front().first,y=can[0].front().second;
	can[0].pop();
	out(c[0],x,y);
	scanf("%d",&a);
	for(int i=1;i<=3;i++)
		if(a!=i&&i!=c[0])
		{
			c[1]=i;
			break;
		}
	x=can[1].front().first,y=can[1].front().second;
	out(c[1],x,y);
	can[1].pop();
	int fin=-1;
	for(int i=3;i<=n*n;i++)
	{
		scanf("%d",&a);
		if(fin==-1)
		{
			int p=a==c[0]?1:0;
			x=can[p].front().first,y=can[p].front().second;
			can[p].pop();
			out(c[p],x,y);
			if(!can[p].size())
				fin=p;
		}
		else
		{
			int col=-1;
			for(int i=1;i<=3;i++)
				if(i!=a&&i!=c[fin])
					col=i;
			int p=fin^1;
			x=can[p].front().first,y=can[p].front().second;
			can[p].pop();
			out(col,x,y);
		}
	}
}