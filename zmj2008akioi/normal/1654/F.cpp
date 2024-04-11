#include <cstdio>
const int N=20,EXT=10;
int n,p,rk,a[(1<<N)+EXT],b[(1<<N)+EXT],sz[(1<<N)+EXT],cnt[(1<<N)+EXT],sum[(1<<N)+EXT],xa[(1<<N)+EXT],xb[(1<<N)+EXT],xid[(1<<N)+EXT],ya[(1<<N)+EXT],yb[(1<<N)+EXT],yid[(1<<N)+EXT];
char s[(1<<N)+EXT];
void resort(int d){
	rk=1;
	for(int i=0;i<(1<<n);++i)b[i]=a[i^(1<<d)];
	for(int i=0;i<(1<<N);++i)sz[i]=cnt[i]=0;
	for(int i=0;i<(1<<n);++i)++sz[b[i]];
	for(int i=0;i<(1<<N);++i)sum[i]=(i?sum[i-1]:0)+sz[i];
	for(int i=0;i<(1<<n);++i)p=cnt[b[i]]+(b[i]?sum[b[i]-1]:0),++cnt[b[i]],xa[p]=a[i],xb[p]=b[i],xid[p]=i;
	for(int i=0;i<(1<<N);++i)sz[i]=cnt[i]=0;
	for(int i=0;i<(1<<n);++i)++sz[xa[i]];
	for(int i=0;i<(1<<N);++i)sum[i]=(i?sum[i-1]:0)+sz[i];
	for(int i=0;i<(1<<n);++i)p=cnt[xa[i]]+(xa[i]?sum[xa[i]-1]:0),++cnt[xa[i]],ya[p]=xa[i],yb[p]=xb[i],yid[p]=xid[i];
	for(int i=0;i<(1<<n);++i){
		if(i&&(ya[i]!=ya[i-1]||yb[i]!=yb[i-1]))++rk;
		a[yid[i]]=rk;
	}
}
int main(){
	scanf("%d %s",&n,s);
	for(int i=0;i<(1<<n);++i)a[i]=s[i]-'a'+1;
	for(int i=0;i<n;++i)resort(i);
	for(int i=0;i<(1<<n);++i){
		if(a[i]==1){
			for(int j=0;j<(1<<n);++j)putchar(s[i^j]);
			return 0;
		}
	}
	return 0;
}