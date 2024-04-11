#include<bits/stdc++.h>
#define rep(i,x,y) for (int i=(x); i<=(y); i++)
#define per(i,x,y) for (int i=(x); i>=(y); i--)
#define ll long long
#define N 1000005
#define all(x) (x).begin(),(x).end()
using namespace std;
int n,m,k,len,f[N],g[N],w1[N],w2[N]; char s[N],t[N],str[N];
void get_next(char s[],int nxt[]){
	int k=0; nxt[1]=0;
	rep (i,2,len){
		while (k && s[k+1]!=s[i]) k=nxt[k];
		if (s[k+1]==s[i]) nxt[i]=++k; else nxt[i]=k;
	}
}
int main(){
	scanf("%d%d%d%s%s",&n,&m,&k,s+1,t+1);
	if (k*2>n || k*2<m){ puts("No"); exit(0); }
	len=0;
	rep (i,1,m) str[++len]=t[i]; str[++len]='#';
	rep (i,1,n) str[++len]=s[i];
	get_next(str,f);
	len=0;
	rep (i,1,n) str[++len]=s[i]; str[++len]='#';
	rep (i,1,m) str[++len]=t[i]; reverse(str+1,str+1+len);
	get_next(str,g);
	rep (i,m+2,n+m+1) if (f[i]>=m){
		int p1=i-m-1; p1=max(p1-2*k,0);
		printf("Yes\n%d %d\n",p1+1,p1+1+k); exit(0);
	}
	rep (i,0,n) w1[i]=n+1;
	rep (i,m+2,n+m+1){
		if (i-m-1>=k){
			int tmp=f[i];
			while(tmp){
				if (i-m-1<w1[tmp]) w1[tmp]=i-m-1; else break;
				tmp=f[tmp];
			}
			tmp=g[i];
			while (tmp){
				if (n-(i-m-1)+1>w2[tmp]) w2[tmp]=n-(i-m-1)+1; else break;
				tmp=g[tmp];
			}
		}
	}
	w1[0]=0; w2[0]=n+1;
	rep (i,1,min(k,m)){
		if (m-i>k) continue;
		int p1=w1[i]-k+1,p2=w2[m-i];
		if (p1>=1 && p2+k-1<=n && w1[i]<p2){
			printf("Yes\n%d %d\n",p1,p2); exit(0);
		}
	}
	puts("No");
}