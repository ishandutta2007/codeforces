#include<bits/stdc++.h>
const int N=1e5+5;
int n,a[N],b[N],ia[N],i,ans;
void getinv(int*a){
/*
	int b[N];
	for(int i=1;i<=n;++i)b[a[i]]=i;
	memcpy(a+1,b+1,n<<2);
*/
	std::reverse(a+1,a+n+1);
}
int main(){
	scanf("%d",&n);
	for(i=1;i<=n;++i)scanf("%d",a+i);getinv(a);
	for(i=1;i<=n;++i)scanf("%d",b+i);getinv(b);
	for(i=1;i<=n;++i)ia[a[i]]=i;
	int mx=0;
	for(i=1;i<=n;++i)if(ia[b[i]]>mx)mx=ia[b[i]];else ++ans;
	printf("%d\n",ans);
	return 0;
}