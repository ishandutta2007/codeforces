#include<bits/stdc++.h>
using namespace std;
const int sg[]={0,1,2,1,4,3,2,1,5,6,2,1,8,7,5,9,8,7,3,4,7,4,2,1,10,9,3,6,11,12,14};
int main()
{
	int n,tot=0;
	cin>>n;
	set<int> s;
	for(int i=2;i*i<=n;++i)
	{
		if(s.count(i))
			continue;
		long long x=i;
		int t=0;
		while(x<=n)
		{
			s.insert(x);
			++t;
			x*=i;
		}
		//cout<<"i="<<i<<" t="<<t<<" sg[t]="<<sg[t]<<endl;
		tot^=sg[t];
	}
	//cout<<s.size()<<endl;
	tot^=(n-s.size())%2;
	//cout<<"tot="<<tot<<endl;
	puts(tot ? "Vasya" : "Petya");
	return 0;
}