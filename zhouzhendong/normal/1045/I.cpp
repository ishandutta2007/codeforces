#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=100005;
int n,v[N];
map <int,int> Map;
char s[N*10];
int main(){
	scanf("%d",&n);
	Map.clear();
	for (int i=1;i<=n;i++){
		scanf("%s",s+1);
		int len=strlen(s+1);
		v[i]=0;
		for (int j=1;j<=len;j++)
			v[i]^=1<<(s[j]-'a');
		Map[v[i]]++;
	}
	LL ans=0;
	for (int i=1;i<=n;i++){
		ans+=Map[v[i]]-1;
		for (int j=0;j<26;j++)
			ans+=Map[v[i]^(1<<j)];
	}
	printf("%I64d",ans/2);
	return 0;
}