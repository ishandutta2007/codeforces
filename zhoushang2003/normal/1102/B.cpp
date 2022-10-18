#import<bits/stdc++.h>
using namespace std;
const int N=1e4;
int n,k,x,c[N],v,A[N];
pair<int,int>p[N];
main()
{
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>x,c[x]++,p[i]={x,i},v=max(v,c[x]);
	if(v>k)
		cout<<"NO",exit(0);
	sort(p+1,p+n+1);
	for(int i=1;i<=n;i++)
		A[p[i].second]=i%k+1;
	puts("YES");
	for(int i=1;i<=n;i++)
		cout<<A[i]<<' ';
}