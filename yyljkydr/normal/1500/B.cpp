#include<bits/stdc++.h>
using namespace std;

#define int long long

const int N=3e6+1e3+7;

int n,m,a[N],b[N];

int k;

int ex_gcd(int a, int b, int& x, int& y) {
  if (b == 0) {
    x = 1;
    y = 0;
    return a;
  }
  int d = ex_gcd(b, a % b, x, y);
  int temp = x;
  x = y;
  y = temp - a / b * y;
  return d;
}
bool liEu(int a, int b, int c, int& x, int& y) {
  int d = ex_gcd(a, b, x, y);
  if (c % d != 0) return 0;
  int k = c / d;
  x *= k;
  y *= k;
  return 1;
}

int pos[N];

vector<int>v;

signed main()
{
	scanf("%lld%lld",&n,&m);
	memset(pos,-1,sizeof(pos));
	scanf("%lld",&k);
	for(int i=0;i<n;i++)
		scanf("%lld",&a[i]),pos[a[i]]=i;
	for(int i=0;i<m;i++)
		scanf("%lld",&b[i]);
	int R=n*m/__gcd(n,m);
	for(int j=0;j<m;j++)
	{
		if(pos[b[j]]!=-1)
		{
			int i=pos[b[j]];
			int a,b;
			bool ok=liEu(n,m,j-i,a,b);
			int tmp=m/__gcd(n,m);
			a=(a%R+R)%R;
			if(!ok)
				continue;
			int p=(a*n+i)%R;
			assert(p%m==j);
			v.push_back(p);
		}
	}
	int l=-1,r=1e18;
	while(r-l>1)
	{
		int mid=(l+r)>>1;
		int totw=(mid+1)/R*v.size();
		int res=(mid+1)%R;
		if(res)
		{
			res--;
			for(int j=0;j<v.size();j++)
				if(v[j]<=res)
					totw++;
		}
		int tot=mid+1-totw;
		if(tot>=k)
			r=mid;
		else
			l=mid;
	}
	printf("%lld\n",r+1);
}