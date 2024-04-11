#include<cstdio>
#include<cstring>
int n,k,x,i,j,o,be[100010],l[100010],m,a[3000010],p;
char c[3000010],d[3000010];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%s%d",c+o+1,&k);
		be[i]=o+1;
		l[i]=strlen(c+o+1);
		o+=l[i];
		for(j=1;j<=k;++j){
			scanf("%d",&x);
			if(x+l[i]-1>m)m=x+l[i]-1;
			if(l[i]>l[a[x]])a[x]=i;
		}
	}
	j=0;
	for(i=1;i<=m;++i){
		if(i>j && !a[i])d[i]='a';
			else{
				if(a[i] && i+l[a[i]]-1>j){
					if(i>j)p=i;
						else p=j+1;
					for(;p<=i+l[a[i]]-1;++p)
						d[p]=c[be[a[i]]+p-i];
					j=i+l[a[i]]-1;
				}
			}
	}
	for(i=1;i<=m;++i)putchar(d[i]);
	return 0;
}