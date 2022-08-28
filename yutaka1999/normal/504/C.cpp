#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#define SIZE 100005

using namespace std;
typedef long long int ll;

int cnt[SIZE],in[SIZE];
bool ok[SIZE],ok2[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&in[i]);
		in[i]--;
	}
	for(int l=0,r=n-1;l<=r;l++,r--)
	{
		bool v=in[l]==in[r];
		if(l>0) v&=ok[l-1];
		ok[l]=ok[r]=v;
	}
	int m=(n-1)/2;
	for(int l=(n-1)/2,r=n/2;0<=l&&r<n;l--,r++)
	{
		bool v=in[l]==in[r];
		if(l<(n-1)/2) v&=ok2[l+1];
		ok2[l]=ok2[r]=v;
	}
	ll ret=0;
	int Tl=0,Tr=n-1,nz=0;
	for(int l=0,r=n-1;l<r;l++,r--)
	{
		if(cnt[in[r]]==0) nz++;
		cnt[in[r]]++;
		if(cnt[in[r]]==0) nz--;
		if(cnt[in[l]]==0) nz++;
		cnt[in[l]]--;
		if(cnt[in[l]]==0) nz--;
		if(l+1<=r-1&&!ok2[r-1]) continue;
		if(nz>0) continue;
		while(r<Tr)
		{
			if(in[Tl]!=in[Tr]) break;
			Tl++,Tr--;
		}
		ret+=2*(n-Tr);
	}
	memset(cnt,0,sizeof(cnt));
	nz=0;
	int mn=0;
	for(int i=0;i<=(n-1)/2;i++)
	{
		if(cnt[in[i]]==0) mn++;
		cnt[in[i]]--;
	}
	for(int i=(n+1)/2;i<n;i++)
	{
		if(cnt[in[i]]==-1) mn--;
		cnt[in[i]]++;
	}
	for(int i=0;i<n;i++) if(cnt[i]>0&&cnt[i]%2==1) nz++;
	Tl=0,Tr=n-1;
	for(int i=(n-1)/2;i>=0;i--)
	{
		if(Tl<=i)
		{
			if(cnt[in[i]]==-1)
			{
				mn--;
				nz++;
			}
			if(cnt[in[i]]==-2) mn--;
			cnt[in[i]]+=2;
		}
		else
		{
			int r=n-i-1;
			if(cnt[in[i]]==-1) mn--;
			if(cnt[in[i]]>=0&&cnt[in[i]]%2==0) nz++;
			if(cnt[in[i]]>=0&&cnt[in[i]]%2==1) nz--;
			cnt[in[i]]++;
			if(cnt[in[r]]<=0) mn++;
			if(cnt[in[r]]>0&&cnt[in[r]]%2==0) nz++;
			if(cnt[in[r]]>0&&cnt[in[r]]%2==1) nz--;
			cnt[in[r]]--;
		}
		if(mn>0|nz!=n%2) continue;
		while(n/2<Tr)
		{
			if(Tl<i)
			{
				if(in[Tl]!=in[Tr]) break;
				Tl++,Tr--;
			}
			else
			{
				if(cnt[in[Tr]]<2) break;
				cnt[in[Tr]]-=2;
				Tl++,Tr--;
			}
		}
		//printf("%d %d %d\n",i,Tl,Tr);
		ret+=n-Tr;
	}
	printf("%I64d\n",ret);
	return 0;
}