#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int a,b,seq[1000],ans;
bool search(int i,ll x){
	seq[i]=x;
	if(x>b)return false;
	if(x==b){
		ans=i;
		return true;
	}
	
	if(search(i+1,x*2))return true;
	if(search(i+1,x*10+1))return true;
	return false;
}
int main(){
	scanf("%d%d",&a,&b);
	if(search(1,a)){
		printf("YES\n%d\n",ans);
		for(int i=1;i<=ans;++i)printf("%d ",seq[i]);
	} else printf("NO\n");
}