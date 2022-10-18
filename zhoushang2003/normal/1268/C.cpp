#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
const int N=2e5+1;
long long n,a[N],p[N],t,A;
tree<long long,null_type,less<long long>,rb_tree_tag,tree_order_statistics_node_update>s;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i],p[a[i]]=i;
	for(int i=1;i<=n;i++)
	{
		t=s.order_of_key(p[i]),A+=max(0ll,i-2*t-1);
		if(t>(i-1)/2)
			A+=p[i]-*s.find_by_order((i-1)/2)+(i-1)/2-t;
		if(t<i/2)
			A+=*s.find_by_order(i/2-1)-p[i]+t-i/2;
		s.insert(p[i]);
		cout<<A<<' ';
	}
	return 0;
}