#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstdlib>
using namespace std;
int k,ans=0;
bool check(int v){
	int res=0;
	while (v){
		res+=v%10,v/=10;
		if (res>10)
			break;
	}
	return res==10;
}
int main(){
	scanf("%d",&k);
	while (k-=check(++ans));
	printf("%d",ans);
	return 0;
}