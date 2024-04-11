#include <cstdio>
#include <map>
const int SZ=1000,N=1e5+10;
int n,nw,ans,a[N],bkt[2*N];
std::map<int,int> map;
//for all |d| >= 100,the length doesn't exceed 1000.
//the length of (1,101,201,...,99901) is 1000.
//the length in the code is actually 1001.
//then enum the |d| < 100,using std::map.
inline int min(int x,int y){return x<y?x:y;}
inline int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]);
	for(int i=1;i<=n;++i){
		for(int j=i+1;j<=min(i+SZ,n);++j)if((a[j]-a[i])%(j-i)==0)nw=(a[j]-a[i])/(j-i)+N,ans=max(ans,++bkt[nw]+1);
		for(int j=i+1;j<=min(i+SZ,n);++j)if((a[j]-a[i])%(j-i)==0)--bkt[(a[j]-a[i])/(j-i)+N];
	}
	for(int i=-99;i<100;++i){
		map.clear();
		for(int j=1;j<=n;++j)ans=max(ans,++map[a[j]+i*j]);
	}
	printf("%d",n-ans);
	return 0;
}