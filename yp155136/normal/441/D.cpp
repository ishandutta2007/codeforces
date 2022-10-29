#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 3e3 + 6;

int a[MAX_N];
bool visit[MAX_N];
vector<int> ala[MAX_N];

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=0;n>=i;i++) {
			ala[i].clear();
		}
		for (int i=1;n>=i;i++) {
			int x;
			scanf("%d",&x);
			a[i]=x;
		}
		memset(visit,0,sizeof(visit));
		int _;
		scanf("%d",&_);
		int sz=0;
		for (int i=1;n>=i;i++) {
			if (!visit[i]) {
				sz++;
				int __=i;
				while (!visit[__]) {
					visit[__]=1;
					ala[sz].push_back(__);
					__ = a[__];
				}
			}
		}
		if (n-sz == _) {
			puts("0");
			continue;
		}
		else if (n-sz >= _) {
			vector<pii> ans;
			//too much
			int need=(n-sz-_);
			printf("%d\n",(n-sz-_));
			while (need--) {
				pii alala=make_pair(n+1,n+1);
				int mn1=n+1,mnid=n+1;
				for (int i=1;sz>=i;i++) {
					if (ala[i].size()!=1) {
						int len=ala[i].size();
						for (int j=0;len>j;j++) {
							if (ala[i][j] < mn1) {
								mn1=ala[i][j];
								mnid=i;
							}
						}
					}
				}
				int mn2=n+1;
				for (int i=1;sz>=i;i++) {
					if (i!=mnid) continue;
					if (ala[i].size()!=1) {
						int len=ala[i].size();
						for (int j=0;len>j;j++) {
							if (ala[i][j] < mn2 && ala[i][j] != mn1) {
								mn2=ala[i][j];
								mnid=i;
							}
						}
					}
				}
				alala = make_pair(mn1,mn2);
				printf("%d %d ",alala.first,alala.second);
				swap(a[alala.first],a[alala.second]);
				memset(visit,0,sizeof(visit));
				sz=0;
				for (int i=1;n>=i;i++) {
					ala[i].clear();
				}
				for (int i=1;n>=i;i++) {
					if (!visit[i]) {
						sz++;
						int __=i;
						while (!visit[__]) {
							visit[__]=1;
							ala[sz].push_back(__);
							__ = a[__];
						}
					}
				}
			}
			puts("");
		}
		else if (n-sz < _){
			vector<pii> ans;
			//too few
			int need = _-(n-sz);
			for (int i=2;sz>=i;i++) {
				ans.push_back(make_pair(ala[1][0],ala[i][0]));
			}
			sort(ans.begin(),ans.end());
			printf("%d\n",-(n-sz-_));
			for (auto i:ans) {
				printf("%d %d ",i.first,i.second);
				need--;
				if (!need) break;
			}
			puts("");
		}
	}
}