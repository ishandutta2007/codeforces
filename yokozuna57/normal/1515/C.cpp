#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define mp make_pair
#define fr first
#define sc second

int n,m,x;
int h[100010];

void solve(){
	puts("YES");
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> que;
	for(int i=1;i<=m;i++)que.push(mp(0,i));
	for(int i=0;i<n;i++){
		auto p=que.top(); que.pop();
		printf("%d%c",p.sc,(i+1==n)?'\n':' ');
		que.push(mp(p.fr+h[i],p.sc));
	}
}

int main(){
	int T;
	scanf("%d",&T);
	for(;T>0;T--){
		scanf("%d%d%d",&n,&m,&x);
		for(int i=0;i<n;i++)scanf("%d",&h[i]);
		solve();
	}
}