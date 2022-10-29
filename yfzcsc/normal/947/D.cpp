#include<bits/stdc++.h>
#define maxn 301000
using namespace std;
char s[maxn],t[maxn];
int S[maxn],S1[maxn];
int T[maxn],T1[maxn];
int ns,nt,Q; 
bool solve(int b,int a,int sb,int sa){
//	printf("[%d,%d,%d,%d]",b,a,sb,sa);
	if(!b){
		if(!sb)return a>=sa&&(a-sa)%3==0;
		if(a==sa)return 0;
	}
	if(a<sa)return 0;
	if((sb-b)%2)return 0;
	int g=(a-sa)%3!=0;
	if(b+2*g<=sb)return 1;
	else return 0;
}
int main(){
	scanf("%s%s%d",s+1,t+1,&Q);
	ns=strlen(s+1);
	nt=strlen(t+1);
	for(int i=1;i<=ns;++i){
		if(s[i]=='A')S1[i]=S1[i-1]+1;
		S[i]=S[i-1]+(s[i]!='A');
	}
	for(int i=1;i<=nt;++i){
		if(t[i]=='A')T1[i]=T1[i-1]+1;
		T[i]=T[i-1]+(t[i]!='A');
	}
	for(int i=1;i<=Q;++i){
		int l,r,sl,sr;
		scanf("%d%d%d%d",&l,&r,&sl,&sr);
		putchar('0'+solve(S[r]-S[l-1],min(r-l+1,S1[r]),T[sr]-T[sl-1],min(sr-sl+1,T1[sr])));
	}
}