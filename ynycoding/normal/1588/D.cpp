#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <algorithm>
#define pb push_back
using std::map;
using std::vector;
const int N=11;
int T, n, id[N][55][2], top, mx, mxid;
int f[55000], fr[55000];
vector<int> pr[55000];
vector<int> pos, cpos;
int cid, len, tp;
char s[200], rs[200];
map<vector<int>, int> rid;
inline int gid(char c) { return c<='Z'?c-'A':c-'a'+26; }
void dfs(int u)
{
	if(u>n) { pr[++top]=pos; return; }
	if(id[u][cid][0]) pos[u-1]=id[u][cid][0], dfs(u+1);
	if(id[u][cid][1]) pos[u-1]=id[u][cid][1], dfs(u+1);
}
int gpos(int u)
{
	if(u>n) return f[rid[cpos]];
	if(id[u][cid][1]&&id[u][cid][1]<pos[u-1])
	{
		cpos[u-1]=id[u][cid][1];
		return gpos(u+1);
	}
	if(id[u][cid][0]&&id[u][cid][0]<pos[u-1])
	{
		cpos[u-1]=id[u][cid][0];
		return gpos(u+1);
	}
	return 0;
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		mxid=mx=top=0;
		scanf("%d", &n);
		rid.clear();
		pos.resize(n), cpos.resize(n);
		memset(id, 0, sizeof(id));
		for(int i=1; i<=n; ++i)
		{
			scanf("%s", s+1);
			len=strlen(s+1);
			for(int j=1; j<=len; ++j)
			{
				id[i][gid(s[j])][(id[i][gid(s[j])][0]>0)]=j;
			}
		}
		for(cid=0; cid<52; ++cid)
			dfs(1);
		std::sort(pr+1, pr+top+1);
		for(int i=1; i<=top; ++i)
		{
			pos=pr[i];
			rid[pos]=i;
			fr[i]=0;
			f[i]=1;
			for(cid=0; cid<52; ++cid)
			{
				int v=gpos(1)+1;
				if(v>f[i])
				{
					fr[i]=rid[cpos];
					f[i]=v;
				}
			}
			if(f[i]>mx) mx=f[i], mxid=i;
		}
		int u=mxid;
		printf("%d\n", mx);
		tp=0;
		while(u) rs[tp++]=s[pr[u][n-1]], u=fr[u];
		std::reverse(rs, rs+tp);
		rs[tp]=0;
		if(tp) puts(rs);
		else puts("");
	}
	return 0;
}