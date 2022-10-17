#pragma GCC optimize(3)
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define reaD() read()
#define mst(a,b) memset(a,b,sizeof(a))
#define For(i, k, j) for(register int i = (k); i <= (j); i++)
#define DEBUG printf("Running on Line %d in Function %s\n",__LINE__,__FUNCTION__)
using namespace std;
inline int read()
{
    int num=0,flag=1;char c=' ';
    for(;c>'9'||c<'0';c=getchar()) if(c=='-') flag = -1;
    for(;c>='0'&&c<='9';num=(num<<1)+(num<<3)+c-48,c=getchar());
    return num*flag;
}
#define MAXN 3000005
int st = 1;
int n, m;
string s[MAXN]; 
 
int qwq(int i,int j) {
	return 2*((i-1)*m+j+1);
}
	struct bian {
		int x,y,l,ls;
	}b[MAXN*6];
	int t[MAXN],cnt = 1;
	int p[MAXN];
	queue<int>q;
	int ss,tt;
	
	void qk() {
		memset(t,0,sizeof(t));
		cnt = 1;
	}
	
	void jb(int x,int y,int l) {
		cnt ++;
		b[cnt].x = x;
		b[cnt].y = y;
		b[cnt].l = l;
		b[cnt].ls = t[x];
		t[x] = cnt;
	}
	
	void jn(int x,int y,int l) {
		jb(x,y,l);
		jb(y,x,0); 
	} 
	
	void huanyuan() {
		for(int i = 2; i <= m; i ++) {
			if((i&1) == 0) {
				b[i].l += b[i^1].l;
				b[i^1].l = 0;
			}
		}
	}
	
	int bfs()
	{
		memset(p,0,sizeof(p));
		q.push(ss);
		while(!q.empty())
		{
			int x = q.front();
			q.pop();
			for(int i = t[x]; i != 0; i = b[i].ls) 
			if(b[i].l > 0){
				int y = b[i].y;
				if(!p[y]) {
					p[y] = i^1;
					q.push(y);
				}
			}
		}
		int x = tt,fl = (1 << 30);
		if(p[tt] == 0) return 0;
		while(x != ss) {
			fl = min(fl,b[p[x]^1].l);
			x = b[p[x]].y;
		}
		x = tt;
		while(x != ss) {
			b[p[x]^1].l -= fl;
			b[p[x]].l += fl;
			x = b[p[x]].y;
		}
		return fl;
	} 
	
	int EK(int sb,int tb)
	{
		ss = sb;
		tt = tb;
		m = cnt;
		int ans = 0;
		while(1) {
			int x = bfs();
			if(x == 0) break;
			ans += x;
			
		} 
		huanyuan();
		return ans;
	}
int an = 0;
 
int main()
{
	cin >> n >> m; 
	for(int i = 1; i <= n; i ++)
		cin >> s[i];
	for(int i = 1; i <= n; i ++)
		for(int j = 0; j <= m-1; j++)
		{
			int t = qwq(i,j);
			int td = qwq(i+1,j),tr = qwq(i,j+1);
			if(s[i][j] != '#') {
				int ty = 1;
				if(i == 1 && j == 0) ty = (1<< 30);
				if(i == n && j == m-1) ty = (1<< 30);
				jn(t,t+1,ty);
				
				jn(t+1,td,(1<< 30));
				jn(t+1,tr,(1<< 30));
			} 
		}
	cout<<EK(qwq(1,0),qwq(n,m-1)+1);
	return 0;
}