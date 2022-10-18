#include <cstdio>
#include <cstring>
#include <algorithm>
#define ll unsigned int
#define N 135
int n, p, q;
ll ans, out, ret[N], tr[N], tmp[N], cur;
inline void mul(ll *A, ll *B, ll *C)
{
	std::fill(tmp, tmp+p+1, 0);
	for(int i=0; i<=p; ++i) for(int j=0; i+j<=p; ++j) tmp[i+j]+=A[i]*B[j];
	memcpy(C, tmp, sizeof(int)*(p+1));
}
int main()
{
	scanf("%d%d%d", &n, &p, &q);
	ret[0]=1, tr[0]=tr[1]=1;
	int k=n;
	while(k)
	{
		if(k&1) mul(ret, tr, ret);
		k>>=1;
		mul(tr, tr, tr);
	}
	p=std::min(p, (n-1));
	for(int i=1; i<=q; ++i)
	{
		ans=0, cur=1;
		for(int j=0; j<=p; ++j, cur*=i) ans+=ret[j]*cur;
		out^=ans*i;
	}
	printf("%u\n", out);
	return 0;
}