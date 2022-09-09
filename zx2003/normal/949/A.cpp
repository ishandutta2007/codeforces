#include<bits/stdc++.h>
const int N=200005;
char c[N];
int w0,st0[N],w1,st1[N],i,lst[N],n,j,w,a[N],cnt;;
bool vi[N];
int main(){
	scanf("%s",c+1);n=strlen(c+1);
	for(i=1;i<=n;++i)
		if(c[i]=='0'){
			if(w1)lst[i]=st1[w1--];
			st0[++w0]=i;
		}else{
			if(w0){
				lst[i]=st0[w0--];
				st1[++w1]=i;
			}else return puts("-1"),0;
		}
	if(w1)return puts("-1"),0;
	for(i=n;i;--i)if(!vi[i]){
		for(j=i;j;j=lst[j])vi[j]=1;
		++cnt;
	}
	printf("%d\n",cnt);memset(vi,0,sizeof vi);
	for(i=n;i;--i)if(!vi[i]){
		for(j=i,w=0;j;j=lst[j])vi[a[++w]=j]=1;
		std::reverse(a+1,a+w+1);
		printf("%d ",w);for(j=1;j<=w;++j)printf("%d ",a[j]);puts("");
	}
	return 0;
}