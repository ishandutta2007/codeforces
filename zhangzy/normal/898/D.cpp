#include<bits/stdc++.h>
using namespace std;

struct P{
	int tim,who,val;
}p[404000],now;
bool cmp(P p1,P p2){
	return p1.tim==p2.tim? p1.val<p2.val: p1.tim<p2.tim;
}

int n,m,k,tot,cnt,x,fl[404000],ans;

int main(){
	scanf("%d%d%d",&n,&m,&k); k--;
	for (int i=1;i<=n;++i){
		scanf("%d",&x);
		p[++tot]=(P){x,i,1};
		p[++tot]=(P){x+m,i,0};
	}
	sort(p+1,p+tot+1,cmp);
	for (int i=1;i<=tot;++i){
		now=p[i];
		if (now.val){
			if (cnt==k) ans++;
			else fl[now.who]=1, cnt++;
		}else{
			if (fl[now.who]) cnt--;
		}
	}
	cout<<ans;
}