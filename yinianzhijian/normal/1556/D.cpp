#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,k;
vector<ll>v;
ll gad(int a,int b)
{
	cout<<"and "<<a<<" "<<b<<"\n";
	fflush(stdout);
	int o=read();
	return o;
}
ll gor(int a,int b)
{
	cout<<"or "<<a<<" "<<b<<"\n";
	fflush(stdout);
	int o=read();
	return o;
}
signed main(){
	n=read(),k=read();
	ll x=gor(1,2)+gad(1,2),y=gor(1,3)+gad(1,3),z=gor(3,2)+gad(3,2);
	v.push_back((x+y+z)/2-z);
	v.push_back((x+y+z)/2-y);
	v.push_back((x+y+z)/2-x);
	for(int i=4;i<=n;i++)v.push_back(gad(1,i)+gor(1,i)-v[0]);
	sort(v.begin(),v.end());
	cout<<"finish "<<v[k-1]<<"\n";
	return 0;
}