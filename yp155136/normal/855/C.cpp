#include <iostream>
#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

typedef long long LL;
const int MAX_N = 1e5 + 6;
const LL mod = 1e9 + 7;

LL dp[MAX_N][11][4];
bool visit[MAX_N];

vector<int> edg[MAX_N];
LL pre[11];
LL pre2[11];

#define SZ(x) ((int)(x).size())

int k,x,m;

//dp[i][j][k] --> subtree i has j k-type and type is k
//k == 0 , val == k, k==1 --> val < k , k==2, val > k

void dfs(int id) {
	visit[id]=1;
	vector<int> v;
	for (int i:edg[id]) {
		if (!visit[i]) {
			dfs(i);
			v.push_back(i);
		}
	}
	if (SZ(v) == 0) {
		dp[id][1][0] = 1;
		dp[id][0][1] = (k-1);
		dp[id][0][2] = (m-k);
	}
	else {
		for (int num=0;x>=num;num++) {
			dp[id][num][1] = (k-1);
			dp[id][num][2] = (m-k);
			memset(pre,0,sizeof(pre));
			int cnt=0;
			for (int son:v) {
				memset(pre2,0,sizeof(pre2));
				cnt++;
				for (int numm=0;num>=numm;numm++) {
					for (int nnum=0;numm>=nnum;nnum++) {
						if (cnt == 1) {
							;
						}
						else {
							pre2[numm] += pre[nnum]*(dp[son][numm-nnum][0] + dp[son][numm-nnum][1] + dp[son][numm-nnum][2]);
							pre2[numm] %= mod;
						}
					}
					if (cnt == 1) {
						pre2[numm] = (dp[son][numm][0] + dp[son][numm][1] + dp[son][numm][2]);
						pre2[numm] %= mod;
					}
				}
				for (int i=0;num>=i;i++) {
					pre[i] = pre2[i];
//					cout<<"son = "<<son<<" , "<<"id = "<<id<<" , pre["<<i<<"] = "<<pre[i]<<endl;
				}
			}
			LL sum=pre[num];
			dp[id][num][1] *= sum;
			dp[id][num][1] %= mod;
			memset(pre,0,sizeof(pre));
			cnt=0;
			for (int son:v) {
				memset(pre2,0,sizeof(pre2));
				cnt++;
				for (int numm=0;num>=numm;numm++) {
					for (int nnum=0;numm>=nnum;nnum++) {
						if (cnt == 1) {
							;
						}
						else {
							pre2[numm] += pre[nnum]*(dp[son][numm-nnum][1] + dp[son][numm-nnum][2]);
							pre2[numm] %= mod;
						}
					}
					if (cnt == 1) {
						pre2[numm] = (dp[son][numm][1] + dp[son][numm][2]);
						pre2[numm] %= mod;
					}
				}
				for (int i=0;num>=i;i++) {
					pre[i] = pre2[i];
//					cout<<"son = "<<son<<" , "<<"id = "<<id<<" , pre["<<i<<"] = "<<pre[i]<<endl;
				}
			}
			sum=pre[num];
			dp[id][num][2] *= sum;
			dp[id][num][2] %= mod;
			if (num) {
				dp[id][num][0] = 1;
				memset(pre,0,sizeof(pre));
				cnt=0;
				for (int son:v) {
					memset(pre2,0,sizeof(pre2));
					cnt++;
					for (int numm=0;num>=numm;numm++) {
						for (int nnum=0;numm>=nnum;nnum++) {
							if (cnt == 1) {
								;
							}
							else {
								pre2[numm] += pre[nnum]*(dp[son][numm-nnum][1]);
								pre2[numm] %= mod;
							}
						}
						if (cnt == 1) {
							pre2[numm] = (dp[son][numm][1]);
							pre2[numm] %= mod;
						}
					}
					for (int i=0;num>=i;i++) {
						pre[i] = pre2[i];
	//					cout<<"son = "<<son<<" , "<<"id = "<<id<<" , pre["<<i<<"] = "<<pre[i]<<endl;
					}
				}
				sum=pre[num-1];
				dp[id][num][0] *= sum;
				dp[id][num][0] %= mod;
//				cout<<"dp["<<id<<"]["<<num<<"]["<<0<<"] = "<<dp[id][num][0]<<endl;
			}
		}
	}
//	cout<<"id = "<<id<<" : "<<endl;
//	for (int num=0;x>=num;num++) {
//		for (int type=0;2>=type;type++) {
//			cout<<dp[id][num][type]<<' ';
//		}
//		cout<<endl;
//	}
//	cout<<endl<<endl;
}

int main () {
	int n;
	scanf("%d %d",&n,&m);
	for (int i=1;n-1>=i;i++) {
		int x,y;
		scanf("%d %d",&x,&y);
		edg[x].push_back(y);
		edg[y].push_back(x);
	}
	scanf("%d %d",&k,&x);
	dfs(1);
	LL ans=0;
	for (int num=0;x>=num;num++) {
		for (int type=0;2>=type;type++) {
			ans += dp[1][num][type];
			ans %= mod;
		}
	}
	printf("%lld\n",ans);
}