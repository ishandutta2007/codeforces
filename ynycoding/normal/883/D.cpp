#include <cstdio>
#include <algorithm>
#define N 1000005
int n, a[N], f[N], pos[N], sum[N], cnt, cnt1;
char s[N];
inline int ask(int l, int r) { return (l>r)?0:sum[r]-sum[l-1]; }
bool check(int d)
{
	for(int i=1; i<=pos[0]; ++i)
	{
		f[i]=0;
		if(ask(f[i-1]+1, pos[i]-d-1)==0) f[i]=std::max(f[i], std::max(f[i-1], pos[i]));
		if(ask(f[i-1]+1, pos[i]-1)==0) f[i]=std::max(f[i], std::max(f[i-1], pos[i]+d));
		if(i>1&&pos[i-1]>=pos[i]-d&&ask(f[i-2]+1, pos[i]-d-1)==0)
		f[i]=std::max(f[i], pos[i-1]+d);
	}
	return f[pos[0]]>n||(sum[f[pos[0]]]==sum[n]);
}
int main()
{
	scanf("%d%s", &n, s+1);
	for(int i=1; i<=n; ++i) a[i]=(s[i]=='*'?1:s[i]=='P'?2:0), cnt+=a[i]==2, cnt1+=a[i]==1;
	if(cnt==0||cnt1==0) return puts("0 0"), 0;
	if(cnt==1)
	{
		int cl=0, ml=0x3f3f3f3f, cr=0, mr=0, id;
		for(int i=1; a[i]!=2; ++i) if(a[i]==1) ++cl, ml=std::min(ml, i);
		for(int i=n; a[i]!=2; --i) if(a[i]==1) ++cr, mr=std::max(mr, i);
		for(id=1; a[id]!=2; ++id);
		printf("%d %d\n", std::max(cl, cr), (cl==cr?std::min(id-ml, mr-id):cl>cr?id-ml:mr-id));
		return 0;
	}
	for(int i=1; i<=n; ++i) sum[i]=sum[i-1]+(a[i]==1), (a[i]==2?pos[++pos[0]]=i:0);
	int l=0, r=n;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d %d\n", cnt1, l);
	return 0;
}