#include<bits/stdc++.h>
using namespace std;
const int N=400005;
struct wzp{
	int r1,c1,r2,c2,id;
}q[N];
bool cmp(wzp a,wzp b){
	return a.r2<b.r2;
}
int lg[N],st[22][N];
int a[N],sta[N],ans[N];
int n,Q,k,top;



int abs(int x){
	return x<0?-x:x;
}
int min(int x,int y){
	return x<y?x:y;
}
int qmin(int l,int r){
	if (l>r) swap(l,r);
	int k=lg[r-l+1];
	return min(st[k][l],st[k][r-(1<<k)+1]);
}
int calc(int r1,int c1,int r2,int c2,int r){
	int ans=0;
	c1=min(c1,qmin(r1,r));
	if (c1<a[r]) ans++;
	ans+=abs(r1-r)+abs(r2-r);
	ans+=abs(c2-a[r]);
	return ans;
}
int getpos(int l,int r,int k){
	l--;
	for (;l<r-1;){
		int mid=(l+r)>>1;
		if (sta[mid]<=k) r=mid;
		else l=mid;
	}
	return r;
}
void getans(wzp x,int l,int r){
	l--; r++;
	for (;l<r-10;){
		int len=(r-l+1)/3;
		int lm=l+len,rm=r-len;
		int lv=calc(x.r1,x.c1,x.r2,x.c2,sta[lm]);
		int rv=calc(x.r1,x.c1,x.r2,x.c2,sta[rm]);
		if (lv>rv) l=lm; else r=rm;
	}
	for (l++;l<r;l++)
		ans[x.id]=min(ans[x.id],calc(x.r1,x.c1,x.r2,x.c2,sta[l]));
}
int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++)	
		scanf("%d",&a[i]),st[0][i]=a[i];
	for (int j=0;j<20;j++)
		for (int i=1;i+(1<<(j+1))-1<=n;i++)
			st[j+1][i]=min(st[j][i],st[j][i+(1<<j)]);
	for (int i=2;i<=n;i++) lg[i]=lg[i>>1]+1;
	scanf("%d",&Q);
	for (int i=1;i<=Q;i++){
		scanf("%d%d%d%d",&q[i].r1,&q[i].c1,&q[i].r2,&q[i].c2);
		ans[i]=abs(q[i].r1-q[i].r2)+1+q[i].c2; q[i].id=i;
	}
	sort(q+1,q+Q+1,cmp);
	top=0; k=1;
	for (int i=1;i<=n;i++){
		for (;top&&a[sta[top]]>=a[i];top--);
		sta[++top]=i;
		for (;k<=Q&&q[k].r2==i;k++)
			if (q[k].r1<=q[k].r2){
				int pos=lower_bound(sta,sta+top+1,q[k].r1)-sta;
				getans(q[k],pos,top); getans(q[k],1,pos-1);
				int res=abs(q[k].r2-q[k].r1);
				int mn=min(q[k].c1,qmin(q[k].r1,q[k].r2));
				ans[q[k].id]=min(ans[q[k].id],res+abs(mn-q[k].c2));
			}
			else getans(q[k],1,top);
	}
	top=0; k=Q;
	for (int i=n;i;i--){
		for (;top&&a[sta[top]]>=a[i];top--);
		sta[++top]=i;
		for (;k&&q[k].r2==i;k--)
			if (q[k].r1>q[k].r2){
				int pos=getpos(1,top,q[k].r1);
				getans(q[k],pos,top); getans(q[k],1,pos-1);
				int res=abs(q[k].r2-q[k].r1);
				int mn=min(q[k].c1,qmin(q[k].r1,q[k].r2));
				ans[q[k].id]=min(ans[q[k].id],res+abs(mn-q[k].c2));
			}
			else
				getans(q[k],1,top);
	}
	for (int i=1;i<=Q;i++)
		printf("%d\n",ans[i]);
}