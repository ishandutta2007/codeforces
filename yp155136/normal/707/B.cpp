#include <iostream>
#include <stdio.h>
#include <vector>
#include <utility>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 +6;
const int INF = 1e9+7;

bool sto[MAX_N];
vector<pii> edg[MAX_N];

int main () {
	int n,m,k;
	while (scanf("%d %d %d",&n,&m,&k) != EOF) {
		for (int x=0;n>=x;x++) {
			edg[x].clear();
			sto[x]=false;
		}
		for (int x=0;m>x;x++) {
			int i,j,k;
			scanf("%d %d %d",&i,&j,&k);
			edg[j].push_back(make_pair(i,k));
			edg[i].push_back(make_pair(j,k));
		}
		for (int x=0;k>x;x++) {
			int i;
			scanf("%d",&i);
			sto[i]=true;
		}
		int ans=INF;
		for (int x=1;n>=x;x++) {
			if (sto[x]==false) {
				for (auto i=edg[x].begin();i!=edg[x].end();i++) {
					pii tmp=*i;
					int f=tmp.first;
					int s=tmp.second;
					if (sto[f]==true && s<ans) ans=s;
				}
			}
		}
		printf("%d\n",ans==INF?-1:ans);
	}
}