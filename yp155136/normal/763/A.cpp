#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAX_N = 1e5 + 6;

vector<int> edg[MAX_N];
vector<int> edg_2[MAX_N];
int c[MAX_N];
int color[MAX_N];
bool used[MAX_N];

void dfs(int id,int clr) {
	//cout<<"id = "<<id<<" clr = "<<clr<<endl;
	color[id]=clr;
	used[id]=1;
	for (auto i:edg[id]) {
		if (!used[i]) {
			if (c[i]==c[id]) {
				dfs(i,clr);
			}
		}
		else {
			if (c[i]!=c[id]) {
				edg_2[color[i]].push_back(clr);
				edg_2[clr].push_back(color[i]);
			}
		}
	}
}

int main () {
	int n;
	while (scanf("%d",&n) != EOF) {
		for (int i=1;n>=i;i++) {
			edg[i].clear();
			edg_2[i].clear();
		}
		for (int i=1;n>i;i++) {
			int a,b;
			scanf("%d %d",&a,&b);
			edg[a].push_back(b);
			edg[b].push_back(a);
		}
		vector<int> v;
		for (int i=1;n>=i;i++) {
			scanf("%d",&c[i]);
			v.push_back(c[i]);
		}
		memset(used,0,sizeof(used));
		memset(color,-1,sizeof(color));
		int clr=1;
		for (int i=1;n>=i;i++) {
			if (!used[i]) {
				dfs(i,clr++);
			}
		}
		string ans="YES";
		int _2=-1;
		clr--;
		for (int i=1;clr>=i;i++) {
			if (edg_2[i].size()>1 && _2==-1) {
				_2=i;
			}
			else if (edg_2[i].size()>1 && _2!=-1) {
				ans="NO";
				break;
			}
		}
		if (_2!=-1) {
			int cnt=-1;
			for (int i=1;n>=i;i++) {
				if (color[i]==_2) {
					int sz=0;
					for (auto j:edg[i]) {
						if (color[i]!=color[j]) sz++;
					}
					if (sz==clr-1) {
						cout<<"YES\n";
						cout<<i<<endl;
						return 0;
					}
				}
			}
			if (cnt==-1) ans="NO";
		}
		cout<<ans<<endl;
		if (ans=="YES") {
			if (_2==-1 && clr==1) puts("1");  //nothing in it
			else if (_2==-1) {
				//cout<<"hahaha\n";
				bool get_ans=false;
				for (int i=1;n>=i;i++) {
					for (auto j:edg[i]) {
						if (color[i]!=color[j]) {
							printf("%d\n",i);
							get_ans=1;
							break;
						}
					}
					if (get_ans) break;
				}
			}
			else {
				for (int i=1;n>=i;i++) {
					if (color[i]==_2) {
						printf("%d\n",i);
						break;
					}
				}
			}
		}
	}
}