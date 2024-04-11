#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int MAX_N = 1003;
vector<int> edg[MAX_N];
int rudu[MAX_N];
int adj[MAX_N][MAX_N];
int tmp[MAX_N];
int val[MAX_N];
int n,k;
int main () {
	while (scanf("%d %d",&n,&k) != EOF) {
		memset(adj,0,sizeof(adj));
		memset(rudu,0,sizeof(rudu));
		memset(val,0,sizeof(val));
		for (int x=0;n>=x;x++) edg[x].clear();
		for (int x=0;k>x;x++) {
			for (int y=0;n>y;y++) {
				scanf("%d",&tmp[y]);
				for (int z=0;y>z;z++) {
					adj[tmp[z]][tmp[y]]++;
				}
			}
		}
//		cout<<"finish\n";
//		cout<<"k="<<k<<endl;
		for (int x=1;n>=x;x++) {
			for (int y=1;n>=y;y++) {
				if (adj[x][y]==k) {
//					cout<<x<<" , "<<y<<endl;
					rudu[y]++;
					edg[x].push_back(y);
				}
			}
		}
		queue<int> que;
		for (int x=1;n>=x;x++) {
//			cout<<"rudu["<<x<<"] = "<<rudu[x]<<endl;
			if (rudu[x]==0) que.push(x);
		}
		while (que.empty() == false) {
			int t = que.front();
			que.pop();
			int len=edg[t].size();
			for (int x=0;len>x;x++) {
				int i = edg[t][x];
				rudu[i]--;
				val[i] = max(val[i],val[t]+1);
				if (rudu[i] == 0) que.push(i);
			}
		}
		int ans=-1;
		for (int x=1;n>=x;x++) {
			if (ans<val[x]) ans=val[x];
		}
		printf("%d\n",ans+1);
	}
}