#include<bits/stdc++.h>
#define maxn 1001000
using namespace std;
int n,ans=0;
char S[maxn],T[maxn];
int main(){
	scanf("%d%s%s",&n,S+1,T+1);
	for(int i=1;i<=n;){
		if(S[i]==T[i])i++;
		else if(S[i+1]!=S[i]&&T[i+1]!=T[i])i+=2,ans++;
		else ans++,i++;
	}
	printf("%d",ans);
}