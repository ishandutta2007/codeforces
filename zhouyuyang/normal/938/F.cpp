#include<bits/stdc++.h>
#define pa pair<int,int>
#define N 5005
using namespace std;
char s[N];
bool vis[N][N];
vector<pa > can[26],now;
void dfs(int x,int y){
	if (vis[x][y]) return;
	vis[x][y]=1;
	if (s[x+1+y])
		can[s[x+1]-'a'].push_back(pa(x+1,y));
	for (int i=0;y>>i;i++)
		if ((y>>i)&1) dfs(x+(1<<i),y-(1<<i)); 
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1),k=1;
	for (;(k<<1)<=n;k<<=1);
	now.push_back(pa(0,k-1));
	for (;;){
		for (int i=0;i<now.size();i++)
			dfs(now[i].first,now[i].second);
		int c=-1;
		for (int i=25;i>=0;i--)
			if (can[i].size()) c=i;
		if (c<0) break;
		putchar(c+'a');
		swap(now,can[c]);
		for (int i=0;i<26;i++)
			can[i].clear();
	}
}