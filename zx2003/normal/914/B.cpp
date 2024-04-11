#include<cstdio>
int n,i,a[100005],cnt[100005];
bool fl;
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i){
		scanf("%d",a+i);
		++cnt[a[i]];
	}
	for(i=1;i<=100000;++i)if(cnt[i]&1)break;
	puts(i>100000?"Agasa":"Conan");
	return 0;
}