#include<bits/stdc++.h>
using namespace std;

int n,nex[26],used[26],l,c,deg[26];
char s[101000];
string ans;

int main(){
	scanf("%d",&n);
	memset(nex,-1,sizeof nex);
	for (;n--;){
		scanf("%s",s+1); l=strlen(s+1);
		for (int i=used[c=s[1]-'a']=1;i<l;i++){
			if (~nex[c]&&nex[c]!=s[i+1]-'a') return 0*printf("NO");
			used[c=nex[c]=s[i+1]-'a']=1;
		}
	}
	for (int i=0;i<26;i++) deg[nex[i]]++;
	for (int p;*max_element(used,used+26);){
		for (p=0;!(used[p]&&!deg[p])&&p<26;p++);
		if (p==26) return 0*printf("NO");
		for (;;){
			ans+=p+'a';
			used[p]=0;
			if (~nex[p]){
				deg[p=nex[p]]--;
				if (!(used[p]&&!deg[p])) return 0*printf("NO");
			}else{
				break;
			}
		}
	}
	cout<<ans;
}