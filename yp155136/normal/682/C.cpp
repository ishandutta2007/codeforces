#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
using namespace std;

#define int long long

const int MAX_N = 100003;
int a[MAX_N];
bool visit[MAX_N];
int ans;

struct Edge {
	int j;
	int c;
};

vector<Edge> edg[MAX_N];

int max(int a,int b) {
	int tmp=b;
	if (a>tmp) return a;
	else return tmp;
}

void DFS(int id,int dis,bool destroy) {
//	cout<<"id = "<<id<<" , dis = "<<dis<<" , destroy = "<<destroy<<endl;
	visit[id]=true;
	if (destroy==true) {
		ans++;
//		cout<<"in1\n";
	}
	if (id==1) {
		int len=edg[id].size();
		for (int x=0;len>x;x++) {
			Edge i=edg[id][x];
			if (visit[i.j]==false) {
				DFS(i.j, max(dis,0) + i.c,destroy);
			}
		}
	}
	else {
		if (dis>a[id] && destroy==false) {
			destroy=true;
			ans++;
//			cout<<"in2\n";
		}
		int len=edg[id].size();
		for (int x=0;len>x;x++) {
			Edge i=edg[id][x];
			if (visit[i.j]==false) {
				DFS(i.j, max(dis,0) + i.c,destroy);
			}
		}
	}
}



main () {
	int n;
	while (scanf("%I64d",&n) != EOF) {
		for (int x=1;n>=x;x++) scanf("%I64d",&a[x]);
		for (int x=2;n>=x;x++) {
			int i,j;
			scanf("%I64d %I64d",&i,&j);
			Edge tmp;
			tmp.j=i;
			tmp.c=j;
			edg[x].push_back(tmp);
			tmp.j=x;
			edg[i].push_back(tmp);
		}
		ans=0;
		for (int x=0;n>=x;x++) visit[x]=false;
		DFS(1,0,false);
		printf("%I64d\n",ans);
	}
}