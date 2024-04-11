#include <cstdio>
#include <cstring>
#include <vector>
const int G=26,N=2e5+10;
int T,n;char s[N];
std::vector<int> vec[G];
template<typename T>T rv(T x){return x>T()?x:-x;}
template<typename T>int sgn(T x){return x>0?1:-1;}
template<typename T>void swp(T &x,T &y){T z=x;x=y;y=z;}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%s",s+1),n=strlen(s+1);int sum=0;
		for(int i=0;i<G;++i)vec[i].clear();
		for(int i=2;i<n;++i)vec[s[i]-'a'].push_back(i);
		for(int t=sgn(s[n]-s[1]),i=s[1];i!=s[n]+t;i+=t)sum+=vec[i-'a'].size();
		printf("%d %d\n%d",rv(s[n]-s[1]),sum+2,1);
		for(int t=sgn(s[n]-s[1]),i=s[1];i!=s[n]+t;i+=t)for(int j:vec[i-'a'])printf(" %d",j);
		printf(" %d\n",n);
	}
	return 0;
}