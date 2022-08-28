#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define repn(i,n) for(int i=1;i<=n;i++)
typedef pair<int,int> P;
typedef long long ll;
#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define INF 1000000000
int n,m,a,b;
int x[100005],y[100005],cnt[200005];
priority_queue<int,vector<int>,greater<int>>que;
int main(){
	scanf("%d%d%d%d",&n,&m,&a,&b);
	if(a > m-1 || b > n-1){
		puts("No");
		return 0;
	}
	rep(i,a) scanf("%d",&x[i]);
	rep(i,b) scanf("%d",&y[i]);
	while(a < m-1){
		x[a++] = x[0];
	}
	while(b < n-1){
		y[b++] = y[0];
	}
	puts("Yes");
	rep(i,a)  cnt[x[i]]++;
	rep(i,b)  cnt[y[i]]++;
	repn(i,n+m){
		if(cnt[i] == 0){
			que.push(i);
		}
	}
	int pt = 0, pt2 = 0;
	
	for(int i=0;i<n+m-2;i++){
		int q = que.top(); que.pop();
		if(q <= n){
			cnt[y[pt2]]--;
			if(cnt[y[pt2]] == 0) que.push(y[pt2]);
			printf("%d %d\n",q,y[pt2++]);
		}
		else{
			cnt[x[pt]]--;
			if(cnt[x[pt]] == 0) que.push(x[pt]);
			printf("%d %d\n",q,x[pt++]);
		}
	}
	assert(pt == a && pt2 == b);
	assert(que.size() == 2);
	printf("%d",que.top()); que.pop();
	printf(" %d\n",que.top()); que.pop();
}