#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005
#define SQR 450

using namespace std;

struct BIT
{
	int bit[SIZE];
	
	void init()
	{
		memset(bit,0,sizeof(bit));
	}
	void add(int k,int x)
	{
		k++;
		while(k<SIZE)
		{
			bit[k]+=x;
			k+=k&-k;
		}
	}
	int get(int k)
	{
		k++;
		int ret=0;
		while(k>0)
		{
			ret+=bit[k];
			k-=k&-k;
		}
		return ret;
	}
};
BIT bit[2*SIZE/SQR+5];
BIT calc[SQR+5];
vector <int> nd[2*SIZE];
int pos[SIZE*2];
int A[SIZE];
int X[SIZE],Y[SIZE],Z[SIZE];
vector <int> vx;
int all[SIZE*2];
int id[2*SIZE];
int n,m,sz;

int get(int x,int y)
{
	int c=A[y];
	if(c<0||c>=vx.size()) return -1;
	if(x==1) return vx[c];
	int nm=0;
	if(id[c]!=-1) nm=bit[id[c]].get(y);
	else
	{
		for(int i=0;i<pos[c];i++)
		{
			if(nd[c][i]==y)
			{
				nm=i+1;
				break;
			}
		}
	}
	if(x%2==0) return nm;
	else
	{
		int ret=nm<=SQR?calc[nm-1].get(y):0;
		//printf("%d %d : %d %d %d\n",c,id[c],nm,y,ret);
		for(int i=0;i<sz;i++) if(bit[i].get(y)>=nm) ret++;
		return ret;
	}
}
int nxt[SQR+5];
void rem(int k)
{
	int c=A[k];
	if(id[c]!=-1) bit[id[c]].add(k,-1);
	else
	{
		int now=0;
		for(int i=0;i<pos[c];i++)
		{
			calc[i].add(nd[c][i],-1);
			if(nd[c][i]!=k)
			{
				calc[now].add(nd[c][i],1);
				nxt[now++]=nd[c][i];
			}
		}
		pos[c]=now;
		for(int i=0;i<now;i++) nd[c][i]=nxt[i];
	}
}
void add(int k)
{
	int c=A[k];
	if(id[c]!=-1) bit[id[c]].add(k,1);
	else
	{
		bool up=true;
		int now=0;
		for(int i=0;i<pos[c];i++)
		{
			calc[i].add(nd[c][i],-1);
			if(up&&nd[c][i]>k)
			{
				calc[now].add(k,1);
				nxt[now++]=k;
				up=false;
			}
			calc[now].add(nd[c][i],1);
			nxt[now++]=nd[c][i];
		}
		if(up)
		{
			calc[now].add(k,1);
			nxt[now++]=k;
		}
		pos[c]=now;
		for(int i=0;i<now;i++) nd[c][i]=nxt[i];
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		vx.push_back(A[i]);
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d %d %d",&X[i],&Y[i],&Z[i]);
		Z[i]--;
		if(X[i]==1) vx.push_back(Y[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
		all[A[i]]++;
	}
	for(int i=0;i<m;i++)
	{
		if(X[i]==1)
		{
			Y[i]=lower_bound(vx.begin(),vx.end(),Y[i])-vx.begin();
			all[Y[i]]++;
		}
	}
	sz=0;
	for(int i=0;i<vx.size();i++)
	{
		if(all[i]>=SQR) id[i]=sz++;
		else
		{
			id[i]=-1;
			nd[i].resize(all[i]+5);
			pos[i]=0;
		}
	}
	for(int i=0;i<n;i++) add(i);
	for(int i=0;i<m;i++)
	{
		if(X[i]==1)
		{
			rem(Z[i]);
			A[Z[i]]=Y[i];
			add(Z[i]);
		}
		else
		{
			printf("%d\n",get(Y[i],Z[i]));
		}
	}
	return 0;
}