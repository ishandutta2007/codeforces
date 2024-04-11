#include<bits/stdc++.h>
#define maxn 100050
#define modu 1000000007
using namespace std;
typedef long long LL;

LL x,y;

int n;
int L[maxn],R[maxn];

int pos[maxn];

void init()
{
	scanf("%d%lld%lld",&n,&x,&y);
	for (int i=0;i<n;++i)
		scanf("%d%d",&L[i],&R[i]),pos[i]=i;
}

bool cmp(int i,int j)
{
	return L[i]<L[j];
}

priority_queue<int> D;
priority_queue<int,vector<int>,greater<int> > T;

void solve()
{
	LL ans=0;
	sort(pos,pos+n,cmp);
	for (int k=0;k<n;++k)
	{
		int i=pos[k];
//		cout<<"["<<L[i]<<","<<R[i]<<"]"<<endl;
		while (T.size()&&T.top()<L[i])
			D.push(T.top()),T.pop();
		if (D.size()&&y*(L[i]-D.top())<x)
			ans+=y*(R[i]-D.top()),D.pop();
		else
			ans+=x+y*(R[i]-L[i]);
		
		T.push(R[i]);
		ans%=modu;
	}
	printf("%lld\n",ans);
}

int main()
{
	init();
	solve();
	return 0;
}