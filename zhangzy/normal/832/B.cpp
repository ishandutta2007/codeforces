#include<bits/stdc++.h>
using namespace std;
char good[233],s[520517],ss[520517];
int ok[128]={0},n,l,ll,m,xin=-1,bef,aft;

bool pp(char x,char y){
	if (x=='?'){
		if (!ok[y]) return 0;
		return 1;
	}else{
		if (x!=y) return 0;
		return 1;
	}
}

int pd(){
	if (xin<0){
		if (l!=ll) return 0;
		for (int i=0;i<l;i++){
			if (!pp(s[i],ss[i])) return 0; 
		}
		return 1;
	}
	
	int st=xin,en=ll-l+xin;
	//printf("%d %d\n",st,en);
	if (st>en+1) return 0;
	for (int i=0;i<xin;i++){
		if (!pp(s[i],ss[i])) return 0;
	}
	for (int i=en+1;i<ll;i++){
		if (!pp(s[i-en+xin],ss[i])) return 0;
	}
	for (int i=st;i<=en;i++){
		if (ok[ss[i]]) return 0;
	}
	
	return 1;
}

int main(){
	scanf("%s",good);
	n=strlen(good);
	for (int i=0;i<n;i++){
		ok[good[i]]=1;
	}
	scanf("%s",s);
	l=strlen(s);
	for (int i=0;i<l;i++){
		if(s[i]=='*'){
			xin=i;
			bef=i;
			aft=l-i;
		}
	}
	
	scanf("%d\n",&m);
	while (m--){
		scanf("%s",ss);
		ll=strlen(ss);
		if (pd()){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
}