//#include<stdio.h>
//#include<memory.h>
//int p[22][22],n,t,f[22],mk[22],d[22],st[102],tp=0;
//char c[200002],e[200002];
//inline int gf(int p){return p==f[p]?p:(f[p]=gf(f[p]));}
//int main(){
//	scanf("%d",&t);
//	while(t--){
//		scanf("%d%s%s",&n,c+1,e+1);
//		memset(p,0,sizeof(p));memset(mk,0,sizeof(mk));memset(d,0,sizeof(d));
//		for(int i=1;i<=n;i++)p[c[i]-'a'][e[i]-'a']=1;
//		for(int i=0;i<20;i++)f[i]=i;
//		for(int i=0;i<20;i++){
//			for(int j=0;j<20;j++)if(i!=j&&p[i][j]&&gf(i)!=gf(j))f[f[i]]=f[j];
//		}for(int i=0;i<20;i++)gf(i),p[i][i]=0;
//		int ans=20,minc=20;for(int i=0;i<20;i++)if(f[i]==i)ans--;
//		for(int B=0;B<1048576;B++){
//			int cntt=20-__builtin_popcount(B),cnttt=20-cntt;if(cnttt>=minc)continue;memset(d,0,sizeof(d));
//			for(int i=0;i<20;i++)if(!(B>>i&1))for(int j=0;j<20;j++)if(i!=j&&p[i][j]&&!(B>>j&1))d[j]++;tp=0;
//			for(int i=0;i<20;i++)if(!(B>>i&1)&&!d[i])st[++tp]=i;
//			while(tp){
//				int t=st[tp--];cntt--;
//				for(int i=0;i<20;i++)if(!(B>>i&1)&&i!=t&&p[t][i])!--d[i]&&(st[++tp]=i);
//			}if(!cntt)minc=cnttt;
//		}printf("%d\n",ans+minc);
//	}
//}
#include<stdio.h>
int a[100002],n,t;
int main(){
	scanf("%d",&t);
	while(t--){
		int cnt=0;
		scanf("%d",&n);for(int i=1;i<=n;i++)scanf("%d",&a[i]),cnt^=a[i];
		if(!cnt){
			puts("DRAW");continue;
		}while(cnt!=(cnt&-cnt))cnt^=cnt&-cnt;
		int cntt=0;for(int i=1;i<=n;i++)if(a[i]&cnt)cntt++;
		if(n&1){
			if(cntt%4==1)puts("WIN");
			else puts("LOSE");
		}else{
			puts("WIN");
		}
	}
}