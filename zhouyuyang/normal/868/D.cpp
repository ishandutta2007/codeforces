#include<bits/stdc++.h>
using namespace std;
const int maxn=210;
int n,m,ans[maxn];
string s[maxn];
int solve(string s){
	for(int i=10;i>=0;i--){
		bool flag=0;
		for(int j=0;j<(1<<i);j++){
			string t;
			for(int k=0;k<i;k++)
				if(j&(1<<k)) t+='1';
				else t+='0';
			if(s.find(t)==s.npos){
				flag=1; break;
			}
		}
		if(!flag) return i;
	}
	return 0;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++) cin>>s[i];
	scanf("%d",&m);
	for(int i=n+1;i<=n+m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		s[i]=s[a]+s[b];
		if(s[i].length()>1000)
			s[i]=s[i].substr(0,500)+s[i].substr(s[i].length()-500,500);
		ans[i]=max(solve(s[i]),max(ans[a],ans[b]));
		printf("%d\n",ans[i]);
	}
}