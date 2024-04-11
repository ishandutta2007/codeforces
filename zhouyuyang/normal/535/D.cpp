#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 1000005
#define mo 1000000007
using namespace std;
char s[N];
int n,m,len,ans;
int a[N],nxt[N],hsh[N];
int power(int y){
	int s=1,x=26;
	for (;y;y/=2,x=1ll*x*x%mo)
		if (y&1) s=1ll*s*x%mo;
	return s;
}
int main(){
	scanf("%d%d%s",&n,&m,s+1);
	len=strlen(s+1);
	for (int i=2,j=0;i<=len;i++){
		for (;j&&s[i]!=s[j+1];j=nxt[j]);
		if (s[i]==s[j+1]) j++;
		nxt[i]=j;
	}
	for (int i=nxt[len];i;i=nxt[i])
		hsh[len-i+1]=1;
	if (!m){
		printf("%d",power(n));
		return 0;
	}
	scanf("%d",&a[1]);
	ans+=a[1]-1;
	for (int i=2;i<=m;i++){
		scanf("%d",&a[i]);
		if (a[i]-a[i-1]<len){
			if (!hsh[a[i]-a[i-1]+1]){
				puts("0");
				return 0;
			}
		}
		else ans+=a[i]-a[i-1]-len;
	}
	ans+=n-a[m]-len+1;
	printf("%d",power(ans));
}