#include<bits/stdc++.h>
using namespace std;
const int K=110;
int n,k;
vector<int> u,v;
queue<int> leaf;
void construct()
{
	while(leaf.size()%k)
	{
		int s=leaf.front();
		leaf.pop();
		for(int i=1;i<k;++i)
		{
			u.push_back(s),v.push_back(++n);
			leaf.push(n);
		}
	}
	int a[K]={};
	while(leaf.size())
	{
		for(int i=1;i<=k;++i)
		{
			a[i]=leaf.front();
			leaf.pop();
		}
		for(int i=1;i<=k;++i)
			for(int j=i+1;j<=k;++j)
				u.push_back(a[i]),v.push_back(a[j]);
	}
}
int main()
{
	cin>>k;
	if(k==1)
	{
		puts("YES");
		puts("2 1");
		puts("1 2");
		return 0;
	}
	if(k%2==0)
	{
		puts("NO");
		return 0;
	}
	n=k+1;
	for(int i=2;i<=k+1;++i)
		u.push_back(1),v.push_back(i);
	leaf.push(2);
	if(k%2==0)
		leaf.push(3);
	construct();
	for(int i=3+!(k%2);i<=k+1;++i)
		leaf.push(i);
	construct();
	puts("YES");
	printf("%d %u\n",n,u.size());
	for(int i=0;i<(int)u.size();++i)
		printf("%d %d\n",u[i],v[i]);
	return 0;
}