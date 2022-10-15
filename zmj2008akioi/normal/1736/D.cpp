#include <cstdio>
#include <vector>
const int N=2e5+10;
int T,n;char s[N];
std::vector<int> vec;
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d %s",&n,s+1);
		char ls='1';vec.clear();int sum=0;
		for(int i=1;i<=2*n;i+=2){
			sum+=(s[i]^48)+(s[i+1]^48);
			if(s[i]!=s[i+1]){
				if(ls==s[i])vec.push_back(i+1);
				else vec.push_back(i);ls^=1;
			}
		}
		if(sum&1){puts("-1");continue;}
		printf("%d ",(int)vec.size());
		for(int i:vec)printf("%d ",i);putchar('\n');
		for(int i=1;i<=2*n;i+=2)printf("%d ",i);putchar('\n');
	}
	return 0;
}