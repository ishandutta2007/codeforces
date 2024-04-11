#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
#define SIZE 100005

using namespace std;
typedef pair <int,int> P;

int in[SIZE];
priority_queue <P> que;
int f[SIZE],s[SIZE],t[SIZE];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&in[i]);
	sort(in,in+n);
	in[n]=-SIZE;
	int sum=0,val=-1;
	for(int i=0;i<=n;i++)
	{
		if(val!=in[i])
		{
			if(val!=-1) que.push(P(sum,val));
			sum=1;
			val=in[i];
		}
 		else sum++;
	}
	int sz=0;
	while(que.size()>2)
	{
		P p=que.top();que.pop();
		P q=que.top();que.pop();
		P r=que.top();que.pop();
		int a=p.second,b=q.second,c=r.second;
		if(a<b) swap(a,b);
		if(a<c) swap(a,c);
		if(b<c) swap(b,c);
		f[sz]=a;s[sz]=b;t[sz]=c;sz++;
		p.first--;
		q.first--;
		r.first--;
		if(p.first) que.push(p);
		if(q.first) que.push(q);
		if(r.first) que.push(r);
	}
	printf("%d\n",sz);
	for(int i=0;i<sz;i++) printf("%d %d %d\n",f[i],s[i],t[i]);
	return 0;
}