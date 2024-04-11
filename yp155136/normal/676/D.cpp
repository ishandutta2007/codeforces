#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

char CWturn(char c) { //clockwise==> 
	if (c=='+') return c;
	if (c=='*') return c;
	if (c=='|') return '-';
	if (c=='-') return '|';
	if (c=='^') return '>';
	if (c=='>') return 'v';
	if (c=='v') return '<';
	if (c=='<') return '^';
	if (c=='L') return 'U';
	if (c=='R') return 'D';
	if (c=='U') return 'R';
	if (c=='D') return 'L';
}

bool avail(char a,char b) { //available b=<,^,>,v  ==> ab() 
	if (a=='+') return true;
	if (a=='*') return false;
	if (b=='<') {
		if (a=='|') return false;
		if (a=='-') return true;
		if (a=='^') return false;
		if (a=='>') return false;
		if (a=='v') return false;
		if (a=='<') return true;
		if (a=='L') return false;
		if (a=='R') return true;
		if (a=='U') return true;
		if (a=='D') return true;
	}
	if (b=='^') {
		if (a=='|') return true;
		if (a=='-') return false;
		if (a=='^') return true;
		if (a=='>') return false;
		if (a=='v') return false;
		if (a=='<') return false;
		if (a=='L') return true;
		if (a=='R') return true;
		if (a=='U') return false;
		if (a=='D') return true;
	}
	if (b=='>') {
		if (a=='|') return false;
		if (a=='-') return true;
		if (a=='^') return false;
		if (a=='>') return true;
		if (a=='v') return false;
		if (a=='<') return false;
		if (a=='L') return true;
		if (a=='R') return false;
		if (a=='U') return true;
		if (a=='D') return true;
	}
	if (b=='v') {
		if (a=='|') return true;
		if (a=='-') return false;
		if (a=='^') return false;
		if (a=='>') return false;
		if (a=='v') return true;
		if (a=='<') return false;
		if (a=='L') return true;
		if (a=='R') return true;
		if (a=='U') return true;
		if (a=='D') return false;
	}
}

bool check(char a,char b,int dur) { //if dur==1 than ab, else ab 
//	cout<<"a="<<a<<" , b="<<b<<endl;
	if (a=='*' || b=='*') return false;
	if (dur==2) {
		if (avail(a,'>') && avail(b,'<')) return true;
		else return false;
	}
	else if (dur==1) {
		if (avail(a,'v') && avail(b,'^')) return true;
		else return false;
	}
	else if (dur==4) {
		if (avail(a,'<') && avail(b,'>')) return true;
		else return false;
	}
	else if (dur==3) {
//		cout<<"innnn\n";
		if (avail(a,'^') && avail(b,'v')) return true;
		else return false;
	}
}

const int MAX_K = 5;
const int MAX_N = 1001;
const int MAX_M = 1001;
const int MAX_NUM = 31001001;

string mp[MAX_K][MAX_N];
int dp[MAX_K][MAX_N][MAX_M];
int n,m;

struct Node {
	int a;
	int b;
	int c;
	void give_val(int _a,int _b,int _c) {
		a=_a;
		b=_b;
		c=_c;
	}
};

inline int transfer(Node node) {
	return node.a * 1000000 + node.b * 1000 + node.c;
}

inline Node NEXT(Node node) {
	node.a = (node.a+1)%4;
	return node;
}

void mkCWturn() {
	for (int i=0;3>i;i++) {
		for (int x=0;n>x;x++) {
			mp[i+1][x] = mp[i][x];
			for (int y=0;m>y;y++) {
				mp[i+1][x][y] = CWturn(mp[i][x][y]);
			}
		}
	}
}


/*
void build_edge() {
	for (int i=0;4>i;i++) {
		for (int x=0;n>x;x++) {
			for (int y=0;m>y;y++) {
				Node node;
				node.give_val(i,x,y);
				edg[transfer(node)].push_back(NEXT(node));
				int dx[2]={1,0},dy[2]={0,1};
				for (int j=0;2>j;j++) {
					int tx=x+dx[j],ty=y+dy[j];
					if (tx>=n ||ty>=m) continue;
					else {
						if (check(mp[x][y],mp[tx][ty],j+1) == true) {
							Node tmp = node;
							node.b=tx;
							node.c=ty;
							edg[transfer(node)].push_back(tmp);
							edg[transfer(tmp)].push_back(node);
						}
					}
				}
			}
		}
		for (int x=0;n>x;x++) {
			for (int y=0;m>y;y++) {
				mp[x][y]=CWturn(mp[x][y]);
			}
		}
//		for (int x=0;n>x;x++) cout<<mp[x]<<endl;
	}
}
*/

void bfs(int sx,int sy) {
	memset(dp,-1,sizeof(dp));
	queue<Node> que;
	Node uu;
	uu.give_val(0,sx,sy);
	que.push(uu);
	dp[0][sx][sy]=0;
	while (que.empty()==false) {
		Node node = que.front();
		que.pop();
//		cout<<"dp = "<<dp[node.a][node.b][node.c] <<" : ";
//		cout<<node.a << ' ' << node.b << ' '<<node.c << endl;
		int tmp = transfer(node);
		int dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
		for (int i=0;5>i;i++) {
			Node t;
			if (i==4) {
				t=NEXT(node);
				if (dp[t.a][t.b][t.c]==-1) {
					dp[t.a][t.b][t.c]=dp[node.a][node.b][node.c] + 1;
					que.push(t);
				}
			}
			else {
				int tx=node.b + dx[i];
				int ty=node.c + dy[i];
//				cout<<"tx = "<<tx<<" , ty = "<<ty << endl;
				if (0<=tx&&tx<n && 0<=ty&&ty<m) {
					if(check(mp[node.a][node.b][node.c],mp[node.a][tx][ty],i+1) == true) {
						t.a=node.a;
						t.b=tx;
						t.c=ty;
						if (dp[t.a][t.b][t.c]==-1) {
							dp[t.a][t.b][t.c]=dp[node.a][node.b][node.c] + 1;
							que.push(t);
						}
					}
				}
			}
		}
	}
}

int main () {
	//ios::sync_with_stdio(0);cin.tie(0);
	while (cin >> n >> m) {
		for(int x=0;n>x;x++) cin >> mp[0][x];
//		build_edge();
		mkCWturn();
//		for (int i=0;4>i;i++) {
//			for (int x=0;n>x;x++) {
//				cout<<mp[i][x]<<endl;
//			}
//			cout<<endl;
//		}
		int sx,sy;
		int ex,ey;
		cin >> sx >> sy;
		cin >> ex >> ey;
		bfs(sx-1,sy-1);
		int mn = 1e9+7;
		for (int x=0;4>x;x++) {
			if (dp[x][ex-1][ey-1]!=-1)mn=min(dp[x][ex-1][ey-1],mn);
		}
		if (mn==1e9+7) cout << "-1" << endl;
		else cout << mn << endl;
	}
}

/*
3 3
->v
*+|
+*^
3 3
1 1
*/