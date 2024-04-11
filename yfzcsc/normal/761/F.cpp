#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#define maxn 1010
#define maxk 300100
using namespace std;
long long tag[26][maxn][maxn],A[maxn][maxn];
long long a[maxk],b[maxk],c[maxk],d[maxk],n,m,p,col[maxk];
long long base,ans=1ll<<60,now,ps[maxn][maxn];
char ch[2],str[maxn][maxn];
int main(){
	scanf("%lld%lld%lld",&n,&m,&p);
	for(int i=1;i<=n;++i)scanf("%s",str[i]+1);
	for(int i=1;i<=p;++i){
		scanf("%lld%lld%lld%lld%s",&a[i],&b[i],&c[i],&d[i],ch);
		col[i]=ch[0]-'a';
		tag[ch[0]-'a'][a[i]][b[i]]++;
		tag[ch[0]-'a'][a[i]][d[i]+1]--;
		tag[ch[0]-'a'][c[i]+1][b[i]]--;
		tag[ch[0]-'a'][c[i]+1][d[i]+1]++;
		
		A[a[i]][b[i]]--;
		A[a[i]][d[i]+1]++;
		A[c[i]+1][b[i]]++;
		A[c[i]+1][d[i]+1]--;
		A[1][1]++;
	}
	for(int c=0;c<26;++c)for(int i=1;i<=n;i++)
		for(int j=1;j<=m;++j)
			tag[c][i][j]=tag[c][i-1][j]+tag[c][i][j-1]-tag[c][i-1][j-1]+tag[c][i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;++j)
			tag[str[i][j]-'a'][i][j]+=(A[i][j]=A[i-1][j]+A[i][j-1]-A[i-1][j-1]+A[i][j]);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int c=0;c<26;++c)
				ps[i][j]+=1ll*tag[c][i][j]*abs(str[i][j]-'a'-c);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			ps[i][j]=ps[i-1][j]+ps[i][j-1]-ps[i-1][j-1]+ps[i][j];
	for(int c=0;c<26;++c)for(int i=1;i<=n;i++)
		for(int j=1;j<=m;++j)
			tag[c][i][j]=tag[c][i-1][j]+tag[c][i][j-1]-tag[c][i-1][j-1]+tag[c][i][j];
	for(int i=1;i<=p;++i){
		long long now=ps[n][m]-(ps[c[i]][d[i]]-ps[a[i]-1][d[i]]-ps[c[i]][b[i]-1]+ps[a[i]-1][b[i]-1]);
//		printf("[%lld]",now);
		for(int cx=0;cx<26;++cx)
			now+=1ll*abs(cx-col[i])*(tag[cx][c[i]][d[i]]-tag[cx][a[i]-1][d[i]]-tag[cx][c[i]][b[i]-1]+tag[cx][a[i]-1][b[i]-1]);
//		printf("[%lld]",now);
		ans=min(ans,now);
	}
	printf("%I64d",ans);
}