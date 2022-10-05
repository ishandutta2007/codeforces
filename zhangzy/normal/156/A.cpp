#include<bits/stdc++.h>
using namespace std;

char s[2333],t[2333];
int ls,lt,ans=1e5,cnt;

int main(){
	scanf("%s%s",s+1,t+1);
	ls=strlen(s+1); lt=strlen(t+1);
	for (int i=1;i<=ls;i++){
		cnt=max(0,lt-(ls-i+1));
		for (int j=1;j<=lt&&i+j-1<=ls;j++)
			cnt+=s[i+j-1]!=t[j];
		ans=min(ans,cnt);
	}
	for (int i=2;i<=lt;i++){
		cnt=i-1;
		for (int j=1;i+j-1<=lt;j++)
			if (j<=ls)
				cnt+=s[j]!=t[i+j-1];
			else
				cnt++;
		ans=min(ans,cnt);
	}
	cout<<ans;
}