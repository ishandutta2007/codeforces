#include<stdio.h>
inline int Min(int p,int q){return p<q?p:q;}
char c[1000002],d[1000002],e[1000002];
int t,n,r[1000002];
int main(){
	scanf("%d",&t);
	while(t--){
		scanf("%s",c+1);
		for(n=1;c[n];n++);n--;
		if(n==1){
			puts(c+1);c[1]=0;continue;
		}int pos=0;
		for(pos=1;pos+pos<=n;pos++)if(c[pos]!=c[n+1-pos])break;
		if(pos+pos>n&&c[pos]==c[n+1-pos]){
			puts(c+1);for(int i=1;i<=n;i++)c[i]=0;continue;
		}pos--;int m=n-pos-pos;
		for(int i=1;i<=m;i++){
			d[i]=c[i+pos];
		}int len1=0,len2=0;
		for(int i=m;i>=1;i--){
			bool f=1;
			for(int j=1;j<=i;j++)f&=d[j]==d[i+1-j];
			if(f){len1=i;break;}
		}for(int i=1;i<=m;i++){
			d[m+1-i]=c[i+pos];
		}for(int i=m;i>=1;i--){
			bool f=1;
			for(int j=1;j<=i;j++)f&=d[j]==d[i+1-j];
			if(f){len2=i;break;}
		}for(int i=1;i<=pos;i++)putchar(c[i]);
		if(len1>=len2){
			for(int i=pos+1;i<=pos+len1;i++)putchar(c[i]);
		}else for(int i=n+1-pos-len2;i<=n-pos;i++)putchar(c[i]);
		for(int i=n+1-pos;i<=n;i++)putchar(c[i]);puts("");
		for(int i=1;i<=n;i++)c[i]=0;
	}
}