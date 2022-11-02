#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cctype>
#include<cstring>
#include<vector>
#include<list>
#include<deque>
#include<queue>
#include<stack>
#include<string>
#include<utility>
using namespace std;
int n,c,a[110]={},ans=0;
int main()
{	
	cin>>n>>c;
	for(int i=1;i<=n;++i)
		cin>>a[i];
	for(int i=1;i<n;++i)
		ans=max(a[i]-a[i+1],ans);
	if(ans-c>=0)
		cout<<ans-c<<endl;
	else
		cout<<0<<endl;
	return 0;
}