#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
unordered_set<int>a[N],S;
int n,m,x,y,i,ans;
queue<int>q;
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",&x,&y),a[x].insert(y),a[y].insert(x);
	for(i=1;i<=n;++i)S.insert(i);
	for(;!S.empty();){
		++ans;q.push(*S.begin());S.erase(S.begin());
		for(;!q.empty();){
			x=q.front();q.pop();
			vector<int>ve;
			for(auto it=S.begin();it!=S.end();++it)if(!a[x].count(*it))ve.push_back(*it);
			for(int x:ve)q.push(x),S.erase(x);
		}
	}
	printf("%d\n",ans-1);
	return 0;
}