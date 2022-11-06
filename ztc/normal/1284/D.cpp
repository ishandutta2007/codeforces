#include<stdio.h>
#include<algorithm>
#include<vector>
int n,a[100002][2],g[100002][2],mk[100002],top=0,cnt=0;
std::pair<int,int>b[1000002];
struct node{
	node *ls,*rs;
	int maxx,cnt;
}tr[10000002],*null=tr,*tp=tr-1,*rt;
node *addnode(){
	node *p=++tp;
	p->ls=p->rs=null;
	p->cnt=p->maxx=0;
	return p;
}
inline int Max(int p,int q){return p>q?p:q;}
void add(int l,int r,int L,int R,node *p,int v){
	if(L<=l&&r<=R){p->cnt+=v;return;}
	if(l+r>>1>=L)add(l,l+r>>1,L,R,p->ls==null?(p->ls=addnode()):p->ls,v);
	if(l+r>>1<R)add(l+r+2>>1,r,L,R,p->rs==null?(p->rs=addnode()):p->rs,v);
	p->maxx=Max(p->ls->maxx+p->ls->cnt,p->rs->maxx+p->rs->cnt);
}
int main(){
	scanf("%d",&n);addnode();rt=addnode();
	for(int i=1;i<=n;i++){
		int p,q;
		scanf("%d%d%d%d",&p,&q,&a[i][0],&a[i][1]);
		b[++top]=std::make_pair(p,i);
		b[++top]=std::make_pair(q+1,i);
		g[i][0]=p;g[i][1]=q;
	}std::sort(b+1,b+top+1);
	for(int i=1;i<=top;){
		int j=i;
		while(j<=top&&b[j].first==b[i].first){
			int p=b[j].second;
			if(!mk[p]){//printf("%d %d 1\n",a[p][0],a[p][1]);
				add(1,1e9,a[p][0],a[p][1],rt,1);
				cnt++;mk[p]=1;
			}else{//printf("%d %d -1\n",a[p][0],a[p][1]);
				add(1,1e9,a[p][0],a[p][1],rt,-1);
				cnt--;mk[p]=0;
			}j++;
		}i=j;
		if(cnt>rt->maxx+rt->cnt)return printf("NO")&0;
	}top=0;tp=tr;rt=addnode();
	for(int i=1;i<=n;i++){
		int p=a[i][0],q=a[i][1];
		b[++top]=std::make_pair(p,i);
		b[++top]=std::make_pair(q+1,i);
	}std::sort(b+1,b+top+1);
	for(int i=1;i<=top;){
		int j=i;
		while(j<=top&&b[j].first==b[i].first){
			int p=b[j].second;
			if(!mk[p]){//printf("%d %d 1\n",a[p][0],a[p][1]);
				add(1,1e9,g[p][0],g[p][1],rt,1);
				cnt++;mk[p]=1;
			}else{//printf("%d %d -1\n",a[p][0],a[p][1]);
				add(1,1e9,g[p][0],g[p][1],rt,-1);
				cnt--;mk[p]=0;
			}j++;
		}i=j;
		if(cnt>rt->maxx+rt->cnt)return printf("NO")&0;
	}printf("YES");
}