#include <cstdio>
#include <cstring>
#ifdef _WIN32
#define LLFORMAT "%I64"
#else
#define LLFORMAT "%ll"
#endif
const int MAXM=100005;
const int MAXS=300005;
const int MOD=1000000007;
const int PHI=MOD-1;
int m;
char _str[MAXS];
int d[MAXM];
int lt[MAXM];
char *t[MAXM];
int which[10];
int len[MAXM];
int tot[MAXM];
void init()
{
	scanf("%s%d",_str,&m);
	++m;
	t[0]=_str;
	char *now=_str+(lt[0]=strlen(t[0]))+1;
	for (int i=1;i<m;++i)
	{
		scanf("%d->",&d[i]);
		t[i]=now;
		fgets(t[i],MAXS-(now-_str),stdin);
		now+=(lt[i]=strlen(t[i])-1)+1;
	}
}
int powermod(int x,int y,int z)
{
	int s=1;
	while (y)
	{
		if (y&1) s=(long long)s*x%z;
		x=(long long)x*x%z;
		y>>=1;
	}
	return s;
}
void solve()
{
	memset(which,-1,sizeof(which));
	for (int i=m-1;i>=0;--i)
	{
		for (int j=lt[i]-1;j>=0;--j)
			if (which[t[i][j]-'0']==-1)
			{
				tot[i]=(tot[i]+(long long)powermod(10,len[i],MOD)*(t[i][j]-'0'))%MOD;
				len[i]=(len[i]+1)%PHI;
			}
			else
			{
				int p=which[t[i][j]-'0'];
				tot[i]=(tot[i]+(long long)powermod(10,len[i],MOD)*tot[p])%MOD;
				len[i]=(len[i]+len[p])%PHI;
			}
		which[d[i]]=i;
	}
	printf("%d\n",tot[0]);
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);
#endif
	init();
	solve();
#ifndef ONLINE_JUDGE
	fclose(stdin);fclose(stdout);
#endif
	return 0;
}