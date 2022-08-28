#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <cmath>
#define SIZE 100005
#define MX 30

using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[MX];
char ans[SIZE];
int all;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		all+=A[i];
	}
	int mx=0;
	int NOW=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<A[i];j++)
		{
			ans[NOW++]='a'+i;
		}
	}
	for(int i=1;i<=all;i++)//ST
	{
		if(all%i==0)
		{
			bool ok=true;
			int nm=all/i;
			for(int j=0;j<n;j++)
			{
				if(A[j]%nm!=0)
				{
					ok=false;
					break;
				}
			}
			if(ok)
			{
				if(i==1)
				{
					mx=nm;
					for(int j=0;j<all;j++) ans[j]='a';//Aevf
					break;
				}
				if(all%2==0)
				{
					bool up=true;
					for(int j=0;j<n;j++)
					{
						if(A[j]%(2*nm)!=0)
						{
							up=false;
							break;
						}
					}
					if(up)
					{
						mx=2*nm;
						int l=0,r=i-1;
						for(int j=0;j<n;j++)
						{
							for(int k=0;k<A[j]/(2*nm);k++)
							{
								ans[l]='a'+j;
								ans[r]='a'+j;
								l++,r--;
							}
						}
						for(int j=i;j<all;j++) ans[j]=ans[j-i];
						break;
					}
				}
				else
				{
					int cnt=0,pos=-1;
					for(int j=0;j<n;j++)
					{
						if(A[j]%(2*nm)!=0)
						{
							cnt++;
							pos=j;
						}
					}
					if(cnt==1)
					{
						mx=nm;
						int l=0,r=i-1;
						for(int j=0;j<n;j++)
						{
							if(j==pos) continue;
							for(int k=0;k<A[j]/(2*nm);k++)
							{
								ans[l]='a'+j;
								ans[r]='a'+j;
								l++,r--;
							}
						}
						for(int j=l;j<=r;j++) ans[j]='a'+pos;
						for(int j=i;j<all;j++) ans[j]=ans[j-i];
						break;
					}
				}
			}
		}
	}
	printf("%d\n",mx);
	printf("%s\n",ans);
	return 0;
}