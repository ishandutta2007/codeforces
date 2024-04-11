#include <cstdio>
#include <cstring>
#include <algorithm>
const int N=5000005;
int n, is, len[N], pos[N], tp;
char s[N];
void prt(void)
{
	tp=0;
	for(int l=1; l<=n; ++l) if(s[l]&&!s[l-1])
	{
		int r=l;
		while(s[r+1]) ++r;
		len[++tp]=r-l+1;
	}
	printf("%d\n", tp);
	for(int i=1; i<=tp; ++i) printf("%d ", len[i]);
}
int main()
{
	scanf("%s", s+1);
	n=strlen(s+1);
	for(int i=1; i<=n; ++i) s[i]=s[i]=='#', is|=s[i];
	if(!is)
	{
		printf("%d\n", 0);
		return 0;
	}
	if(s[1]) len[++tp]=0;
	for(int l=1, r; l<=n; l=r+1)
	{
		while(s[l]) ++l;
		if(l>n) break;
		r=l;
		while(r<n&&!s[r+1]) ++r;
		len[++tp]=r-l+1-(s[l-1]&s[r+1]);
		pos[tp]=l+(s[l-1]);
	}
	if(s[n]) len[++tp]=0;
//	for(int i=1; i<=tp; ++i) printf("%d %d\n", pos[i], len[i]);
	int o=0;
	for(int i=1; i<=tp; ++i) o|=!len[i];
	if(o)
	{
		for(int i=1; i<=tp; ++i) if(len[i]) return puts("-1"), 0;
		prt();
		return 0;
	}
	int is1=1, is2=1, is3=1;
	for(int i=1; i<=tp; ++i)
	{
		if(len[i]&1)
		{
			if(len[i]<5) is2=0;
			if(len[i]<3) is3=0;
		}
		else
		{
			is1=0;
			if(len[i]<6) is3=0;
		}
	}
	if(!is1&&!is2&&!is3) return puts("-1"), 0;
	int rlen=is1?1:is2?2:3;
	for(int i=1; i<=n; ++i) if(s[i]&&!s[i-1])
	{
		std::fill(s+i-rlen, s+i, 1);
	}
//	fprintf(stderr, "%d %d %d\n", is1, is2, is3);
	for(int i=1; i<=tp; ++i)
	{
		int l=pos[i], r=pos[i]+len[i]-1;
		if(is1) for(int j=l; j<r; j+=2) s[j]=1;
		else if(is2)
		{
			if(len[i]&1)
			{
				s[l]=s[l+1]=1;
				for(int j=l+3; j+1<r; j+=2) s[j]=1;
			}
			else
			{
				for(int j=l; j+2<=r; j+=2) s[j]=1;
			}
		}
		else if(is3)
		{
			if(len[i]&1)
			{
				for(int j=l; j+4<=r; j+=2) s[j]=1;
			}
			else
			{
				s[l]=s[l+1]=1;
				for(int j=l+3; j+4<=r; j+=2) s[j]=1;
			}
		}
	}
	prt();
	return 0;
}