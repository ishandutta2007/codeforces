#include<bits/stdc++.h>
using namespace std;
int s0=0,s1=0,n,m,fail[501000],tp;
char S[500100],T[500100];
void use(){
	while(s0)s0--,S[++tp]='0';
	while(s1)s1--,S[++tp]='1';
}
int main(){
	scanf("%s%s",S+1,T+1);
	n=strlen(S+1);
	m=strlen(T+1);
	for(int i=1;i<=n;++i)
		if(S[i]=='0')s0++;
		else s1++;
	fail[1]=0;
	for(int i=2;i<=m;++i){
		int j=fail[i-1];
		while(T[i]!=T[j+1]&&j)j=fail[j];
		if(T[i]==T[j+1])j++;
		fail[i]=j;
	}
	for(int i=1;i<=m;++i){
		if(T[i]=='0'){
			if(!s0)use();
			else S[++tp]='0',s0--;
		} else {
			if(!s1)use();
			else S[++tp]='1',s1--;
		}
	}
	while(s0||s1){
		int x=fail[m];
		for(int i=x+1;i<=m;++i){
			if(T[i]=='0'){
				if(!s0)use();
				else S[++tp]='0',s0--;
			} else {
				if(!s1)use();
				else S[++tp]='1',s1--;
			}	
		}
	}
	printf("%s\n",S+1);
}