#include <bits/stdc++.h>
#define SIZE 400005
using namespace std;
typedef long long int ll;
typedef pair <int,int> P;

int A[SIZE];
void solve()
{
	int n;
	scanf("%d",&n);
	int bef=-1,cnt=0;
	vector <int> vec;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&A[i]);
		if(bef!=A[i])
		{
			if(cnt>0) vec.push_back(cnt);
			cnt=0;
			bef=A[i];
		}
		cnt++;
	}
	vec.push_back(cnt);
	int g=vec[0];
	int now=1,sum=0;
	while(now<vec.size()&&sum<=vec[0]) sum+=vec[now++];
	if(sum<=vec[0])
	{
		puts("0 0 0");
		return;
	}
	int s=sum;
	sum=0;
	while(now<vec.size()&&sum<=vec[0]) sum+=vec[now++];
	if(sum<=vec[0]||g+s+sum>n/2)
	{
		puts("0 0 0");
		return;
	}
	while(now<vec.size()&&g+s+sum+vec[now]<=n/2) sum+=vec[now++];
	printf("%d %d %d\n",g,s,sum);
}
	
int main()
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}