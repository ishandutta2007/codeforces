#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
#include <utility>
#include <cmath>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int MAX_N= 302;
const int INF = 1e9+7;

vector<pii> color[MAX_N*MAX_N];
int cnt[MAX_N*MAX_N];
int dp[MAX_N][MAX_N];
int mp[MAX_N][MAX_N];
int d[MAX_N][MAX_N];

int main () {
	memset(mp,-1,sizeof(mp));
	int n,m,p;
	while (scanf("%d %d %d",&n,&m,&p) != EOF) {
		for (int x=1;n>=x;x++) {
			for (int y=1;m>=y;y++) {
				scanf("%d",&mp[x][y]);
				color[mp[x][y]].push_back(make_pair(x,y));
				cnt[mp[x][y]]++;
				if (mp[x][y]==1) dp[x][y]=(x-1)+(y-1);
				else dp[x][y] = INF;
			}
		}
		#define F first
		#define S second
		for (int x=2;p>=x;x++) {
			//from x-1 to x
			if (cnt[x]*cnt[x-1]<=n*m) {
				int len1=color[x].size();
				int len2=color[x-1].size();
				for (int i=0;len1>i;i++) {
					pii tmp1=color[x][i];
					for (int j=0;len2>j;j++) {
						pii tmp2=color[x-1][j];
						dp[tmp1.F][tmp1.S]=min(dp[tmp1.F][tmp1.S],dp[tmp2.F][tmp2.S]+abs(tmp1.F-tmp2.F)+abs(tmp1.S-tmp2.S));
					}
				}
			}
			else {
//				cout<<"in2\n";
				int len1=color[x-1].size();
				queue<piii> que;
				vector<piii> vec;
				for (int i=0;len1>i;i++) {
					pii tmp=color[x-1][i];
					vec.push_back(make_pair(dp[tmp.F][tmp.S],tmp));
//					cout<<"dis = "<<dp[tmp.F][tmp.S]<<endl;
				}
				sort(vec.begin(),vec.end());
				int len2=vec.size();
				memset(d,-1,sizeof(d));
				d[vec[0].S.F][vec[0].S.S]=0;
				int val=vec[0].F;
				int id=1;
				que.push(vec[0]);
				while (len2>id && vec[id].F<=val) {
					que.push(vec[id]);
					d[vec[id].S.F][vec[id].S.S]=0;
					id++;
				}
				while (!que.empty()) {
					piii tmp=que.front();
//					cout<<"tmp = "<<tmp.F<<' '<<tmp.S.F<<' '<<tmp.S.S <<endl;
					que.pop();
					int val1=tmp.F;
					while (len2>id && vec[id].F<=val1) {
						que.push(vec[id]);
						id++;
					}
					int dx[4]={0,0,1,-1},dy[4]={1,-1,0,0};
					for (int i=0;4>i;i++) {
						int tx=tmp.S.F + dx[i],ty=tmp.S.S + dy[i];
						if (mp[tx][ty]!=-1 && d[tx][ty]==-1) {
							d[tx][ty]=val1+1;
							que.push(make_pair(d[tx][ty],make_pair(tx,ty)));
						}
					}
				}
//				cout<<"dis : \n";
				for (int i=1;n>=i;i++) {
					for (int j=1;m>=j;j++) {
//						cout<<d[i][j]<<' ';
						if (mp[i][j]==x) {
							dp[i][j]=d[i][j];
						}
					}
//					cout<<endl;
				}
			}
//			cout<<"x="<<x<<" : \n";
//			for (int x=1;n>=x;x++) {
//				for (int y=1;m>=y;y++) {
//					if (dp[x][y]==INF) cout<<"- ";
//					else cout << dp[x][y]<< ' ';
//				}
//				cout<<endl;
//			}
		}
//		cout<<color[p][0].F<<' '<<color[p][0].S<<endl;
		printf("%d\n",dp[color[p][0].F][color[p][0].S]);
		
	}
}