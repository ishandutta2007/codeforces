#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define d 3000
#define N 200015
using namespace std;
int n,m;
int c[N];
struct node{
    int l,r,t,pr;
    node(){l=r=t=0;}
}q[N],g[N];
int cnt1,cnt2;
bool cmp1(const node &aa,const node &bb){
    return aa.t<bb.t;
}
int be1[N],be2[N];
bool cmp2(const node &aa,const node &bb)
{
    if(be1[aa.l]==be1[bb.l])
    {
        if(be2[aa.r]==be2[bb.r])return aa.t<bb.t;
        return aa.r<bb.r;
    }
    return aa.l<bb.l;
}
int ans[N];
int op,tt[N],tong[N];
inline void ins(int x){
	//cout<<tong[x]<<endl;
	tt[tong[x]]--; tt[++tong[x]]++; 
	//cout<<x<<" ins"<<" "<<tong[x]<<" "<<tt[1]<<endl; 
}
inline void del(int x){
	//cout<<tong[x]<<endl;
	tt[tong[x]]--; tt[--tong[x]]++;
	//cout<<x<<" del"<<" "<<tong[x]<<" "<<tt[1]<<endl;
}
#include<map>
map<int,int> M;
int sum;
void solve(){
    int p1,p2,p;
    g[cnt1+1].t=200004;
    p=1; p1=1;
    ins(c[1]);
    p2=0;
    for(int i=1;i<=cnt2;i++){
        while(g[p2+1].t<q[i].t){
            p2++;
            int tmp=c[g[p2].l];
            g[p2].pr=tmp;
            c[g[p2].l]=g[p2].r;
            if(g[p2].l<=p&&g[p2].l>=p1){
            	del(tmp); ins(g[p2].r);
            }
        }
        while(g[p2].t>q[i].t){
            c[g[p2].l]=g[p2].pr;
            if(g[p2].l<=p&&g[p2].l>=p1){
            	del(g[p2].r); ins(g[p2].pr);
            }
            p2--;
        }
        while(p<q[i].r){
        	ins(c[++p]);
        }
        while(p1>q[i].l){
            ins(c[--p1]);
        }
        while(p>q[i].r){
            del(c[p--]);
        }
        while(p1<q[i].l){
            del(c[p1++]);
        }
        //cout<<q[i].t<<endl;
        //cout<<p<<" "<<p1<<" "<<q[i].t<<" "<<q[i].l<<" "<<q[i].r<<" "<<tong[1]<<" "<<tong[2]<<" "<<tong[3]<<" "<<tong[4]<<" "<<tt[1]<<" "<<tt[2]<<endl;
        //cout<<tt[1]<<endl;
		for(int j=1;;j++)if(!tt[j]){ans[q[i].t]=j; break;}
        //cout<<ans[q[i].t]<<" "<<q[i].t<<endl;
    }
}
int main(){
	//freopen("std.in","r",stdin); freopen("my.out","w",stdout);
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++){
    	int t;
    	scanf("%d",&t);
    	if(!M[t])c[i]=M[t]=++sum; else c[i]=M[t];
    	//cout<<c[i]<<" ";
	}
    for(int i=1;i<=n;i++){
        be1[i]=be2[i]=(i-1)/d+1;
    }
    memset(ans,-1,sizeof(ans));
    for(int i=1;i<=m;i++){
        scanf("%d",&op);
        if(op==2){
            cnt1++;
            scanf("%d%d",&g[cnt1].l,&g[cnt1].r); if(!M[g[cnt1].r])M[g[cnt1].r]=++sum; g[cnt1].r=M[g[cnt1].r];
            g[cnt1].t=i;
        }else{
            cnt2++;
            scanf("%d%d",&q[cnt2].l,&q[cnt2].r);
            q[cnt2].t=i;
        }
    }
    sort(q+1,q+cnt2+1,cmp2);
    sort(g+1,g+cnt1+1,cmp1);
    solve();
    for(int i=1;i<=m;i++){
        if(ans[i]!=-1)printf("%d\n",ans[i]);
    }
    return 0;
}