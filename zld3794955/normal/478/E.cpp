#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<ctime>
#include<vector>
using namespace std;
const long long D=10000000;
const int UP=0,DOWN=1,Bit=7,AT=840000;
typedef vector<int>::iterator iter;
typedef pair<iter,iter> seg;
struct mod_compare
{
	int k;
	mod_compare(long long k_): k(min(D+1,k_)) {}
	bool operator() (int a,int b)
	{
		return a%k<b%k;
	}
};
long long n,k;
int a[AT]={},atot=0,vtot=0;
vector<int> v[10][2];
void tryy(int t,int l,long long s,int c)
{
	if(t>=Bit)
		return;
	if(c==1)
		for(int i=l+1;i<=9;++i)
		{
			a[++atot]=s*10+i;
			tryy(t+1,i,s*10+i,-c);
		}
	else
		for(int i=0;i<=l-1;++i)
		{
			a[++atot]=s*10+i;
			tryy(t+1,i,s*10+i,-c);
		}
}
inline bool search_latter(int former,int d,int c)
{
	long long mod=((n-former*D)%n+n)%n;
	if(mod>D)
		return false;
	int l=d,r=d;
	if(c==UP)
		l=0;
	else
		r=9;
	for(int i=l;i<=r;++i)
	{
		seg s=equal_range(v[i][c].begin(),v[i][c].end(),mod,mod_compare(n));
		int l=s.second-s.first;
		if(k<=l)
		{
			sort(s.first,s.second);
			for(iter it=s.first;it!=s.second;++it)
				if((--k)==0)
				{
					printf("%d%0*d\n",former,Bit,*it);
					return true;
				}
		}
		k-=l;
	}
	return false;
}
bool work()
{
	for(int i=1;i<=9;++i)
	{
		tryy(1,i,i,1);
		tryy(1,i,i,-1);
	}
	sort(a+1,a+atot+1);
	for(int d=1;d<=9;++d)
		if(d%n==0 && (--k)==0)
		{
			printf("%d\n",d);
			return true;
		}
	for(int i=1;i<=atot;++i)
		if(a[i]%n==0 && (--k)==0)
		{
			printf("%d\n",a[i]);
			return true;
		}
	for(int i=1;i<=atot;++i)
	{
		if(a[i]>D/10)
			v[a[i]/(D/10)][a[i]/(D/10) > a[i]/(D/100)%10].push_back(a[i]);
		else if(a[i]>(D/100) && a[i]/(D/100)%10>a[i]/(D/1000)%10)
			v[a[i]/(D/10)][UP].push_back(a[i]);
	}
	for(int d=0;d<=9;++d)
	{
		sort(v[d][UP].begin(),v[d][UP].end(),mod_compare(n));
		sort(v[d][DOWN].begin(),v[d][DOWN].end(),mod_compare(n));
	}
	for(int d=1;d<=9;++d)
	{
		if(search_latter(d,d-1,UP))
			return true;
		if(search_latter(d,d+1,DOWN))
			return true;
	}
	for(int i=1;i<=atot;++i)
	{
		int dir=a[i]%10 < a[i]/10%10;
		if(dir==UP && search_latter(a[i],a[i]%10-1,UP))
			return true;
		if(dir==DOWN && search_latter(a[i],a[i]%10+1,DOWN))
			return true;
	}
	return false;
}
int main()
{	
	scanf("%I64d%I64d",&n,&k);
	//cout<<clock()<<endl;
	if(!work())
		printf("-1\n");
	//cout<<clock()<<endl;
	return 0;
}