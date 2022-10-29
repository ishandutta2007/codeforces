#include<bits/stdc++.h>
using namespace std;
int n,sum[100100],mn[100100];
char s[1000100];
map<int,int>st;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		int len=strlen(s);
		for(int j=0;j<len;++j){
			if(s[j]=='(')sum[i]++;
			else sum[i]--;
			mn[i]=min(mn[i],sum[i]);
		}
	}
	for(int i=1;i<=n;++i){
		if(mn[i]>=0){
			st[sum[i]]++;
		}
	}
	int ans=0;
	for(int i=1;i<=n;++i){
		if(mn[i]==sum[i]&&mn[i]<0){
			if(st[-mn[i]]){
				ans++;
				st[-mn[i]]--;
			}
		}
	}
	ans+=st[0]/2;
	printf("%d",ans);
}