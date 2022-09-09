#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
int x,i,n,k,a[300005];
ll ans,s;
priority_queue<pair<int,int> > q;
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=k;++i){
		scanf("%d",&x);
		q.push(make_pair(x,i));
		ans+=s+=x; 
	}
	for(;i<=n;++i){
		scanf("%d",&x);
		q.push(make_pair(x,i));
		a[q.top().second]=i;
		ans+=s+=x-q.top().first;
		q.pop();
	}
	while(!q.empty()){
		a[q.top().second]=i++;
		ans+=s-=q.top().first;
		q.pop();
	}
	cout<<ans<<endl;
	for(i=1;i<=n;++i)printf("%d ",a[i]);
	return 0;
}