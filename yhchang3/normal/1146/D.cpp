#include<bits/stdc++.h>
using namespace std;
bool visit[300001];
queue<int> q;
long long int calc(long long int gc,long long int x){
	long long int tmp=x/gc*gc;
	return gc*(1+x/gc)*(x/gc)/2+(x-tmp+1)*(x/gc+1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	long long int m,cnt=0;int a,b;
	cin>>m>>a>>b;
	long long int ans=0;
	ans++;
	cnt++;
	visit[0]=true;
	for(int i=1;i<=min(m,300000LL);i++){
		//cout<<ans<<endl;
		if(i-a<0||!visit[i-a]){
			ans+=cnt;
			if(i==m){
				cout<<ans<<endl;
				return 0;
			}
			continue;
		}
		visit[i]=true;
		q.push(i);
		while(!q.empty()){
			int now=q.front();
			q.pop();cnt++;
			if(now-b>=0&&!visit[now-b])	q.push(now-b),visit[now-b]=true;
			if(now+a<=i&&!visit[now+a])	q.push(now+a),visit[now+a]=true;
		}
		ans+=cnt;
		if(i==m){
			cout<<ans<<endl;
			return 0;
		}
	}
	long long int g=__gcd(a,b);
	ans=ans-calc(g,300000)+calc(g,m);
	cout<<ans<<endl;
}