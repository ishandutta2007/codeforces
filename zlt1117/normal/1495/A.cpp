#include<bits/stdc++.h>
using namespace std;
int n;
vector<int>a,b;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		a.clear(),b.clear();
		cin>>n;
		for(int i=1;i<=2*n;++i)
		{
			int x,y;
			cin>>x>>y;
			if(y==0)a.push_back(abs(x));
			if(x==0)b.push_back(abs(y)); 
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		double sum=0;
		int siz=a.size();
		for(int i=0;i<=siz-1;++i)
		{
			long long val=a[i];
			val*=val;
			val+=1ll*b[i]*b[i];
			sum+=sqrt(val);
		}
		printf("%.10lf\n",sum);
	}
	return 0;
}