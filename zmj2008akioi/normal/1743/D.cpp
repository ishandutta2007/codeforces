#include <cstdio>
#include <vector>
const int N=1e6+10;
int n;char *s;std::vector<int> vec;
int main(){
	s=new char[N];
	scanf("%d %s",&n,s+1);
	while(n&&s[1]=='0')++s,--n;
	if(!n){putchar('0');return 0;}
	int p=1;while(p<=n&&s[p]=='1')++p;
	if(p>n){for(int i=1;i<=n;++i)putchar('1');return 0;}
	for(int i=1;i<p;++i)vec.push_back(i);
	for(int i=1;i<=p;++i)putchar('1');
	for(int i=p+1;i<=n;++i){
		if(s[i]=='1'){putchar('1');continue;}
		std::vector<int> A,B;
		for(int j:vec)(s[j+(i-p)]=='1'?A:B).push_back(j);
		if(A.size())putchar('1'),vec=A;else putchar('0'),vec=B;
	}
	return 0;
}