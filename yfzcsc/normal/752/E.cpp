#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,k,mx;
long long a[10001000];
long long cur;
bool b[10001000];
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1,j=0;i<=n;i++)scanf("%d",&j),mx=max(mx,j),a[j]++;
	for(int i=mx;i>=1;--i){
		cur+=a[i];
		if(i*2<=mx&&i*2>i&&!b[i*2])b[i*2]=true,cur-=a[i*2];
		if(i*2+1<=mx&&i*2+1>i&&!b[i*2+1])b[i*2+1]=true,cur-=a[i*2+1];
		if(i*2-1<=mx&&i*2-1>i&&!b[i*2-1])b[i*2-1]=true,cur-=a[i*2-1];
		if(cur>=k){printf("%d",i);return 0;}
	//	printf("[%d,%lld,%d]",i,cur,a[i]);
		if(i%2==0)a[i/2]+=a[i]*2;
		else a[i/2]+=a[i],a[i/2+1]+=a[i];
	}
	printf("-1");
}