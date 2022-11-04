#include<bits/stdc++.h>
#define mo ((1ll<<62)-23333)
#define ll long long
#define pa pair<int,int>
#define N 100005
using namespace std;
string Fuck="What are you doing at the end of the world? Are you busy? Will you save us?";
string LXL="What are you doing while sending   ? Are you busy? Will you send   ?";
bool fl[100005];
ll len[100005];
int q,n;
ll k;
char work(bool fuck,int pos){
	if (fuck) return LXL[pos-1];
	return Fuck[pos-1];
}
char solve(int x,ll p){
	if (!x) return work(0,p);
	if (p<=34) return work(1,p);
	p-=34;
	if (fl[x-1]||len[x-1]>=p)
		return solve(x-1,p);
	p-=len[x-1];
	if (p<=32)
		return work(1,p+34);
	p-=32;
	if (fl[x-1]||len[x-1]>=p)
		return solve(x-1,p);
	p-=len[x-1];
	return work(1,p+66);
}
int main(){
	scanf("%d",&q);
	len[0]=75;
	LXL[34]=LXL[33]='"';
	LXL[66]=LXL[65]='"';
	for (int i=1;i<=100000;i++){
		len[i]=(1ll*len[i-1]*2+68)%mo;
		fl[i]=fl[i-1]|(1ll*len[i-1]*2+68>mo);
	}
	while (q--){
		scanf("%d%I64d",&n,&k);
		for (;k>34&&n>=100;k-=34,n--);
		if (fl[n]||len[n]>=k) 
			printf("%c",solve(n,k));
		else putchar('.');
	}
}