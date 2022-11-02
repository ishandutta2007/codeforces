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
int a,b,ans=0,t=0;
int main()
{	
	cin>>a>>b;
	ans=a+a/(b-1);
	if(a%(b-1)==0)
		--ans;
	cout<<ans<<endl;
	return 0;
}