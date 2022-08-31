#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <cmath>
#define SIZE 105

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE],cnt[SIZE];
int tp[SIZE][SIZE],back[SIZE][SIZE];
int L[SIZE][SIZE];
vector <int> vx;

int main()
{
	int n,T;
	scanf("%d %d",&n,&T);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		vx.push_back(A[i]);
	}
	sort(vx.begin(),vx.end());
	vx.erase(unique(vx.begin(),vx.end()),vx.end());
	for(int i=0;i<n;i++)
	{
		A[i]=lower_bound(vx.begin(),vx.end(),A[i])-vx.begin();
		cnt[A[i]]++;
	}
	for(int i=0;i<n;i++)
	{
		memset(L[i],0,sizeof(L[i]));
		for(int j=0;j<i;j++) L[i][j]=-1;
		for(int j=0;j<n;j++)
		{
			int mx=-1;
			for(int k=0;k<=A[j];k++) mx=max(mx,L[i][k]);
			if(mx>=0) L[i][A[j]]=mx+1;
		}
		for(int j=1;j<n;j++) L[i][j]=max(L[i][j],L[i][j-1]);
	}
	memset(tp,0,sizeof(tp));
	memset(back,0,sizeof(back));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			for(int k=j;k<n;k++)
			{
				tp[i+1][k]=max(tp[i+1][k],tp[i][j]+L[j][k]);
				back[i+1][j]=max(back[i+1][j],back[i][k]+L[j][k]);
			}
		}
	}
	int mx=0;
	for(int i=0;i<n;i++)
	{
		int l=min(n,T);
		int sum=tp[l][i];
		int zan=min(n,T-l);
		sum+=back[zan][i];
		mx=max(mx,sum+cnt[i]*(T-l-zan));
	}
	printf("%d\n",mx);
	return 0;
}