#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#define SIZE 200005

using namespace std;
typedef pair <int,int> P;
typedef pair <P,int> PP;

int left[SIZE*2],right[SIZE*2];
int A[SIZE],B[SIZE];
int col[SIZE];
priority_queue <PP,vector <PP>,greater <PP> > que;

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d %d",&A[i],&B[i]);
		que.push(PP(P(A[i],B[i]),i));
	}
	memset(col,-1,sizeof(col));
	memset(left,-1,sizeof(left));
	memset(right,-1,sizeof(right));
	int sz=n;
	while(!que.empty())
	{
		PP p=que.top();que.pop();
		if(que.empty())
		{
			col[p.second]=0;
			break;
		}
		PP q=que.top();que.pop();
		if(p.first.second<q.first.first)
		{
			col[p.second]=0;
			que.push(q);
			continue;
		}
		if(p.first.second>q.first.second) swap(p,q);
		if(p.first.second==q.first.second)
		{
			col[p.second]=0;
			col[q.second]=1;
		}
		else
		{
			left[sz]=p.second;
			right[sz]=q.second;
			que.push(PP(P(p.first.second+1,q.first.second),sz++));
		}
	}
	for(int i=sz-1;i>=n;i--)
	{
		col[left[i]]=col[i]^1;
		col[right[i]]=col[i];
	}
	for(int i=0;i<n;i++)
	{
		if(i!=0) printf(" ");
		printf("%d",col[i]);
	}puts("");
	return 0;
}