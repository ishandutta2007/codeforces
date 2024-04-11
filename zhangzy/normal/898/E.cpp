#include<bits/stdc++.h>
#define ll long long
#define db double
using namespace std;

int n;
ll x,y,z,ans=0;
priority_queue<ll,vector<ll>,greater<ll> >q;

int main(){
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%I64d",&x);
		if (!x){
			ans+=2;
			q.push(-2);
			continue;
		}
		y=1e15; z=sqrt((db)x);
		for (int j=-2;j<=2;++j) y=min(y,abs(x-(z+j)*(z+j)));
		if (y){
			q.push(y);
		}else{
			++ans;
			q.push(-1);
		}
	}
	for (int i=n/2;i--;) ans+=q.top(), q.pop();
	cout<<ans;
}