#include<bits/stdc++.h>
using namespace std;
int n,m,k,a[1001000];
long long ans;
priority_queue<int,vector<int>,greater<int> >Q;
int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),ans++;
	for(int i=2;i<=n;++i)Q.push(a[i]-a[i-1]-1);
	for(int i=1;i<=n-k&&Q.size();++i){
		ans+=Q.top();
		Q.pop();
	}
	printf("%lld",ans);
}