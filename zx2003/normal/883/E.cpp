#include<cstdio>
#include<cstring>
const int N=55,M=1005;
int n,i,m,j,ans,z,bb[26];
char a[N],b[N],c[N];
bool b2[26],bbb[26];
int main(){
	scanf("%d%s%d",&n,a+1,&m);
	for(i=1;i<=n;++i)if(a[i]!='*')b2[a[i]-'a']=1;
	for(i=1;i<=m;++i){
		scanf("%s",b+1);
		for(j=1;j<=n;++j)if(a[j]!='*' && b[j]!=a[j])break;
		if(j>n){
			for(j=1;j<=n;++j)if(a[j]=='*' && b2[b[j]-'a'])break;
			if(j>n){
				++z;
				memset(bbb,0,sizeof bbb);
				for(j=1;j<=n;++j)if(a[j]=='*')bbb[b[j]-'a']=1;
				for(int i=0;i<26;++i)bb[i]+=bbb[i];
			}
		}
	}
	for(i=0;i<26;++i)ans+=bb[i]==z;
	return printf("%d\n",ans),0;
}