#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<algorithm>
using namespace std;
char s[2001];
int ans;
int main(){
	scanf("%s",s+1);
	int len=strlen(s+1);
	for (int i=1;i<=len;i++)
		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='1'||s[i]=='3'||s[i]=='5'||s[i]=='7'||s[i]=='9')	ans++;
	printf("%d",ans);
}