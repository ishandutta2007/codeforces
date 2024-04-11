#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#define inf 8333583335000000000ll
#define pii pair<int,int>
using namespace std;
int n,lcnt;
long long m,p,q;
int a[100005],lsum[100005];
long long sum[100005],rmax[100005],lmin[100005],ls[100005];
long long ans1,ans2,ans;
set<int>unu;
inline long long Min(long long x,long long y){return x<y?x:y;}
inline long long Max(long long x,long long y){return x>y?x:y;}
inline int lowbit(int k){return k&-k;}
struct ta{
	long long t[100005];
	void add(int k,long long x){for(;k<=lcnt;k+=lowbit(k))t[k]+=x;}
	inline long long query(int k){long long ans=0;for(;k;k-=lowbit(k))ans+=t[k];return ans;}
}tsum,tnum;
struct ta2{
	int t[100005];
	void build(){for(int i=1;i<=lcnt;i++)t[i]=n+1;}
	void add(int k,int x){for(;k<=lcnt;k+=lowbit(k))t[k]=Min(t[k],x);}
	inline int query(int k){int ans=n+1;for(;k;k-=lowbit(k))ans=Min(ans,t[k]);return ans;}
}tmin;
struct subs{
	int l,r;long long w;
	bool operator <(const subs k)const{
		if(w!=k.w)return w<k.w;
		else if(r!=k.r)return r>k.r;
		else return l>k.l;
	}
	bool operator ==(const subs k)const{return (k.l==l)&&(k.r==r)&&(k.w==w);}
	bool operator !=(const subs k)const{return (k.l!=l)||(k.r!=r)||(k.w!=w);}	
};
priority_queue<subs>subsq;
void del(int k);
#define lson index<<1
#define rson index<<1|1
#define mid ((l+r)>>1)
struct sg1{
	bool b[400005];
	void cover(int L,int R,int l,int r,int index){
		if(L>R)return;
		if(b[index])return;
		if(l==r){del(l);b[index]=true;return;}
		if(L<=mid)cover(L,R,l,mid,lson);
		if(R>mid)cover(L,R,mid+1,r,rson);
		b[index]=b[lson]&&b[rson];
	}
}s1;
struct node2{
	long long max,min;
	void pushup(node2 l,node2 r){
		max=Max(l.max,r.max);
		min=Min(l.min,r.min);
	}
};
struct t{
	long long max[100005][17],min[100005][17];
	int lo[100005];
	void build(int l,int r,int index){
		lo[1]=0;
		for(int i=2;i<=n;i++)if((1<<(lo[i-1]+1))==i)lo[i]=lo[i-1]+1;
		else lo[i]=lo[i-1];
		for(int i=0;i<=n;i++)max[i][0]=min[i][0]=sum[i];
		for(int i=1;i<=lo[n];i++)
			for(int j=0;j+(1<<i)-1<=n;j++)max[j][i]=Max(max[j][i-1],max[j+(1<<(i-1))][i-1]),min[j][i]=Min(min[j][i-1],min[j+(1<<(i-1))][i-1]);
	}
	long long query(int l,int r){
		int tmp=lo[r-l+1];
		return Max(max[l][tmp],max[r-(1<<tmp)+1][tmp])-Min(min[l][tmp],min[r-(1<<tmp)+1][tmp]);
	}
}s2;
#undef lson
#undef rson
struct node3{
	int l,r,s;
};
struct sg3{
	node3 t[2000005];
	int root[100005],cnt;
	void ins(int &rt,int l,int r,int k){
		if(rt==0)rt=++cnt;
		t[rt].s++;
		if(l==r)return;
		if(k<=mid)ins(t[rt].l,l,mid,k);
		else ins(t[rt].r,mid+1,r,k);
	}
	void build(){for(int i=0;i<=n;i++)ins(root[lsum[i]],0,n,i);}
	inline int qsum(int rt,int l,int r,int k){
		if(rt==0)return 0;
		if(l==r)return t[rt].s;
		if(k<=mid)return qsum(t[rt].l,l,mid,k);
		else return t[t[rt].l].s+qsum(t[rt].r,mid+1,r,k);
	}
	inline int query(int rt,int l,int r,int k){
		if(l==r)return r;
		if(k<=t[t[rt].l].s)return query(t[rt].l,l,mid,k);
		else return query(t[rt].r,mid+1,r,k-t[t[rt].l].s);
	}
}s3;
struct sg4{
	node3 t[2000005];
	int cnt,root[100005];
	void ins(int &rt,int Rt,int l,int r,int k){
		rt=++cnt;
		if(l==r)return;
		if(k<=mid){
			t[rt].r=t[Rt].r;
			ins(t[rt].l,t[Rt].l,l,mid,k);
		}else{
			t[rt].l=t[Rt].l;
			ins(t[rt].r,t[Rt].r,mid+1,r,k);
		}
	}
	void build(){ins(root[0],0,1,lcnt,lsum[0]);for(int i=1;i<=n;i++)ins(root[i],root[i-1],1,lcnt,lsum[i]);}
	inline int query(int rt,int l,int r,int k){
		if(k>r)return 0;
		if(rt==0)return 0;
		if(l==r)return l;
		if(k>mid)return query(t[rt].r,mid+1,r,k);
		else{
			int tmp=query(t[rt].l,l,mid,k);
			if(tmp)return tmp;
			else return query(t[rt].r,mid+1,r,k);
		}
	}
}s4;
struct splaynode{
	int l,r,size,fa;
	subs s;
	long long sum;
	bool operator <(const splaynode k)const{return s<k.s;}
};
struct Splay{
	splaynode t[100005];
	int root,top,cnt,stack[100005];
	inline int newnode(){return stack[top--];}
	void pushup(int rt){
		t[rt].size=t[t[rt].l].size+t[t[rt].r].size+1;
		t[rt].sum=t[t[rt].l].sum+t[t[rt].r].sum+t[rt].s.w;
	}
	void rorate(int k,int i){
	    int tmp=t[k].fa;
	    t[k].fa=t[tmp].fa;
	    if(t[t[tmp].fa].l==tmp)t[t[tmp].fa].l=k;
	    else t[t[tmp].fa].r=k;
	    t[tmp].fa=k;
	    if(i==0){
		    if(t[k].l>0)t[t[k].l].fa=tmp;
		    t[tmp].r=t[k].l;
		    t[k].l=tmp;
		}else{
		    if(t[k].r>0)t[t[k].r].fa=tmp;
		    t[tmp].l=t[k].r;
		    t[k].r=tmp;
   		}
		pushup(tmp);pushup(k);
	}
	void splay(int k,int g){
		while(t[k].fa!=g){
			int tmp=t[k].fa;
			if(t[tmp].fa==g)if(t[tmp].r==k)rorate(k,0);
			else rorate(k,1);
			else{
				int Tmp=t[tmp].fa;
				if(t[Tmp].l==tmp){
				    if(t[tmp].l==k)rorate(tmp,1);
				    else rorate(k,0);
				    rorate(k,1);
				}else{
				    if(t[tmp].r==k)rorate(tmp,0);
					else rorate(k,1);
					rorate(k,0);
				}
			}
		}
		if(g==0)root=k;
	}
	void build(int l,int r,int &root){
		root=++cnt;t[root].s=(subs){mid+1,mid,0};
		if(l<mid){
			build(l,mid-1,t[root].r);
			t[t[root].r].fa=root;
		}
		if(r>mid){
			build(mid+1,r,t[root].l);
			t[t[root].l].fa=root;
		}
		pushup(root);
	}
	inline long long query(int k){
		if(k>t[root].size)return -inf;
		if(k==t[root].size)return t[root].sum;
		int p=root;
		while(t[t[p].r].size!=k){
			if(k<t[t[p].r].size)p=t[p].r;
			else k-=t[t[p].r].size+1,p=t[p].l;
		}
		splay(p,0);
		return t[t[p].r].sum;
	}
	void ins(subs k){
		if(root==0){
			root=newnode();
			t[root].l=t[root].r=t[root].fa=0;t[root].s=k;pushup(root);
			return;
		}
		int p=root,v;
		while(true){
			if(k<t[p].s)
				if(t[p].l)p=t[p].l;
				else{t[p].l=v=newnode();break;}
			else
				if(t[p].r)p=t[p].r;
				else{t[p].r=v=newnode();break;}
		}
		t[v].fa=p;t[v].l=t[v].r=0;t[v].s=k;pushup(v);splay(v,0);
	}
	void del(subs k){
		if(t[root].size==1){root=0;return;}
		int p=root;
		while(t[p].s!=k){
			if(k<t[p].s)p=t[p].l;
			else p=t[p].r;
		}
		splay(p,0);
		int tmp=t[p].l;
		if(tmp==0){
			t[t[p].r].fa=0;
			root=t[p].r;
			stack[++top]=p;
			return;
		}
		while(t[tmp].r)tmp=t[tmp].r;
		splay(tmp,root);
		t[tmp].fa=0;root=tmp;
		if(t[p].r)t[t[p].r].fa=tmp,t[tmp].r=t[p].r;
		pushup(tmp);stack[++top]=p;
	}
}s;
inline long long read(){
	long long ret=0,p=1;char c=getchar();
	while((c<'0')||(c>'9')){if(c=='-')p=-1;c=getchar();}
	while((c>='0')&&(c<='9'))ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ret*p;
}
inline int find(long long k){
	int l=0,r=lcnt+1;
	while(r-l>1){
		if(ls[mid]>k)r=mid;
		else l=mid;
	}
	return l;
}
inline long long checknum(long long std){
	long long ans=0;
	for(int i=0;i<=n;i++){
		ans+=tnum.query(find(sum[i]-std));
		tnum.add(lsum[i],1);
	}
	for(int i=0;i<=n;i++)tnum.add(lsum[i],-1);
	return ans;
}
void del(int k){
	set<int>::iterator p=unu.find(k),st=unu.begin(),ed=unu.end();
	ed--;
	if(p!=st){
		set<int>::iterator pre=p;pre--;
		s.del((subs){(*pre)+1,k-1,s2.query(*pre,k-1)});
	}
	if(p!=ed){
		set<int>::iterator nex=p;nex++;
		s.del((subs){k+1,(*nex)-1,s2.query(k,(*nex)-1)});
	}
	if((p!=st)&&(p!=ed)){
		set<int>::iterator pre=p,nex=p;pre--;nex++;
		s.ins((subs){(*pre)+1,(*nex)-1,s2.query((*pre),(*nex)-1)});	
	}
	unu.erase(k);
}
inline subs Next(subs now){
	int l=now.l,r=now.r,L,R=r;
	int tmp=s3.qsum(s3.root[lsum[l]],0,n,l);
	if(tmp==1){
		int S=s4.query(s4.root[r-1],1,lcnt,lsum[l]+1);
		if(S==0)return (subs){0,R,-50000000001ll};
		int Sum=s3.qsum(s3.root[S],0,n,r-1);
		L=s3.query(s3.root[S],0,n,Sum);
	}else L=s3.query(s3.root[lsum[l]],0,n,tmp-1);
	return (subs){L,R,sum[R]-sum[L]};
}
inline long long checksum(long long std,long long rest){
	long long ans=0;tmin.build();
	for(int i=0;i<=n;i++){
		int t=find(sum[i]-std);
		rest-=tnum.query(t);
		ans+=tnum.query(t)*sum[i];
		ans+=tsum.query(t);
		s1.cover(tmin.query(t)+1,i,1,n,1);
		tnum.add(lsum[i],1);
		tsum.add(lsum[i],-sum[i]);
		tmin.add(lsum[i],i);
	}
	for(int i=0;i<=n;i++)tnum.add(lsum[i],-1);
	std--;
	ans+=rest*std;
	tnum.add(lsum[0],1);
	for(int i=1;i<=n;i++){
		int Tmp=find(sum[i]-std);
		if(ls[Tmp]!=sum[i]-std){
			Tmp++;tnum.add(lsum[i],1);
			int p=s4.query(s4.root[i-1],1,lcnt,Tmp);
			if(p==0)continue;
			int L=s3.query(s3.root[p],0,n,s3.qsum(s3.root[p],0,n,i-1));
			subsq.push((subs){L,i,sum[i]-sum[L]});
		}else{
			int tmp=tnum.query(Tmp)-tnum.query(Tmp-1);
			tnum.add(lsum[i],1);
			if(tmp==0){
				Tmp++;
				int p=s4.query(s4.root[i-1],1,lcnt,Tmp);
				if(p==0)continue;
				int L=s3.query(s3.root[p],0,n,s3.qsum(s3.root[p],0,n,i-1));
				subsq.push((subs){L,i,sum[i]-sum[L]});				
			}if(tmp<=rest){
				int L=s3.query(s3.root[Tmp],0,n,1);	
				s1.cover(L+1,i,1,n,1);rest-=tmp;
				Tmp++;
				int p=s4.query(s4.root[i-1],1,lcnt,Tmp);
				if(p==0)continue;
				L=s3.query(s3.root[p],0,n,s3.qsum(s3.root[p],0,n,i-1));
				subsq.push((subs){L,i,sum[i]-sum[L]});
			}else{
				int L;
				if(rest){
					L=s3.query(s3.root[Tmp],0,n,tmp-rest+1);
					s1.cover(L+1,i,1,n,1);
				}
				L=s3.query(s3.root[Tmp],0,n,tmp-rest);
				subsq.push((subs){L,i,sum[i]-sum[L]});rest=0;
			}
		}
	}
	return ans;
}
void upans2(){
	if(unu.empty()){
		if(q)ans2=-inf;
		else ans2=0;
		return;
	}
	if(q==0){ans2=-inf;return;}
	ans2=s.query(q-1);
	if(ans2==-inf)return;
	set<int>::iterator p=unu.begin();
	ans2-=lmin[(*p)-1];
	p=unu.end();p--;
	ans2+=rmax[(*p)];
}
void work(){
	for(int i=1;i<=n;i++)unu.insert(i);
	s.build(1,n-1,s.root);
	long long l=ls[1]-ls[lcnt]-1,r=ls[lcnt]-ls[1]+2;
	while(r-l>1){
		if(checknum(mid)>=p)l=mid;
		else r=mid;
	}
	ans1=checksum(r,p);
	upans2();
	if(ans2>-inf)ans=ans1+ans2;
	else ans=-9000000000000000000ll;
}
void pre(){
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read(),ls[i]=sum[i]=sum[i-1]+a[i];
	ls[n+1]=0;
	sort(ls+1,ls+2+n);
	ls[0]=-10000000000ll;
	for(int i=1;i<=n+1;i++)if(ls[i]!=ls[i-1])ls[++lcnt]=ls[i];
	for(int i=0;i<=n;i++)lsum[i]=find(sum[i]);
	lmin[0]=sum[0];
	for(int i=1;i<=n;i++)lmin[i]=Min(lmin[i-1],sum[i]);
	rmax[n]=sum[n];
	for(int i=n-1;i>=0;i--)rmax[i]=Max(rmax[i+1],sum[i]);
	s2.build(1,n-1,1);s3.build();s4.build();
	if(m>n)p=m-n,q=n;
	else p=0,q=m;
	work();
}
void doit(){
	q--;p++;
	for(;q>=0;q--,p++){
		subs tmp=subsq.top();subsq.pop();subsq.push(Next(tmp));
		s1.cover(tmp.l+1,tmp.r,1,n,1);
		while(subsq.top()==tmp)subsq.pop();
		ans1+=tmp.w;upans2();
		if(ans2>-inf)ans=Max(ans,ans1+ans2);
	}
	printf("%I64d",ans);
}
int main(){
	pre();
	doit();
}