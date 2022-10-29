#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <utility>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
typedef pair<pii,int> piii;

vector<piii> v;

void ask(int id) {
	printf("? %d\n",id);
	fflush(stdout);
	int val,nxt;
	scanf("%d %d",&val,&nxt);
	v.push_back({make_pair(val,id),nxt });
}

bool used[50006];

int myRnd() {
	return 1000*(rand() %1000) + (rand()%1000);
}

int main () {
	srand(time(NULL));
	int n,start,x;
	scanf("%d %d %d",&n,&start,&x);
	if (n<=1999) {
		int ans=-1;
		for (int i=1;n>=i;i++) {
			printf("? %d\n",i);
			fflush(stdout);
			int val,nxt;
			scanf("%d %d",&val,&nxt);
			if (val >= x) {
				if (ans == -1) ans = val;
				else if (val < ans) ans=val;
			}
		}
		printf("! %d\n",ans);
		fflush(stdout);
		return 0;
	}
	ask(start);
	int cnt=999;
	used[start] = 1;
	while (cnt--) {
		int id=myRnd()%n + 1;
		while (used[id]) id=myRnd()%n+1;
		ask(id);
		used[id]=1;
	}
	sort(v.begin(),v.end());
	int ii=-1;
	if (v[0].first.first >= x) {
		printf("! %d\n",v[0].first.first);
		fflush(stdout);
		return 0;
	}
	for (int i=0;v.size()>i;i++) {
		if (i+1 != v.size() && v[i+1].first.first > x) {
			ii=i;
			break;
		}
		else if (i+1 != v.size() && v[i+1].first.first == x) {
			printf("! %d\n",x);
			fflush(stdout);
			return 0;
		}
	}
	if (ii==-1) ii=v.size()-1;
	int now=v[ii].first.first;
	int nxt=v[ii].second;
	while (now < x) {
		if (nxt == -1) {
			puts("! -1");
			fflush(stdout);
			return 0;
		}
		printf("? %d\n",nxt);
		fflush(stdout);
		int nnxt,val;
		scanf("%d %d",&val,&nnxt);
		now = val;
		nxt = nnxt;
	}
	printf("! %d\n",now);
	fflush(stdout);
	return 0;
}