#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int m,n,s[101000]={},l[101000]={},c[101000]={};
int seq[101000]={},top=0;
long long len[101000]={},pos;
inline int find(long long p)
{
	int l=1,r=top;
	while(l!=r)
	{
		int mid=l+r>>1;
		if(p>len[mid])
			l=mid+1;
		else
			r=mid;
	}
	return l;
}
void work()
{
	int p=find(pos);
	while(!(pos==len[p] && seq[p]!=-1))
	{
		//cout<<p<<endl;
		pos=(pos-len[p-1])%l[p];
		if(pos==0)
			pos=l[p];
		p=find(pos);
	}
	printf("%d ",seq[p]);
	return;
}
int main()
{	
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{	
		scanf("%d",&s[i]);
		if(s[i]==1)
		{	
			scanf("%d",&c[i]);
			seq[++top]=c[i];
			len[top]=len[top-1]+1;
		}
		else
		{
			scanf("%d%d",&l[i],&c[i]);
			seq[++top]=-1;
			len[top]=len[top-1]+l[i]*c[i];
		}
	}
	//for(int i=1;i<=top;++i)
	//	cout<<len[i]<<' ';
	//cout<<endl;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{	
		cin>>pos;
		work();
		//cout<<"-------------------"<<endl;
	}
	printf("\n");
	return 0;
}