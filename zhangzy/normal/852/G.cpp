#include<bits/stdc++.h>
using namespace std;

int n,m,l,cnt=1,en[5010000]={0},ch[5010000][5]={0},used[5010000]={0};
char s[233];
int q[233333],sz=0;

void A(){
	int p=1,c;
	for (int i=1;i<=l;i++){
		c=(int)s[i]-'a';
		if (!ch[p][c]){
			ch[p][c]=++cnt;
		}
		p=ch[p][c];
	}
	en[p]++;
}
int Q(int p,int st){
	if (p==0) return 0;
	int c,t=0;
	for (int i=st;i<=l;i++){
		if (s[i]=='?'){
			for (int j=0;j<5;j++){
				t+=Q(ch[p][j],i+1);
			}
		}else{
			c=(int)s[i]-'a';
			p=ch[p][c];
			if (p==0) return t;
		}
	}
	if (!used[p]){
		q[++sz]=p;
		used[p]=1;
		t+=en[p];
	}
	return t;
}

int main(){
	scanf("%d%d\n",&n,&m);
	for (;n--;){
		scanf("%s",s+1);
		l=strlen(s+1);
		A();
	}
	for (;m--;){
		scanf("%s",s+1);
		l=strlen(s+1);
		for (int i=1;i<=sz;i++){
			used[q[i]]=0;
		}
		sz=0;
		printf("%d\n",Q(1,1));
	}
}