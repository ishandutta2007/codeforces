#include<bits/stdc++.h>
using namespace std;
const int N=5005;
int SG[N],f[N];
char s[N];
int calc(int L,int R){
	int tmp=0,ans=0;
	for (int i=L+1;i<R;i++)
		if (s[i-1]==s[i+1]) tmp++;
		else ans^=SG[tmp],tmp=0;
	return ans^SG[tmp];
}
int main(){
	scanf("%s",s+1);
	int n=strlen(s+1);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=i;j++)
			f[SG[max(j-2,0)]^SG[max(i-j-1,0)]]=i;
		for (;f[SG[i]]==i;SG[i]++);
	}
	for (int i=2;i<=n;i++)
		if (s[i-1]==s[i+1]&&!(calc(1,i-1)^calc(i+1,n)))
			return printf("First\n%d",i),0;
	puts("Second");
}