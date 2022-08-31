#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>
#define SIZE 300005

using namespace std;
typedef long long int ll;

set <int> st;
multiset <int> len;
set <int>::iterator it;
multiset <int>::iterator its;
ll diff[SIZE];
int A[SIZE];
int n;

void add(int k)
{
	it=st.lower_bound(k);
	int tp=*it;it--;
	int dn=*it;
	its=len.lower_bound(tp-dn);
	len.erase(its);
	len.insert(k-dn);
	len.insert(tp-k);
	st.insert(k);
}
void rem(int k)
{
	st.erase(k);
	it=st.lower_bound(k);
	int tp=*it;it--;
	int dn=*it;
	its=len.lower_bound(k-dn);
	len.erase(its);
	its=len.lower_bound(tp-k);
	len.erase(its);
	len.insert(tp-dn);
}
void rt1(int k)
{
	if(1<=k&&k+1<n)
	{
		if(diff[k-1]==0||diff[k]==0||(diff[k-1]>0&&diff[k]<0)) rem(k);
	}
}
void rt2(int k)
{
	if(1<=k&&k+1<n)
	{
		if(diff[k-1]==0||diff[k]==0||(diff[k-1]>0&&diff[k]<0)) add(k);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	st.insert(0);
	st.insert(n-1);
	len.insert(n-1);
	for(int i=0;i<n-1;i++) diff[i]=A[i]-A[i+1];
	for(int i=0;i<n-2;i++) rt2(i+1);
	int m;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int l,r,d;
		scanf("%d %d %d",&l,&r,&d);l--,r--;
		//for(it=st.begin();it!=st.end();it++) printf("%d ",*it);puts("");
		if(l>0)
		{
			rt1(l-1);
			rt1(l);
			diff[l-1]-=d;
			rt2(l-1);
			rt2(l);
		}
		if(r+1<n)
		{
			rt1(r);
			rt1(r+1);
			diff[r]+=d;
			rt2(r);
			rt2(r+1);
		}
		its=len.end();its--;
		printf("%d\n",(*its)+1);
	}
	return 0;
}