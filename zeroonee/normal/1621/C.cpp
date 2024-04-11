#include <bits/stdc++.h>
using namespace std;
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e4+2;
int f[N];
int a[N],b[N],c[N];
int n;
int ask(int p)
{
	cout<<"? "<<p<<endl;
	int ans;
//ans=b[p];
//for (int i=1;i<=n;i++) c[i]=b[a[i]];
//for (int i=1;i<=n;i++) b[i]=c[i];
//return ans;
	cin>>ans;
	return ans;
}
void out(int *f,int n)
{
	cout<<"!";int i;
	for (i=1;i<=n;i++) cout<<' '<<f[i];cout<<endl;
}
int main()
{
	ios::sync_with_stdio(0);
	int T;cin>>T;
	while (T--)
	{
		int i,j;
		cin>>n;

//for (i=1;i<=n;i++) cin>>a[i],b[i]=i;

		memset(f+1,0,n*sizeof f[0]);
		for (i=1;i<=n;i++) if (!f[i])
		{
			vector<int> a;
			int x=ask(i);
			a.push_back(x);
			while (1)
			{
				int x=ask(i);
				if (x==a[0]) break;
				a.push_back(x);
			}
			for (j=1;j<a.size();j++) f[a[j-1]]=a[j];
			f[a.back()]=a[0];
		}
		out(f,n);
	}
}