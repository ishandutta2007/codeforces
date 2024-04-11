#include<cstdio>
int n,i,a[1010],b[1010],c[1010],d[10],w,e[10],ww,bb[1010];
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=n;++i){
		scanf("%d",b+i);
		if(a[i]==b[i])++bb[c[i]=a[i]];
			else d[++w]=i;
	}
	for(i=1;i<=n;++i)if(!bb[i])e[++ww]=i;
	if(w==1){
		c[d[1]]=e[1];
	}else if(w==2){
		if(b[d[1]]==e[1] && a[d[2]]==e[2])c[d[1]]=e[1],c[d[2]]=e[2];
		if(b[d[2]]==e[1] && a[d[1]]==e[2])c[d[2]]=e[1],c[d[1]]=e[2];
		if(b[d[1]]==e[2] && a[d[2]]==e[1])c[d[1]]=e[2],c[d[2]]=e[1];
		if(b[d[2]]==e[2] && a[d[1]]==e[1])c[d[2]]=e[2],c[d[1]]=e[1];
	}
	for(i=1;i<=n;++i)printf("%d ",c[i]);
	return 0;
}