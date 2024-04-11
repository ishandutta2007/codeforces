#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#define SIZE 200005

using namespace std;
typedef long long int ll;

int A[SIZE];
int len[SIZE],len2[SIZE];
ll mx[SIZE],mx2[SIZE];
ll gt[SIZE];
int n;

ll get(int s,int t)
{
	return gt[t]-(s==0?0:gt[s-1]);
}
bool check(int x,int pos)//[pos] , x>=1
{
	ll s1=get(pos-x,pos)+get(n-x,n-1);
	ll s2=get(pos-(x-1),pos)+get(n-(x-1),n-1);
	//s1/(2*x+1)s2/(2*x-1)
	if(s1*(ll) (2*x-1)>s2*(ll) (2*x+1)) return true;
	return false;
}
bool check2(int x,int pos)//[pos,pos+1] , x>=2
{
	ll s1=get(pos-x+1,pos+1)+get(n-x+1,n-1);
	ll s2=get(pos-x+2,pos+1)+get(n-x+2,n-1);
	//s1/(2*x)s2/(2*x-2)
	if(s1*(ll) (2*x-2)>s2*(ll) (2*x)) return true;
	return false;
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	sort(A,A+n);
	for(int i=0;i<n;i++)
	{
		gt[i]=A[i];
		if(i>0) gt[i]+=gt[i-1];
	}
	ll a=0,b=1;//a/b
	int pos=-1,tp=-1;
	for(int i=0;i<n;i++)//odd size
	{
		int l=0,r=min(i,n-1-i)+1;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(check(m,i)) l=m;
			else r=m;
		}
		len[i]=l;
		mx[i]=get(i-l,i)+get(n-l,n-1)-(ll) A[i]*(ll) (2*len[i]+1);
		//a/bmx[i]/(2*len[i]+1)
		if(a*(ll) (2*len[i]+1)<=mx[i]*(ll) b)
		{
			pos=i;
			tp=0;
			a=mx[i];
			b=2*len[i]+1;
		}
	}
	for(int i=0;i+1<n;i++)//even size -> Al
	{
		int l=1,r=min(i+1,n-i)+1;
		while(l+1<r)
		{
			int m=(l+r)/2;
			if(check2(m,i)) l=m;
			else r=m;
		}
		len2[i]=l;
		mx2[i]=get(i-l+1,i+1)+get(n-l+1,n-1)-(ll) (A[i]+A[i+1])*(ll) len2[i];
		//a/bmx2[i]/(2*len2[i])
		if(a*(ll) (2*len2[i])<=mx2[i]*(ll) b)
		{
			pos=i;
			tp=1;
			a=mx2[i];
			b=2*len2[i];
		}
	}
	printf("%lld\n",b);
	vector <int> ans;
	if(tp==0)
	{
		for(int i=pos-len[pos];i<=pos;i++) ans.push_back(A[i]);
		for(int i=n-len[pos];i<n;i++) ans.push_back(A[i]);
	}
	else
	{
		for(int i=pos-len2[pos]+1;i<=pos+1;i++) ans.push_back(A[i]);
		for(int i=n-len2[pos]+1;i<n;i++) ans.push_back(A[i]);
	}
	for(int i=0;i<ans.size();i++)
	{
		if(i!=0) printf(" ");
		printf("%d",ans[i]);
	}puts("");
	return 0;
}