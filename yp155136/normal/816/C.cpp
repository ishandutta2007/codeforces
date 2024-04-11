#include <iostream>
#include <stdio.h>
#include <vector>
#include <cstring>
using namespace std;

typedef pair<int,int> pii;
typedef pair<int,pii> piii;
const int MAX_N = 106;

int g[MAX_N][MAX_N];
int h[MAX_N][MAX_N];
bool not_empty_row[MAX_N];
bool not_empty_col[MAX_N];
bool used_row[MAX_N];
bool used_col[MAX_N];

void coppy(int n,int m) {
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			h[i][j] = g[i][j];
		}
	}
	memset(used_row,0,sizeof(used_row));
	memset(used_col,0,sizeof(used_col));
}

bool okayy(int n,int m) {
	bool ret=true;
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			ret &= (h[i][j]==0);
		}
	}
	return ret;
}

bool deleted(int type,int x,int val,int n,int m) {
	if (type==1) {
		//row
		int i=x;
		for (int j=1;m>=j;j++) {
			h[i][j] -= val;
			if (h[i][j] < 0) return false;
		}
		return true;
	}
	if (type==2) {
		//column
		int j=x;
		for (int i=1;n>=i;i++) {
			h[i][j] -= val;
			if (h[i][j] < 0) return false;
		}
		return true;
	}
}

int main () {
	int n,m;
	scanf("%d %d",&n,&m);
	bool not_empty=false;
	for (int i=1;n>=i;i++) {
		for (int j=1;m>=j;j++) {
			scanf("%d",&g[i][j]);
			if (g[i][j]) {
				not_empty_row[i] = 1;
				not_empty_col[j] = 1;
				not_empty=true;
			}
		}
	}
	if (!not_empty) {
		puts("0");
		return 0;
	}
	int rrow=-1;
	for (int i=1;n>=i;i++) {
		if (not_empty_row[i]) {
			rrow=i;
			break;
		}
	}
	if (rrow==-1) cout<<0/0<<endl;
	vector<piii> ans;
	vector<piii> real_ans;
	int meruru = 123456789;
	int xx=0;
	for (int cnt=0;g[rrow][1] >= cnt;cnt++) {
		ans.clear();
		coppy(n,m);
		bool ret=deleted(1,rrow,cnt,n,m);
		xx=0;
		xx+=cnt;
		ans.push_back(make_pair(1,make_pair(rrow,cnt)));
		for (int j=1;m>=j;j++) {
			xx+=h[rrow][j];
			ans.push_back(make_pair(2,make_pair(j,h[rrow][j]) ));
			ret &= deleted(2,j,h[rrow][j],n,m);
		}
		for (int i=1;n>=i;i++) {
			xx+=h[i][1];
			ans.push_back(make_pair(1,make_pair(i,h[i][1]) ));
			ret &= deleted(1,i,h[i][1],n,m);
		}
		if (ret && okayy(n,m)) {
			if (xx<meruru) {
				real_ans=ans;
				meruru=xx;
			}
		}
		else ans.clear();
	}
	ans = real_ans;
	if (ans.size() == 0) puts("-1");
	else {
		int cnt=0;
		for (piii i:ans) {
			cnt += i.second.second;
		}
		//cout<<"meruru = "<<meruru<<endl;
		if (cnt != meruru) cout<<0/0<<endl;
		printf("%d\n",cnt);
		for (piii i:ans) {
			while (i.second.second--) {
				if (i.first == 1) printf("row ");
				else printf("col ");
				printf("%d\n",i.second.first);
			}
		}
	}
}