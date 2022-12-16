#include<cstring>
#include<algorithm>
#include<stdio.h>
#define N 1000005
#define Dict 26
using namespace std;
char c[N];
int a[N][Dict],fail[N],q[N];
int to[N],Next[N],last[N],len[N],cnt;
int f[N][2];
int n,test,tot,Q,ans,i,j,k,l,p,num,x,y;
inline void add(int u,int v) {	
	Next[++cnt]=last[u]; last[u]=cnt; to[cnt]=v;
}
inline void Insert(int &p,int ch) {
    if (a[p][ch]) p=a[p][ch];
    else a[p][ch]=++tot,p=tot;
}
inline void buildAC() { 
	int H=1,T=1;
	q[1]=1;
	for (int i=0;i<Dict;i++) if (!a[1][i]) a[1][i]=1;
    else fail[q[++T]=a[1][i]]=1;
	while (H<T) {
		int k=q[++H];
    	for (int i=0;i<Dict;i++)
    	if (!a[k][i]) a[k][i]=a[fail[k]][i];
    	else fail[q[++T]=a[k][i]]=a[fail[k]][i];
	}
}
int main() {
    scanf("%d",&test);
  	while (test--) {
  		tot=1;len[1]=0;
  		scanf("%d",&n);
    	for (i=1;i<=n;i++) {
			scanf("%s",c);
        	l=strlen(c);
        	int gt=1;
        	for (j=0;j<l;j++) {
				Insert(gt,c[j]-97);
				len[gt]=j+1;
			}
		}
      	buildAC();
      	
      	for (i=2;i<=tot;i++) if (len[fail[q[i]]]==len[q[i]]-1) 
		  add(fail[q[i]],q[i]);
      	else add(1,q[i]);
      	for (i=tot;i>1;i--) {
      		f[q[i]][1]=1;
      		f[q[i]][0]=0;
      		for (j=last[q[i]];j;j=Next[j]) f[q[i]][0]+=f[to[j]][1],f[q[i]][1]+=min(f[to[j]][0],f[to[j]][1]);
      	}
      	ans=tot-1;
      	for (i=last[1];i;i=Next[i]) ans-=min(f[to[i]][0],f[to[i]][1]);
      	printf("%d\n",ans);
      	for (i=1;i<=tot;i++) len[i]=last[i]=fail[i]=0;
      	for (i=1;i<=tot;i++) for (j=0;j<Dict;j++) a[i][j]=0;
      	tot=cnt=0;
  	}
}