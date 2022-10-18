#include <cstdio>
#include <cstring>
#include <algorithm>
#define N 1000005
int T, n, ext[N<<1], lim, id, pos, idx;
char t[N], s[N<<1];
void manacher(int n)
{
	id=pos=0;
	std::fill(ext, ext+n+1, 0);
	for(int i=2; i<=n; ++i)
	{
		if(i>pos||i+(ext[i]=std::min(ext[2*id-i], pos-i))==pos)
		{
			while(ext[i]+1<i&&s[i+ext[i]+1]==s[i-ext[i]-1]) ++ext[i];
			pos=ext[i]+i, id=i;
		}
	}
}
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%s", t+1);
		n=strlen(t+1);
		s[1]='#';
		for(int i=1; i<=n; ++i) s[i<<1]=t[i], s[i<<1|1]='#';
		s[(n+1)<<1]=0;
		manacher(n<<1|1);
		for(lim=0; (lim<<1)<=n&&t[lim+1]==t[n-lim]; ++lim);
		int ans=0;
		for(int i=1; i<=n+1; ++i) if(((i-ext[i])>>1)<=lim&&ans<i) ans=i, idx=i;
		for(int i=n+2; i<=(n<<1|1); ++i) if((((n<<1|1)-i-ext[i])>>1)<=lim&&ans<(n<<1|1)-i+1) ans=(n<<1|1)-i+1, idx=i;
		if(idx<=n+1)
		{
			for(int i=1; i<=idx; ++i) if(!(i&1)) putchar(s[i]);
			for(int i=idx-1; i; --i) if(!(i&1)) putchar(s[i]);
			puts("");
		}
		else
		{
			for(int i=(n<<1|1); i>=idx; --i) if(!(i&1)) putchar(s[i]);
			for(int i=idx+1; i<=(n<<1|1); ++i) if(!(i&1)) putchar(s[i]);
			puts("");
		}
	}
	return 0;
}