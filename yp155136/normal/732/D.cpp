#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 1e5 + 6;

int a[MAX_N];
int b[MAX_N];
int pos[MAX_N];
pii tmp[MAX_N];

bool check(int id,int n,int m) {
//	cout<<"id = "<<id<<endl;
	memset(pos,-1,sizeof(pos));
	for (int x=id;x>=1;x--) {
		pos[a[x]] = max(x,pos[a[x]]);
	}
	for (int x=1;m>=x;x++) {
//		cout<<"x = "<<x<<" , pos = "<<pos[x]<<endl;
		if (pos[x] == -1) return false;
		tmp[x] = make_pair(pos[x],x);
	}
	sort(tmp+1,tmp+m+1);
	int rest=0;
	int last=1;
	for (int x=1;m>=x;x++) {
//		cout<<"x = "<<x<<" , F = "<<tmp[x].first<<" , S= "<<tmp[x].second<<endl;
		rest += tmp[x].first-last;
		last=tmp[x].first+1;
//		cout<<"x = "<<x<<" rest = "<<rest<<endl;
		if (rest < b[tmp[x].second]) return false;
		else rest -= b[tmp[x].second];
	}
	return true;
}

int main () {
	int n,m;
	while (scanf("%d %d",&n,&m) != EOF) {
		for(int x=1;n>=x;x++) {
			scanf("%d",&a[x]);
		}
		for (int y=1;m>=y;y++) {
			scanf("%d",&b[y]);
		}
		int L=-1,R=n+1;
		while (R-L != 1) {
			int mid=(L+R)>>1;
			if (check(mid,n,m)) R=mid;
			else L=mid;
		}
		if (R==n+1) puts("-1");
		else printf("%d\n",R);
	}
}