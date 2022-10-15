#include <cstdio>
#include <vector>
const int N=1e5+10,P=1e9+7;
int n,f[N];long long ans;
std::vector<int> vec[N];
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int main(){
	scanf("%d",&n);
	for(int i=n;i;--i)for(int j=i;j<=n;j+=i)vec[j].push_back(i);
	for(int i=1;i<=n-2;++i){
		int w=n-i;
		for(int j:vec[w]){
			f[j]=w/j-1;
			for(int k:vec[w/j])if(k!=1)f[j]-=f[j*k];
			ans+=1ll*i*j/gcd(i,j)%P*f[j]%P;
		}
	}
	printf("%lld",ans%P);return 0;
}