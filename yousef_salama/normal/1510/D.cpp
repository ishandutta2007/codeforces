#include <bits/stdc++.h>

using namespace std;

const int N=1e5+5;

int lg[1005];
int arr[N];
long long mem[N][10][2];
vector<int> ans;
int n,d;

long long go(int ind,int rem,int got)
{
	//cout << ind <<" " << rem << " " << got << endl;
	if(ind==n)
		return (rem==d&&got?0:-(1LL<<60));
	long long &ret=mem[ind][rem][got];
	if(ret!=-1) return ret;
	ret=max(go(ind+1,rem,got),lg[arr[ind]]+go(ind+1,(rem*arr[ind])%10,1));
	return ret;
}

void build(int ind,int rem,int got)
{
	if(ind==n) return;
	if(go(ind,rem,got)==go(ind+1,rem,got))
	{
		build(ind+1,rem,got); return;
	}
	ans.push_back(arr[ind]);
	build(ind+1,(rem*arr[ind])%10,1);
}

int main()
{
	for(int i=1;i<=1000;i++)
	{
		lg[i]=log(i)*1000000;
	}
	scanf("%d %d",&n,&d);
	for(int i=0;i<n;i++)
		scanf("%d",&arr[i]);
	memset(mem,-1,sizeof mem);
	long long v=go(0,1,0);
	if(v<0)
	{
		puts("-1");
		return 0;
	}
	build(0,1,0);
	printf("%d\n",(int)ans.size());
	for(int i:ans)
		printf("%d ",i);
	puts("");
}