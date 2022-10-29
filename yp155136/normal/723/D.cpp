#include <iostream>
#include <stdio.h>
#include <queue>
#include <cstring>
#include <set>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 53;

int mp[MAX_N][MAX_N];
char c[MAX_N];
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};

int n,m;

int dfs(int x,int y,int id) {
//	cout<<"x="<<x<<",y="<<y<<endl;
	int ret=1;
	mp[x][y]=id;
	for (int i=0;4>i;i++) {
		int tx=x+dx[i];
		int ty=y+dy[i];
		if (mp[tx][ty] == 0 && tx<=n+1 && ty<=m+1 && 0<=tx && 0<=ty) {
			ret += dfs(tx,ty,id);
		}
	}
	return ret;
}

int main () {
	int k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		memset(mp,0,sizeof(mp));
		for (int x=1;n>=x;x++) {
			getchar();
			scanf("%s",c);
			for (int y=1;m>=y;y++) {
				if (c[y-1]=='*') mp[x][y]=-1;
			}
		}
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		int id=1;
		for (int i=0;n>=i;i++) {
			for (int j=0;m>=j;j++) {
				if (mp[i][j] == 0) {
					int sz=dfs(i,j,id);
					if (id!=1) pq.push(make_pair(sz,id));
					id++;
				}
			}
		}
//		cout<<id<<endl;
		int cnt=id-2;
		int need=cnt-k;
		set<int> s;
		int ans=0;
		while (need>0) {
			pii tmp=pq.top();
			pq.pop();
			s.insert(tmp.second);
			ans += tmp.first;
			need--;
		}
		printf("%d\n",ans);
		for (int i=1;n>=i;i++) {
			for (int j=1;m>=j;j++) {
				if (mp[i][j]==-1) printf("*");
				else if (s.find(mp[i][j]) == s.end()) printf(".");
				else printf("*");
			}
			puts("");
		}
	}
}