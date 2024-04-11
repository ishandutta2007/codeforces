#include<bits/stdc++.h>
using namespace std;

int n,mx,cnt,gc;
vector<int>num;

inline int ask(int u,bool v)
{
	int res;
	cnt++;
	if(!v) printf("> %d\n",u);
	else printf("? %d\n",u);
	fflush(stdout);
	scanf("%d",&res);
	return res;
}

inline int get()
{
	int l,r,mid;
	for(l=0,r=1000000001;l<r;)
	{
		mid=((l+r)>>1);
		if(ask(mid,0)) l=mid+1;
		else r=mid;
	}
	return l;
}

inline int gcd(int u,int v)
{
	for(;u&&v&&u!=v;)
	{
		swap(u,v);
		u%=v;
	}
	return max(u,v);
}

int main()
{
	srand(517);
	int i,j;
	cin>>n;
	mx=get();
	for(i=cnt+1;i<=60;i++)
	{
		num.push_back(ask(rand()*rand()%n+1,1));
	}
	sort(num.begin(),num.end());
	for(i=1;i<num.size();i++)
	{
		gc=gcd(gc,num[i]-num[i-1]);
	}
	cout<<"! "<<mx-(n-1)*gc<<' '<<gc;
}