#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <ctime>
#define SIZE 1500005

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct UF
{
	int par[SIZE];
	
	void init(int n)
	{
		for(int i=0;i<n;i++)
		{
			par[i]=i;
		}
	}
	int find(int x)
	{
		if(par[x]==x) return x;
		return par[x]=find(par[x]);
	}
	void unite(int x,int y)
	{
		x=find(x);
		y=find(y);
		if(x==y) return;
		if(x>y) swap(x,y);
		par[y]=x;
	}
	bool same(int x,int y)
	{
		return find(x)==find(y);
	}
}uf;
vector <int> vx[SIZE];
int A[SIZE],to[SIZE];
int B[SIZE];
int st[SIZE];
int ord[SIZE];
int n;

void make_rand()
{
	queue <int> que;
	for(int i=0;i<n;i++) que.push(i);
	int sz=0;
	for(int i=0;i<2*n-1;i++)
	{
		if(que.empty()||(sz>=2&&rand()%3==0)) sz--;
		else st[sz++]=que.front(),que.pop();
		A[i]=st[sz-1];
	}
	for(int i=0;i<n;i++) ord[i]=i;
	random_shuffle(ord,ord+n);
	for(int i=0;i<2*n-1;i++) A[i]=ord[A[i]];
	for(int i=0;i<2*n-1;i++)
	{
		if(rand()%2==0) A[i]=-1;
	}
}
bool solve(vector <int> vec)//in case vec[0]=vec[vec.size()-1]
{
	//for(int i=0;i<vec.size();i++) printf("%d ",vec[i]);puts("");
	int sz=0;
	for(int i=1;i+1<vec.size();i++)
	{
		if(vec[i]>=n)
		{
			if(sz>0&&st[sz-1]<n)
			{
				sz--;
				int tg=sz>=1?st[sz-1]:vec[0];
				uf.unite(tg,vec[i]);
			}
			else
			{
				st[sz++]=vec[i];
			}
		}
		else
		{
			if(sz>0&&st[sz-1]>=n)
			{
				int tg=vec[i+1];
				uf.unite(st[sz-1],tg);
				sz--;
			}
			else
			{
				st[sz++]=vec[i];
			}
		}
	}
	if(sz>1&&st[0]<n) return false;
	while(sz>=3)
	{
		uf.unite(st[sz-1],st[sz-3]);
		sz-=2;
	}
	return true;
}
/* 
hack
20
0 1 5 0 6 18 0 11 7 0 7 0 13 10 0 0 0 0 0 0 9 2 0 20 0 0 4 15 3 20 0 0 0 11 12 18 0 17 5
*/
int main()
{
	scanf("%d",&n);
	if(n==1)
	{
		puts("yes");
		puts("1");
		return 0;
	}
	int sft=-1;
	int nm=n;
	uf.init(3*n+1);
	
	/*srand((unsigned) time(NULL));
	make_rand();
	for(int i=0;i<2*n-1;i++) printf("%d ",A[i]+1);puts("");
	for(int i=0;i<2*n-1;i++)
	{
		if(A[i]<0) A[i]=nm++;
		else sft=i;
	}*/
	for(int i=0;i<2*n-1;i++)
	{
		scanf("%d",&A[i]);
		A[i]--;
		if(A[i]<0) A[i]=nm++;
		else sft=i;
	}
	if(sft==-1)
	{
		puts("yes");
		for(int i=0;i<2*n-1;i++)
		{
			if(i%2==0) printf("%d ",1);
			else printf("%d ",i/2+2);
		}puts("");
		return 0;
	}
	if(A[0]!=A[2*n-2]&&A[0]<n&&A[2*n-2]<n)
	{
		puts("no");
		return 0;
	}
	if(A[2*n-2]<n) A[0]=A[2*n-2],sft=0;
	uf.unite(A[0],A[2*n-2]);
	for(int i=0;i<2*n-1;i++)
	{
		B[i]=A[(i+sft)%(2*n-2)];
	}
	for(int i=0;i<2*n-1;i++) A[i]=B[i];
	//for(int i=0;i<2*n-1;i++) printf("%d ",A[i]);puts("");
	for(int i=0;i<2*n-1;i++) vx[A[i]].push_back(i);
	memset(to,-1,sizeof(to));
	for(int i=0;i<2*n-1;i++) to[i]=vx[A[i]][vx[A[i]].size()-1];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<vx[i].size();j++)
		{
			if(vx[i][j]%2!=vx[i][0]%2)
			{
				puts("no");
				return 0;
			}
		}
	}
	for(int i=2*n-2;i>=0;i--)
	{
		if(A[i]<n&&vx[A[i]][0]==i&&vx[A[i]].size()>=2)
		{
			//printf("%d\n",i);
			for(int k=0;k+1<vx[A[i]].size();k++)
			{
				int s=vx[A[i]][k],t=vx[A[i]][k+1];
				vector <int> vec;
				for(int j=s;j<=t;j++)
				{
					vec.push_back(A[j]);
					if(A[j]!=A[i])
					{
						j=to[j];
						if(j>t)
						{
							puts("no");
							return 0;
						}
					}
				}
				if(!solve(vec))
				{
					puts("no");
					return 0;
				}
			}
		}
	}
	//for(int i=0;i<2*n-1;i++) printf("%d ",uf.find(A[i]));puts("");
	for(int i=0;i<2*n-1;i++) B[i]=A[i];
	for(int i=0;i<2*n-2;i++)
	{
		A[(i+sft)%(2*n-2)]=B[i];
	}A[2*n-2]=A[0];
	queue <int> que;
	for(int i=0;i<n;i++) if(vx[i].empty()) que.push(i);
	//for(int i=0;i<n;i++) if(vx[i].empty()) printf("* %d\n",i);
	for(int i=0;i<2*n-1;i++)
	{
		if(uf.find(A[i])>=n)
		{
			int z=que.front();que.pop();
			uf.unite(A[i],z);
		}
		A[i]=uf.find(A[i]);
	}
	puts("yes");
	for(int i=0;i<2*n-1;i++) printf("%d ",A[i]+1);
	puts("");
	return 0;
}