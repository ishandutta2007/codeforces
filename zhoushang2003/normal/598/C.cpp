#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
const double P=acos(-1);
int n,x,y,A,B;
long double s;
pair<long double,int>p[N];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>x>>y,p[i]=make_pair(atan2(y,x),i);
	sort(p+1,p+n+1),s=p[1].first-p[n].first+2*P,A=p[1].second,B=p[n].second;
	for(int i=1;i<n;i++)
		if(p[i+1].first-p[i].first<s)
			s=p[i+1].first-p[i].first,A=p[i].second,B=p[i+1].second;
	cout<<A<<' '<<B;
}