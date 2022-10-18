#include <cstdio>
#include <vector>
#include <algorithm>
#define pb push_back
//#include "checker.cpp"
using std::vector;
const int N=405;
int n, m;
int qry(int u, int d)
{
	int x;
	printf("? %d %d\n", u, d);
	fflush(stdout);
	scanf("%d", &x);
	return x;
}
int ok[N], ad[N], pos[N], res, lst;
int solve(vector<int> v0, vector<int> v1)
{
	if(v0.size()+v1.size()==1)
	{
		return v0.size()?v0[0]:(qry(v1[0], -1), v1[0]);
	}
	int v=qry(0, -1);
	qry(0, 1);
	if(v>=lst)
	{
		v1.clear();
		int mid=(v0.size()+1)/2;
		for(int i=mid; i<v0.size(); ++i) v1.pb(v0[i]), lst=qry(v0[i], 1);
		v0.resize(mid);
		return solve(v0, v1);
	}
	else
	{
		for(int x:v0) ++ad[x];
		v0.clear();
		int mid=(v1.size()+1)/2;
		for(int i=mid; i<v1.size(); ++i) v0.pb(v1[i]), lst=qry(v1[i], -1);
		v1.resize(mid);
		return solve(v0, v1);
	}
}
int main()
{
	scanf("%d%d", &n, &m);
	int pr1=qry(0, 1), pr=qry(0, 1), cur=qry(0, 1), p=3, len=n*m;
	res=n-1;
	while(res)
	{
		while(pr<=pr1||pr<cur) pr1=pr, pr=cur, cur=qry(0, 1), ++p, p%=len;
		--p;
		p=(p+len)%len;
		cur=qry(0, -1);
		lst=cur;
		vector<int> v0, v1;
		for(int i=1; i<n; ++i) if(!ok[i]) v1.pb(i);
		int x=solve(v0, v1);
		--res;
		ok[x]=1;
		ad[x]=0;
		for(int i=1; i<=m; ++i) qry(x, -1);
		pos[x]=(p-(m+1)+len)%len;
		pr=qry(0, -1);
		pr1=qry(0, -1);
		qry(0, 1);
		cur=qry(0, 1);
	}
	for(int i=1; i<n; ++i) pos[i]=(pos[i]-p+len)%len;
	printf("! ");
	for(int i=1; i<n; ++i) printf("%d ", pos[i]);
	return 0;
}