#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;

const int N=205;

vector< pair<int,int> > v;
int n;
int mem[N][N];
int cmp(int x,int y)
{
	if(mem[x][y]!=-1) return mem[x][y];
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char c;
	scanf(" %c",&c);
	mem[x][y]=(c=='<');
	mem[y][x]=!mem[x][y];
	return mem[x][y];
}

int cmpp(pair<int,int> a,pair<int,int> b)
{
	return cmp(a.S,b.S);
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			for(int j=1;j<=2*n;j++)
				mem[i][j]=-1;
		v.clear();
		for(int i=1;i<=2*n;i+=2)
		{
			pair<int,int> cur={i,i+1};
			if(cmp(i,i+1)) swap(cur.F,cur.S);
			v.push_back(cur);
		}
		sort(v.begin(),v.end(),cmpp);
		/*for(int i=0;i<v.size();i++)
			cout << v[i].F << " " << v[i].S << endl;*/
		int del=0;
		for(int i=0;del<n;i++)
		{
			del++;
			if(del==n) break;
			bool vv=cmp(v[i].F,v[i+1].S);
			del++;
			if(del==n) break;
			if(!vv)
			{
				v[i+1].S=v[i].F;
				if(!cmp(v[i+1].S,v[i+1].F)) swap(v[i+1].S,v[i+1].F);
				sort(v.begin()+i+1,v.end(),cmpp);
			}
		}
		puts("!");
		fflush(stdout);
	}
}