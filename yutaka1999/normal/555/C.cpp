#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <map>
#include <set>
#include <cmath>
#define SIZE 200005
#define BT 256*1024*2

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

struct segtree
{
	int seg[BT];
	int mum;
	
	void init(int n)
	{
		mum=1;
		while(mum<n) mum<<=1;
		for(int i=0;i<mum*2;i++) seg[i]=0;
	}
	void update(int a,int b,int k,int l,int r,int v)
	{
		if(b<=l||r<=a) return;
		if(a<=l&&r<=b) seg[k]=max(seg[k],v);
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,v);
			update(a,b,k*2+2,(l+r)/2,r,v);
		}
	}
	void update(int a,int b,int k)
	{
		update(a,b,0,0,mum,k);
	}
 	int get(int k)
	{
		k+=mum-1;
		int ret=seg[k];
		while(k>0)
		{
			k=(k-1)/2;
			ret=max(ret,seg[k]);
		}
		return ret;
	}
};
segtree up,left;
int X[SIZE],Y[SIZE];
int d[SIZE];
char str[10];
vector <int> vx,vy;

int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %s",&X[i],&Y[i],&str);
		if(str[0]=='U') d[i]=0;
		else d[i]=1;
		vx.push_back(X[i]);
		vy.push_back(Y[i]);
	}
	vx.push_back(0);
	vy.push_back(0);
	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	vy.erase(unique(vy.begin(),vy.end()),vy.end());
	up.init(vx.size()+2);
	left.init(vy.size()+2);
	for(int i=0;i<q;i++)
	{
		X[i]=lower_bound(vx.begin(),vx.end(),X[i])-vx.begin();
		Y[i]=lower_bound(vy.begin(),vy.end(),Y[i])-vy.begin();
		//printf("%d %d\n",X[i],Y[i]);
		if(d[i]==0)
		{
			int gt=up.get(X[i]);
			//printf("gt %d\n",gt);
			printf("%d\n",vy[Y[i]]-vy[gt]);
			left.update(gt,Y[i]+1,X[i]);
			up.update(X[i],X[i]+1,Y[i]);
		}
		else
		{
			int gt=left.get(Y[i]);
			//printf("gt %d\n",gt);
			printf("%d\n",vx[X[i]]-vx[gt]);
			up.update(gt,X[i]+1,Y[i]);
			left.update(Y[i],Y[i]+1,X[i]);
		}
	}
	return 0;
}