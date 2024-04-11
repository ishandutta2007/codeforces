#include<bits/stdc++.h>
const int N=105;
int n,m,i,j,k,s[N],h[N],id[N],a[N],l[N],r[N];
int fr[N],fl[N];
bool cmp(int x,int y){return s[x]<s[y];}
int main(){
	scanf("%d%d",&n,&m);
	for(i=1;i<=m;++i)scanf("%d%d",s+i,h+i),id[i]=i;
	if(m==1){
		printf("%d\n1\n",s[1]);
		return 0;
	}
	std::sort(id+1,id+m+1,cmp);
	for(i=1;i<=n;++i)scanf("%d",a+i);
	for(i=1;i<=m;++i){
		long long ss;
		ss=h[i];
		for(l[i]=s[i];l[i] && ss>=0;ss+=a[--l[i]]);++l[i];
		ss=h[i];
		for(r[i]=s[i];r[i]<=n && ss>=0;ss+=a[++r[i]]);--r[i];
	}
	fr[m]=m;
	for(i=m-1;i;--i){
		for(j=i+1;j<=m;++j)if(fr[j] && l[id[j]]<=s[id[i]])fr[i]=j;
	}
	fl[1]=1;
	for(i=2;i<=m;++i){
		for(j=1;j<i;++j)if(fl[j] && r[id[j]]>=s[id[i]])fl[i]=j;
	}
	if(fr[1]){
		static bool bb[N];
		static int st[N];int w=0;
		printf("%d\n",s[id[1]]);
		for(j=1;j<m;j=fr[j])st[++w]=id[j];st[++w]=id[m];
		std::reverse(st+1,st+w+1);
		for(;w;--w)bb[st[w]]=1,printf("%d ",st[w]);
		for(j=1;j<=m;++j)if(!bb[j])printf("%d ",j);
		exit(0);
	}
	if(fl[m]){
		static bool bb[N];
		 static int st[N];int w=0;
		printf("%d\n",s[id[m]]);
		 for(j=m;j>1;j=fl[j])st[++w]=id[j];st[++w]=id[1];
		std::reverse(st+1,st+w+1);
		 for(;w;--w)bb[st[w]]=1,printf("%d ",st[w]);
		 for(j=1;j<=m;++j)if(!bb[j])printf("%d ",j);
		 exit(0);
	}
	for(i=1;i<m;++i)
		for(k=i+1;k<=m;++k)if(fl[i] && fr[k] && r[id[i]]+1>=l[id[k]]){
		printf("%d\n",l[id[k]]);
		static int st[N];int w=0;
		static bool bb[N];
		
		for(j=k;j<m;j=fr[j])st[++w]=id[j];st[++w]=id[m];
		std::reverse(st+1,st+w+1);
		for(;w;--w)bb[st[w]]=1,printf("%d ",st[w]);w=0;
		
		for(j=i;j>1;j=fl[j])st[++w]=id[j];st[++w]=id[1];
		std::reverse(st+1,st+w+1);
		for(;w;--w)bb[st[w]]=1,printf("%d ",st[w]);
		
		 for(j=1;j<=m;++j)if(!bb[j])printf("%d ",j);
		 exit(0);
	}
	puts("-1");
	return 0;
}