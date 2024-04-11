#include<queue>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 100100
using namespace std;
typedef long long ll;
typedef pair<int,int> data;
priority_queue<data>pq;
ll p[maxn],ans;
int n,w[maxn],cnt,c[maxn],m,vis[maxn];
ll cal(int x){
	x%=100;
	if(x==0)return 0;
	else return 100-x;
}
int main(){
	scanf("%d%d",&n,&p[0]);
	for(int i=1;i<=n;++i)scanf("%d",&c[i]);
	for(int i=1;i<=n;++i)scanf("%d",&w[i]);
	for(int i=1;i<=n;++i)p[i]=p[i-1]+cal(c[i]),ans+=cal(c[i])*w[i];
	for(int i=p[n]/100,now=n;i;){
		for(;now&&p[now]>=i*100;now--)
			pq.push(data(cal(c[now])*w[now],now));
		if(!pq.empty()){
			ans-=pq.top().first;
			vis[pq.top().second]=1; 
			pq.pop();
			cnt++;
			i--; 
		} else {
			if(now)i=p[now]/100;
			else i--;
		}
	}
	printf("%lld\n",ans);
	for(int i=1;i<=n;++i){
		if(vis[i])printf("%d %d\n",c[i]/100,c[i]%100);
		else printf("%d %d\n",(c[i]+99)/100,0);
	}
}