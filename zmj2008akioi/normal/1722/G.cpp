#include <cstdio>
#include <ctime>
#include <cstdlib>
#include <climits>
#include <unordered_map>
const int N=1e6+10;
int T,n,a[N];unsigned int t;
std::unordered_map<int,bool> map;
int rd(){t^=t<<13,t^=t>>17,t^=t<<5;return t&INT_MAX;}
void gen(){
	map.clear(),a[n]=0;
	for(int w,i=1;i<n;++i){
		do w=rd();while(map[w]);
		a[i]=w,a[n]^=w,map[w]=true;
	}
}
int main(){
	scanf("%d",&T),t=1;
	while(T--){
		scanf("%d",&n);
		do gen();while(map[a[n]]);
		for(int i=1;i<=n;++i)printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}