#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[100005],res[100005],tot;
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	int s=0;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),s+=a[i];
	if(s%k!=0){puts("No"); return 0;}
	int w=s/k;
	int cnt=0,su=0;
	for(int i=1;i<=n;i++){
		su+=a[i]; cnt++;
		if(su==w){
			res[++tot]=cnt;
			cnt=0; su=0;
		}
		if(su>w)break;
	}
	if(tot<k){puts("No"); return 0;}
	puts("Yes");
	for(int i=1;i<=k;i++)printf("%d ",res[i]); puts("");
	return 0;
}