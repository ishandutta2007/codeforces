#include<bits/stdc++.h>
#define N 200005
#define M 455
using namespace std;
int n,Q,l,r;
char s[N];
int Le[M],Ri[M];
int tg[M][130];
int cnt[M][130];
int sum[M];
char ch[2];
void pushdown(int k){
	for (int i=Le[k];i<=Ri[k];i++)
		if (s[i]!='@')
			if (tg[k][s[i]])
				s[i]='@';
	memset(tg[k],0,sizeof(tg[k]));
}
void rebuild(int k){
	memset(cnt[k],0,sizeof(cnt[k]));
	sum[k]=0;
	for (int i=Le[k];i<=Ri[k];i++)
		if (s[i]!='@') cnt[k][s[i]]++,sum[k]++;
}
int calc(int x){
	int i;
	for (i=1;x>sum[i];x-=sum[i++]);
	pushdown(i); i=Le[i];
	for (;;i++)
		if (s[i]!='@'){
			x--;
			if (!x) return i; 
		}
}
int main(){
	scanf("%d%d%s",&n,&Q,s+1);
	int sz=(int)(sqrt(n)+1e-9);
	int blk=(n-1)/sz+1;
	for (int i=1;i<=blk;i++){
		Le[i]=(i-1)*sz+1;
		Ri[i]=min(i*sz,n);
		rebuild(i);
	}
	while (Q--){
		scanf("%d%d%s",&l,&r,ch);
		l=calc(l); r=calc(r);
		int L=(l-1)/sz+1,R=(r-1)/sz+1;
		if (L==R){
			pushdown(L);
			for (int i=l;i<=r;i++)
				if (s[i]==ch[0]) s[i]='@';
			rebuild(L);
			continue;
		}
		else{
			for (int i=L+1;i<R;i++){
				sum[i]-=cnt[i][ch[0]];
				tg[i][ch[0]]=1;
				cnt[i][ch[0]]=0;
			}
			pushdown(L);
			pushdown(R);
			for (int i=l;i<=Ri[L];i++)
				if (s[i]==ch[0]) s[i]='@';
			for (int i=Le[R];i<=r;i++)
				if (s[i]==ch[0]) s[i]='@';
			rebuild(L);
			rebuild(R);
		}
	}
	for (int i=1;i<=blk;i++)
		pushdown(i);
	for (int i=1;i<=n;i++)
		if (s[i]!='@') putchar(s[i]);
}