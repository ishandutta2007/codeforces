#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
char duiyin[200],s[1200],t[1200];
bool used[200];
int main(){
	scanf("%s%s",s+1,t+1);
	int n=strlen(s+1);
	for(int i=1;i<=n;++i){
		if(duiyin[s[i]]){if(duiyin[s[i]]!=t[i]){printf("-1");return 0;}}
		else if(duiyin[t[i]]){if(duiyin[t[i]]!=s[i]){printf("-1");return 0;}}
		else duiyin[s[i]]=t[i],duiyin[t[i]]=s[i];
	}
	int ans=0;
	for(int i='a';i<='z';i++)if(duiyin[i]&&!used[i])
		if(duiyin[i]!=i)ans++,used[duiyin[i]]=true;
	printf("%d\n",ans);
	for(int i='a';i<='z';i++)if(duiyin[i]&&!used[i])
		if(duiyin[i]!=i)printf("%c %c\n",i,duiyin[i]);
}