#include <bits/stdc++.h>
using namespace std;
deque <int> p[5001];
int n, m;
int main(){
	cin>>n>>m;
	for(int i=1, a, b; i<=m; i++){
		cin>>a>>b;
		p[a].push_back(b);
	}
	for(int i=1; i<=n; i++){
		sort(p[i].begin(), p[i].end());
		if(!p[i].empty()){
			if(p[i].back()>i)	while(p[i].front()<i){
				p[i].push_back(p[i].front());
				p[i].pop_front();
			}
			int cnt=0;
			int now=i;
			while(now!=p[i].front()){
				cnt++;
				(now%=n)+=1;
			}
			p[i][0]=(p[i].size()-1)*n+cnt;
		}
	}
	int mx=0;
	for(int i=1; i<=n; i++) if(p[i].size()>mx) mx=p[i].size();
	for(int i=1; i<=n; i++){
		int ed=i;
		for(int j=1, pos=i, real=i; j<=n; j++, pos=pos%n+1, real++){
			if(!p[pos].empty())	ed=max(ed, real+p[pos][0]);
		}
		cout<<ed-i<<" \n"[i==n];
	}
}