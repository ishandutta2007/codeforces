#include <iostream>
#include <stdio.h>
#include <cstring>
#include <vector>
#include <utility>
#include <queue>
#include <set>
using namespace std;

typedef pair<long long,long long> pii;
typedef long long LL;
const int MAX_N = 1003;
const int MAX_M = 10003;
const LL INF = 1e15+6;
const LL MAX = 1e18-1;

pii input[MAX_M];
LL w[MAX_N][MAX_N];
LL o[MAX_N][MAX_N];

vector<int> edg[MAX_N];
LL d[MAX_N];
pii d2[MAX_N];
vector<int> re[MAX_N];
bool in_que[MAX_N];

LL spfa1(int id,int t,int n) {
	d[id]=0;
	for (int x=0;n>=x;x++) {
		d[x]=INF;
		in_que[x]=false;
	}
	d[id]=0;
	queue<int> que;
	que.push(id);
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		in_que[t]=false;
		for (auto i=edg[t].begin();i!=edg[t].end();i++) {
			int tmp=*i;
			if (w[t][tmp]==0 || w[t][tmp] == -1) ;
			else if (d[tmp] > d[t] + w[t][tmp]) {
				d[tmp] = d[t] + w[t][tmp];
				if (in_que[tmp]==false) {
					in_que[tmp]=true;
					que.push(tmp);
				}
			}
		}
	}
	return d[t];
}

pii spfa2(int id,int t,int n) {
	d2[id]=make_pair(0,0);
	for (int x=0;n>=x;x++) {
		d2[x]=make_pair(INF,0);
		re[x].clear();
		in_que[x]=false;
	}
	d2[id]=make_pair(0,0);
	queue<int> que;
	que.push(id);
	while (!que.empty()) {
		int t=que.front();
		que.pop();
		in_que[t]=false;
		for (auto i=edg[t].begin();i!=edg[t].end();i++) {
			int tmp=*i;
			if (w[t][tmp] == -1) continue;
			pii ne = make_pair(d2[t].first+w[t][tmp],d2[t].second);
			if (o[t][tmp] != -1) ne.second++;
			if (d2[tmp] > ne) {
				d2[tmp] = ne;
				re[tmp] = re[t];
				if (o[t][tmp]!=-1) re[tmp].push_back(o[t][tmp]);
				if (in_que[tmp]==false) {
					in_que[tmp]=true;
					que.push(tmp);
				}
			}
		}
	}
	return d2[t];
}

void show(int m) {
	cout<<"edges : \n";
	for (int x=0;m>x;x++) {
		int i=input[x].first;
		int j=input[x].second;
		cout<<i << " "<<j<<" "<<w[i][j]<<endl;
	}
	cout<<endl;
}

int main () {
	int n,m;
	LL L;
	int s,t;
	while (scanf("%d %d %I64d %d %d",&n,&m,&L,&s,&t) != EOF) {
		memset(w,-1,sizeof(w));
		memset(o,-1,sizeof(o));
		for (int x=0;n>=x;x++) {
			edg[x].clear();
		}
		for (int x=0;m>x;x++) {
			int i,j;
			LL k;
			scanf("%d %d %I64d",&i,&j,&k);
			input[x]=make_pair(i,j);
			w[i][j]=k;
			w[j][i]=k;
			if (k==0) o[i][j] = o[j][i] = x;
			edg[i].push_back(j);
			edg[j].push_back(i);
		}
		LL ret = spfa1(s,t,n);
		if (ret < L) {
			puts("NO");
			continue;
		}
		for (int x=0;m>x;x++) {
			int i=input[x].first;
			int j=input[x].second;
			if (o[i][j] != -1) {
				w[i][j] = w[j][i] = 1;
			}
		}
		pii ret2=spfa2(s,t,n);
//		cout<<ret2.first<<' '<<ret2.second<<endl;
		if (ret2.first> L) {
			puts("NO");
			continue;
		}
		else {
//			cout<<ret2.first<<' '<<ret2.second<<endl;
			puts("YES");
			LL tmpL = L;
			L -= ret2.first;
			int cnt=ret2.second;
			set<int> tmp;
			for (auto i=re[t].begin();i!=re[t].end();i++) {
				int rrr=*i;
				tmp.insert(rrr);
			}
			for (int x=0;m>x;x++) {
				int i=input[x].first;
				int j=input[x].second;
				if (o[i][j] == -1) {
					;
				}
				else if (tmp.find(x) == tmp.end()) {
					w[i][j] =w[j][i]= INF;
				}
				else {
					if (cnt != 1) ;
					else {
						w[i][j]= w[j][i] = L+1;
					}
					cnt--;
				}
			}
//			show(m);
			while (1) {
				ret2 = spfa2(s,t,n);
//				cout<<ret2.first<<endl;
				if (ret2.first == tmpL) break;
				L = tmpL;
				L -= ret2.first;
				int cnt=ret2.second;
				for (auto i=re[t].begin();i!=re[t].end();i++) {
					int rrr=*i;
					if (cnt==1) {
						int i=input[rrr].first;
						int j=input[rrr].second;
						w[i][j] = w[j][i] = L +1;
					}
					cnt--;
				}
				
			}
			for (int x=0;m>x;x++) {
				int i=input[x].first;
				int j=input[x].second;
				printf("%d %d %I64d\n",i,j,w[i][j]);
			}
		}
	}
}