#include<cstdio>
#include<cstdlib>
#include<set>
#include<cstring>
using namespace std;
const int N=100005;
int n,i,j,k,a[20],x,y;
int main(){
	//freopen("c.txt","r",stdin);
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){
		for(j=1,x=0;j<=k;++j)scanf("%d",&y),x|=y<<(k-j);
		a[x]++;
	}
	for(i=0;i<16;++i)
		for(j=0;j<16;++j)if((i&j)==0 && a[i] && a[j])return puts("YES"),0;
	return puts("NO"),0;
}