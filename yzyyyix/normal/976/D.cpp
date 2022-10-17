#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define N 310
using namespace std;

int n,num[N],cnt,last,tot;
vector<int>a,b;

inline void cz(bool u,int v)
{
	if(!u) return;
	int i,j;
	cnt++;
	for(i=v+1;i<=tot;i++)
	{
		a.push_back(v);
		b.push_back(i);
	}
}

inline bool cmp(int u,int v){return u>v;}

int main()
{
	int i,j,l,r;
	cin>>n;
	for(i=1;i<=n;i++)
		scanf("%d",&num[i]);
	sort(num+1,num+n+1,cmp);
	tot=num[1]+1;
	for(i=1,l=1,r=n;i<=tot&&l<=r;i++)
	{
		if(cnt+tot-i==num[l])
		{
			l++;
			cz(1,i);
			last=1;
		}
		else if(cnt==num[r])
		{
			r--;
			cz(0,i);
			last=0;
		}
		else cz(last,i);
	}
	for(;i<=tot;i++) cz(last,i);
	cout<<a.size()<<endl;
	for(i=0;i<a.size();i++)
	{
		printf("%d %d\n",a[i],b[i]);
	}
}