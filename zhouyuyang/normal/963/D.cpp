#include<bits/stdc++.h>
#define N 100005
using namespace std;
bitset<N> b[26],tmp;
char s[N],t[N];
int main(){
	scanf("%s",s);
	int n=strlen(s);
	for (int i=0;i<n;i++)
		b[s[i]-'a'][i]=1;
	int Q; scanf("%d",&Q);
	while (Q--){
		int k; scanf("%d%s",&k,t);
		int m=strlen(t);
		tmp.set();
		for (int i=0;i<m;i++)
			tmp&=b[t[i]-'a']>>i;
		if (tmp.count()<k){
			puts("-1");
			continue;
		}
		vector<int> v;
		for (int i=tmp._Find_first();i<n;i=tmp._Find_next(i))
			v.push_back(i);
		int ans=1e9;
		for (int i=0;i+k-1<v.size();i++)
			ans=min(ans,v[i+k-1]-v[i]+m);
		printf("%d\n",ans);
	}
}