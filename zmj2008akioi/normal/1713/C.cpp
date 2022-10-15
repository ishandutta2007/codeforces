#include <cstdio>
#include <vector>
const int N=1e5+10;
int T,n,ans[N];
std::vector<int> vec;
int main(){
	scanf("%d",&T);
	for(int i=0;i<=500;++i)vec.push_back(i*i);
	while(T--){
		scanf("%d",&n);
		for(int p,i=n-1;~i;i=p-1){
			p=*std::lower_bound(vec.begin(),vec.end(),i)-i;
			for(int j=p;j<=i;++j)ans[j]=i+p-j;
		}
		for(int i=0;i<n;++i)printf("%d ",ans[i]);
		putchar('\n');
	}
	return 0;
}