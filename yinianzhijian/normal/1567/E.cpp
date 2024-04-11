#include<bits/stdc++.h>
#define ll long long
using namespace std;
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
int n,m;
const int xx=2e5+5;
int a[xx];
ll sum[xx<<2];
void upd(int k)
{
	sum[k]=sum[k<<1]+sum[k<<1|1];
}
void change(int k,int l,int r,int x,ll y)
{
	if(l==r)return sum[k]=y,void();
	int mid=l+r>>1;
	if(x<=mid)change(k<<1,l,mid,x,y);
	else change(k<<1|1,mid+1,r,x,y);
	upd(k);
}
struct node
{
	int l,r;
	bool operator<(const node&w)const{return l<w.l;}
};
multiset<node>s;
ll ask(int k,int l,int r,int x,int y)
{
	if(x>y)return 0;
	if(x<=l&&r<=y)return sum[k];
	int mid=l+r>>1;ll ans=0;
	if(x<=mid)ans+=ask(k<<1,l,mid,x,y);
	if(mid<y)ans+=ask(k<<1|1,mid+1,r,x,y);
	return ans;
}
ll get(ll x){return x*(x-1)/2;}
void brk(int x)//x->x-1 
{
	multiset<node>::iterator it=--s.lower_bound((node){x});
	node w=*it;
	s.erase(it);
	s.insert((node){w.l,x-1});
	change(1,1,n,w.l,get(x-1-w.l+1));
	s.insert((node){x,w.r});
	change(1,1,n,x,get(w.r-x+1));
}
void cnt(int x)//xx-1 
{
	multiset<node>::iterator it=s.lower_bound((node){x}),ita=it;
	node w=*it;ita--;
	s.erase(it);
	change(1,1,n,w.l,0);
	int o=ita->l;
	s.erase(ita);
	s.insert((node){o,w.r});
	change(1,1,n,o,get(w.r-o+1));
}
int main(){
	
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	
	for(int i=1;i<=n;i++)
	{
		int nl=i,nr=i+1;
		while(a[nr]>=a[nr-1])nr++;
		s.insert((node){nl,nr-1});
		i=nr-1;
		change(1,1,n,nl,get((nr-nl)));
//		cout<<nl<<" "<<get((nr-nl+1))<<" "<<nl<<" "<<nr<<"\n";
	}
	
	s.insert((node){0,0});
	s.insert((node){n+1,n+1});
	for(int i=1;i<=m;i++)
	{
		int op=read();
		if(op==1)
		{
			int x=read(),y=read();
//			if(i==63)
//			{
//				cerr<<i<<" "<<x<<" "<<y<<"\n";
//				for(auto it:s)
//				{
//					cerr<<it.l<<" "<<it.r<<"\n";
//				}
//				puts("");
//			}
			if(x!=1)
			{
				if((a[x]>=a[x-1])==(y>=a[x-1]));
				else 
				{
					if(a[x]>=a[x-1])// 
						brk(x);
					else// 
						cnt(x);
				}
			}
			if(x!=n)
			{
				x++;
				if((a[x]>=a[x-1])==(a[x]>=y));
				else 
				{
					if(a[x]>=a[x-1])
						brk(x);
					else cnt(x);
				}
				x--;
			}
			a[x]=y;
		}
		if(op==2)
		{
			int l=read(),r=read();
			multiset<node>::iterator it=--s.lower_bound((node){l});
			ll ans=r-l+1;
			ans+=get((it->r)-l+1);
			if((it->l)<=l&&(it->r)>=r)
			{
//				puts("Qwewqeqe");
				cout<<get(r-l+1)+(r-l+1)<<"\n";
				continue;
			}
			l=(it->r)+1;
			it=--s.upper_bound((node){r});
			ans+=get(r-(it->l)+1);
			r=(it->l)-1;
//			cout<<l<<" "<<r<<" "<<ans<<"\n";
			ans+=ask(1,1,n,l,r);
			cout<<ans<<'\n';
		}
	}
	return 0;
}