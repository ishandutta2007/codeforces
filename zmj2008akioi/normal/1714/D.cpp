#include <cstdio>
#include <cstring>
const int N=110;
int T,n,m,top,mt[N],mp[N],len[N],stk[N];
char s[N],t[N];
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s %d",t+1,&n);
		m=strlen(t+1),top=0;
		for(int i=1;i<=m;++i)mt[i]=0;
		for(int i=1;i<=n;++i){
			scanf("%s",s+1),len[i]=strlen(s+1);
			for(int j=1;j+len[i]-1<=m;++j){
				bool tag=true;
				for(int k=1;k<=len[i];++k)tag&=s[k]==t[j+k-1];
				if(!tag)continue;
				for(int k=1;k<=len[i];++k){
					if(mt[j+k-1]<j+len[i]-1){
						mt[j+k-1]=j+len[i]-1;
						mp[j+k-1]=i;
					}
				}
			}
		}
		bool tag=true;
		for(int i=1;i<=m;){
			if(!mt[i]){puts("-1"),tag=false;break;}
			stk[++top]=i,i=mt[i]+1;
		}
		if(!tag)continue;
		printf("%d\n",top);
		while(top){
			int u=stk[top--];
			printf("%d %d\n",mp[u],mt[u]-len[mp[u]]+1);
		}
	}
	return 0;
}