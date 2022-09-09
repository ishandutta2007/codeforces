#include<bits/stdc++.h>
const int N=1005;
int n,a[N],id[N],i,j,aa[N];
bool cmp(int x,int y){return a[x]<a[y];}
char c[N];
std::vector<int>ve[N];int xb,val[N];
int main(){
	scanf("%d",&n);for(i=1;i<=n;++i)scanf("%d",a+i),id[i]=i;
	std::sort(id+1,id+n+1,cmp);
	if(a[id[n]]==1){puts("1");for(i=1;i<=n;++i)putchar('1');putchar('\n');return 0;}
	if(a[id[n]]==a[id[n-1]]){
		ve[1]={id[n]};val[1]=1;ve[2]={id[n-1]};val[2]=1;
		ve[3]={id[n],id[n-1]};val[3]=a[id[n]]-1;xb=3;
	}else{
		ve[1]={id[n]};val[1]=a[id[n]]-a[id[n-1]];
		ve[2]={id[n-1],id[n]};val[2]=a[id[n-1]];xb=2;
	}
	for(i=n-2;i;--i){
		int mn=N,mnid,x=a[id[i]];
		for(j=1;j<=xb;++j)if(val[j]>1 && val[j]<mn)mn=val[j],mnid=j;
		if(mn>x && mn<N)val[mnid]-=x,val[++xb]=x,ve[xb]=ve[mnid],ve[xb].push_back(id[i]);else{
			if(mn<N)val[mnid]=1,val[++xb]=mn-1,ve[xb]=ve[mnid],ve[xb].push_back(id[i]),x-=mn-1;
			for(j=1;j<=xb && x;++j)if(j!=mnid){
				if(val[j]<=x){x-=val[j];ve[j].push_back(id[i]);continue;}
				val[j]-=x;ve[++xb]=ve[j];ve[xb].push_back(id[i]);val[xb]=x;x=0;
			}
		}
	}
	printf("%d\n",xb);
	for(i=1;i<=xb;++i){
		memset(c+1,'0',n);for(int x:ve[i])c[x]='1';
		puts(c+1);
	}
	return 0;
}