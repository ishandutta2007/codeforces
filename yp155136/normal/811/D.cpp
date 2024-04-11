#include <iostream>
#include <stdio.h>
#include <cstring>
#include <utility>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int,int> pii;
const int MAX_N = 106;

int mp[MAX_N][MAX_N];
int dis[MAX_N][MAX_N];
char c[MAX_N];

pii ask(pii pos,char c) {
	printf("%c\n",c);
	fflush(stdout);
	int x,y;
	scanf("%d %d",&x,&y);
	return make_pair(x,y);
}

pii go(char c,int swap) {
	pii ret=make_pair(0,0);
	if (swap == 1) {
		if (c=='U') return ask(ret,'D');
		if (c=='D') return ask(ret,'U');
		if (c=='L') return ask(ret,'R');
		if (c=='R') return ask(ret,'L');
	}
	else {
		return ask(ret,c);
	}
}

pii meruru;

#define aaa return 0;
#define check(x) if(x==meruru)aaa;

int dx[4]={1,-1,0,0},dy[4] = {0,0,1,-1};
char haha[7] = {'U','D','L','R'};

pii operator+(const pii &p1,const pii &p2) {
	return make_pair(p1.first+p2.first,p1.second+p2.second);
}

int n,m;

void get_ans(pii now,int swapUD,int swapLR) {
	memset(dis,-1,sizeof(dis));
	queue<pii> que;
	que.push(now);
	dis[now.first][now.second] = 0;
	while (!que.empty()) {
		pii t=que.front();
//		cout<<"t = "<<t.first<<","<<t.second<<endl;
		que.pop();
		for (int i=0;4>i;i++) {
			pii now=t+make_pair(dx[i],dy[i]);
			if (mp[now.first][now.second] == 0) continue;
			if (dis[now.first][now.second] == -1) {
				dis[now.first][now.second] = dis[t.first][t.second] + 1;
				que.push(now);
			}
		}
	}
//	cout<<"dis : "<<endl;
//	for (int i=1;n>=i;i++) {
//		for (int j=1;m>=j;j++ ){
//			if (dis[i][j] != -1)cout<<dis[i][j]<<' ';
//			else cout<<"* ";
//		}
//		cout<<endl;
//	}
	pii pos=meruru;
	vector<char> kirino;
	while (dis[pos.first][pos.second] != 0) {
//		cout<<"pos : "<<pos.first<<","<<pos.second<<endl;
		for (int i=0;4>i;i++) {
			pii tmp=pos + make_pair(dx[i],dy[i]);
			if (mp[tmp.first][tmp.second] != 0&&dis[tmp.first][tmp.second] < dis[pos.first][pos.second]) {
				kirino.push_back(haha[i]);
				pos = tmp;
				break;
			}
		}
	}
//	cout<<"kiri : "<<endl;
//	for (char i:kirino) cout<<i<<' ';
//	cout<<endl;
	reverse(kirino.begin(),kirino.end());
	for (char i:kirino) {
		if (i=='L' || i=='R') go(i,swapLR);
		else go(i,swapUD);
	}
}

int main () {
	scanf("%d %d",&n,&m);
	getchar();
	memset(mp,0,sizeof(mp));
	for (int i=1;n>=i;i++) {
		scanf("%s",c);
		for (int j=1;m>=j;j++) {
			if (c[j-1]=='F') mp[i][j] = 2,meruru=make_pair(i,j);
			else if (c[j-1]=='*') mp[i][j] = 0;
			else mp[i][j] = 1;
		}
	}
	if (n==1) {
		pii pos=make_pair(1,1);
		for (int j=1;m>=j;j++) {
			pii ret=ask(pos,'R');
			if (ret == meruru) return 0;
		}
		for (int j=1;m>=j;j++) {
			pii ret=ask(pos,'L');
			if (ret==meruru) return 0;
		}
	}
	if (m==1) {
		pii pos=make_pair(1,1);
		for (int i=1;n>=i;i++) {
			pii ret=ask(pos,'U');
			if (ret==meruru) return 0;
		}
		for (int i=1;n>=i;i++) {
			pii ret=ask(pos,'D');
			if (ret==meruru) return 0;
		}
	}
	int swapLR=-1,swapUD=-1;
	pii pos=make_pair(1,1);
	if (mp[2][1] != 0) {
		pii ret=ask(pos,'D');
		if (ret==pos) swapUD=1;
		else swapUD=0;
		pos=ret;
		check(pos);
		if (pos!=make_pair(1,1))pos = go('U',swapUD);
		while (mp[pos.first][pos.second+1] == 0) {
			pos = go('D',swapUD);
			check(pos);
		}
		ret = ask(pos,'R');
		if (ret == pos) swapLR=1;
		else swapLR=0;
		pos = ret;
		check(pos);
		get_ans(pos,swapUD,swapLR);
	}
	else if (mp[1][2] != 0) {
		pii ret=ask(pos,'R');
		if (ret==pos) swapLR=1;
		else swapLR=0;
		pos=ret;
		check(pos);
		if (pos!=make_pair(1,1))pos = go('L',swapLR);
		while (mp[pos.first+1][pos.second] == 0) {
			pos = go('R',swapLR);
			check(pos);
		}
		ret = ask(pos,'D');
		if (ret == pos) swapUD=1;
		else swapUD=0;
		pos = ret;
		check(pos);
		get_ans(pos,swapUD,swapLR);
	}
	else {
		//it's impossible
	}
}