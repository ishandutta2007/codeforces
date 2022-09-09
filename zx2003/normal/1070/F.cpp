#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[500005],b[500005],c[500005];
int main(){
	int n;
	scanf("%d",&n);
	int s=0,tot=0;
	for(int i=1;i<=n;i++){
		int t,x;
		scanf("%d%d",&t,&x);
		if(t==0)a[++a[0]]=x;
		if(t==1)b[++b[0]]=x;
		if(t==10)c[++c[0]]=x;
		if(t==11)s+=x,tot++;
	}
	if(b[0]<c[0])swap(b,c);
	sort(b+1,b+b[0]+1);
	reverse(b+1,b+b[0]+1);
	for(int i=1;i<=c[0];i++)s+=c[i],s+=b[i];
	for(int i=c[0]+1;i<=b[0];i++)a[++a[0]]=b[i];
	sort(a+1,a+a[0]+1);
	reverse(a+1,a+a[0]+1);
	for(int i=1;i<=min(a[0],tot);i++)s+=a[i];
	printf("%d\n",s);
	return 0;
}