#include<bits/stdc++.h>
using namespace std;
const int N=1000005;
typedef long long ll;
int n,L,l,r,m,i,x,y,mi;
ll a[N],b[N];
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>L;
	for(i=1;i<=n;++i)cin>>a[i],a[i+n]=a[i]+L,a[i+n*2]=a[i]+L*2ll,a[i+n*3]=a[i]+L*3ll;
	for(i=1;i<=n;++i)cin>>b[i],b[i+n]=b[i]+L,b[i+n*2]=b[i]+L*2ll,b[i+n*3]=b[i]+L*3ll;
	sort(a+1,a+n*4+1);
	sort(b+1,b+n*4+1);
	for(l=0,r=L;l<r;){
		m=(l+r)>>1;
		bool fl=1;
		x=y=0;
		for(;x<n*3 && b[x+1]<a[n+1]-m;++x);
		for(;y<n*3 && b[y+1]<=a[n+1]+m;++y);
		if(y-x<1)fl=0;
		static ll q[N];
		static int id[N];
		int add=0;
		int t=1,w=1;
		q[1]=y-x-1;id[1]=n+1;
		for(i=n+2;i<=n*3 && fl;++i){
			int cnt=0,lsty=y;
			for(;x<n*4 && b[x+1]<a[i]-m;++x);
			for(;y<n*4 && b[y+1]<=a[i]+m;++y)++cnt;
			if(y-x<1 || x>lsty)fl=0;
				else{
					if(i-id[t]>=n)++t;
					add+=cnt-1;
					for(;t<=w && q[w]+add>y-x-1;--w);
					q[++w]=y-x-1-add;id[w]=i;
					if(q[t]+add<0)
						fl=0;
				}
		}
		
		if(fl)r=m;else l=m+1;
	}
	cout<<l<<'\n';
	return 0;
}