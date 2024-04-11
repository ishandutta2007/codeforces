#include<bits/stdc++.h>
const int N=150005;
int T,n,i,j,k,f[N][5],ch[5][26],ans,u;
char c[N],d[N];
int main(){
	ch[0]['t'-'a']=1;
	ch[0]['o'-'a']=3;
	ch[1]['w'-'a']=2;
	ch[1]['o'-'a']=3;
	ch[1]['t'-'a']=1;
	ch[2]['o'-'a']=-1;
	ch[2]['t'-'a']=1;
	ch[3]['n'-'a']=4;
	ch[3]['t'-'a']=1;
	ch[3]['o'-'a']=3;
	ch[4]['e'-'a']=-1;
	ch[4]['o'-'a']=3;
	ch[4]['t'-'a']=1;
	for(scanf("%d",&T);T--;){
		scanf("%s",c+1);n=strlen(c+1);
		for(i=1;i<5;++i)f[0][i]=-N;
		for(i=1;i<=n;++i){
			memcpy(f[i],f[i-1],20);
			for(j=0;j<5;++j)if(ch[j][c[i]-'a']!=-1)
				f[i][ch[j][c[i]-'a']]=std::max(f[i-1][j]+1,f[i][ch[j][c[i]-'a']]);
		}
		ans=0;
		for(i=0;i<5;++i)if(f[n][i]>ans)ans=f[n][i],u=i;
		d[ans+1]=0;
		printf("%d\n",n-ans);
		for(i=ans,j=n;i;--i){
			for(;f[j-1][u]==i;--j)
				printf("%d ",j);
			for(k=0;k<5;++k)if(ch[k][c[j]-'a']==u && f[j-1][k]+1==i){u=k;break;}
			d[i]=c[j]-'a';--j;
		}
		for(;j;--j)printf("%d ",j);
		puts("");
	}
}