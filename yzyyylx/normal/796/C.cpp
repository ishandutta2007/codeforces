#include<bits/stdc++.h>
#define ll long long
#define N 300000
#define M 1000000001
using namespace std;

ll n,first[N+5],num[N+5],bb=0,mm,mx,mm2,z=-M,K=0;
struct bian
{
	ll to,next;
}bn[N*2];

void add(ll p,ll q)
{
	bb++;
	bn[bb].to=q;
	bn[bb].next=first[p];
	first[p]=bb;
}

int ss(ll p)
{
	ll i=0,q,o;
	o=p;
	p=first[p];
	while(p!=-1)
	{
		if(num[bn[p].to]==z)
		{
			q=bn[p].to;
			i++;
		}
		p=bn[p].next;
	}
	if(i==mm2-1)
	return o;
	else if(i==1&&K==0)
	{
		K=1;
		return ss(q);
	}
	else
	return 0;
}

int ss2(int p)
{
	ll i=0,q;
	p=first[p];
	while(p!=-1)
	{
		if(num[bn[p].to]==z-1)
		{
			i++;
		}
		p=bn[p].next;
	}
	if(i==mm)
	return 1;
	else
	return 0;
}

int dd(int p)//:-------.. 
{
	int u,i,v;
	u=first[p];
	while(u!=-1)
	{
		v=first[bn[u].to];
		i=0;
		while(v!=-1)
		{
			if(num[bn[v].to]==z) i++;
			v=bn[v].next;
		}
		if(i!=1)
		{
			if(i==mm2)
			return 1;
			else
			return 0;
		}
		u=bn[u].next;
	}
	return 0;
}

int main()
{
	ll i,j,p,q,mn=M,y,u,v;
	cin>>n;
	memset(first,-1,sizeof(first));
	for(i=1;i<=n;i++)
	{
		cin>>num[i];
		z=max(z,num[i]);//z 
	}
	for(i=1;i<=n-1;i++)
	{
		cin>>p>>q;
		add(p,q);
		add(q,p);
	}
	for(i=1;i<=n;i++)
	{
		if(num[i]==z-1)
		{
			mm++;// 
		}
		if(num[i]==z)
		{
			mm2++;// 
			mx=i;// 
		}
	}

	if(mm2==1)// 
	{
		i=mm;
		j=first[mx];
		while(j!=-1)
		{
			if(num[bn[j].to]==z-1) i--;// 
			j=bn[j].next;
		}
		if(i==0)// 
		{
			cout<<z;
			return 0;
		}
		else
		{
			cout<<z+1;
			return 0;
		}
	}	
	
	else if(mm2==2)
	{
		int pp=0;
		u=first[mx];
		while(u!=-1)
		{
			if(num[bn[u].to]==z)
			{
				pp=1;
//				cout<<u<<bn[u].to;
				v=bn[u].to;
				break;
			}
			u=bn[u].next;
		}
		if(pp==0)// 
		{
			pp=dd(mx);
			if(pp==0) 
			{
				cout<<z+2;
			}
			else
			{
				cout<<z+1;
			}
			return 0;
		}
		else//z+1,-12z+1  
		{
			cout<<z+1;
			return 0;
		}
	}
	
	else if(mm2>2)
	{
		i=mm2;
		y=ss(mx);//
		if(y==0)//
		{ 
			if(dd(mx)==0)
			{
				cout<<z+2;
			}
			else
			{
				cout<<z+1;
			}
			return 0;
		}
		else// 
		{
			cout<<z+1;
			return 0;			
		}
	}
}