#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,i,j,a[N],t[N],x,y,p;
pair<int,int>aa[N];
priority_queue<int>q;
long long ans,tot;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i)scanf("%d",t+i),aa[i]={a[i],t[i]};
	sort(aa+1,aa+n+1);
	auto opt=[&](){tot-=q.top();q.pop();ans+=tot;};
	for(i=1;i<=n;i=j){
		for(;!q.empty() && x<aa[i].first;opt(),++x);
		for(j=i;j<=n && aa[j].first==aa[i].first;++j)tot+=aa[j].second,q.push(aa[j].second);x=aa[i].first;
	}
	for(;!q.empty();opt());
	printf("%lld\n",ans);
}