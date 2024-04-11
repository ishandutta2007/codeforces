#include<cstdio>
#include<cstring>
const int N=5005;
int i,j,n,a[N],b[N],p[N],q[N],ans,cnt[N],c[N];
int main(){
	scanf("%d",&n);
	for(i=0;i<n;++i){
		printf("? %d 0\n",i);
		fflush(stdout);
		scanf("%d",a+i);
	}
	for(i=0;i<n;++i){
		printf("? 0 %d\n",i);
		fflush(stdout);
		scanf("%d",b+i);a[i]^=*b;
	}
	for(i=0;i<n;++i){
		for(j=0;j<n;++j)p[j]=a[j]^i;
		for(j=0;j<n;++j)q[j]=b[j]^i;
		for(j=0;j<n && p[j]<n && q[j]<n && p[q[j]]==j;++j);
		if(j<n)continue;
		memset(cnt,0,n<<2);
		for(j=0;j<n;++j)++cnt[p[j]];
		for(j=0;j<n && cnt[j];++j);
		if(j<n)continue;
		memset(cnt,0,n<<2);
		for(j=0;j<n;++j)++cnt[q[j]];
		for(j=0;j<n && cnt[j];++j);
		if(j<n)continue;
		++ans;
		memcpy(c,p,n<<2);
	}
	printf("!\n%d\n",ans);
	for(i=0;i<n;++i)printf("%d ",c[i]);
	return 0;
}