#include<bits/stdc++.h>
#define tp q.top(),q.pop()
#define ll long long
using namespace std;

priority_queue<ll,vector<ll>,greater<ll> >q;
ll n,x,y,z,ans=0;

int main(){
	cin>>n;
	for (int t=n;t--;q.push(x)) cin>>x;
	if (n>3&&!(n&1)) x=tp,y=tp,q.push(ans=x+y);
	for (;q.size()>1;z=0){
		x=tp,y=tp; if (!q.empty()) z=tp;
		ans+=x+y+z;
		q.push(x+y+z);
	}
	cout<<ans;
}