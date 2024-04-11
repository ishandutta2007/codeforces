#include <cstdio>
#include <vector>
using std::vector;
struct pii{
	int first,second;
	bool operator<(const pii&x) const{
		return first==x.first?second<x.second:first<x.first;
	}
	bool operator>(const pii&x)const{
		return first==x.first?second>x.second:first>x.first;
	}
};
pii make_pair(int a,int b){
	return (pii){a,b};
}
const int N=250000;
int n,x,t,st[N],w,xb,y,dfn[N],id[N],b[N],m,j,dep[N],li[N],ri[N],k,o,q,i,xx,yy,zz;
inline void swap(int&a,int&b){
    t=a;
    a=b;
    b=t;
}
inline pii max(pii a,pii b){
	return a>b?a:b;
}
inline pii min(pii a,pii b){
	return a<b?a:b;
}
struct node{
       int l,r,fa,size,sum,add,v;
       pii ma,mi,x; 
       node(int _v=0):v(_v){size=1,l=r=fa=0;}
}a[N];
struct list{
    int rt;
    list(int _rt=0):rt(_rt){}
    inline void pushdown(int i){
        if(a[i].add){
            if(a[i].l)a[a[i].l].add+=a[i].add;
            if(a[i].r)a[a[i].r].add+=a[i].add;
            a[i].x.first+=a[i].add;
            a[i].ma.first+=a[i].add;
            a[i].mi.first+=a[i].add;
            a[i].add=0;
        }
    }
    inline void maintain(int i){
    	pushdown(a[i].l);
    	pushdown(a[i].r);
        a[i].size=a[a[i].l].size+a[a[i].r].size+1;
        a[i].sum=a[a[i].l].sum+a[a[i].r].sum+a[i].v;
        a[i].ma=max(max(a[a[i].l].ma,a[a[i].r].ma),a[i].x);
        a[i].mi=a[i].x;
        if(a[i].l)a[i].mi=min(a[a[i].l].mi,a[i].mi);
        if(a[i].r)a[i].mi=min(a[a[i].r].mi,a[i].mi);
    }
    void build(int fa,int&x,int l,int r){
        a[x=++xb].fa=fa;
        int m=(l+r)>>1;
        a[x].v=b[m];
        a[x].x=make_pair(dep[dfn[m]],dfn[m]);
        if(b[m]==1)li[dfn[m]]=xb;
        	else ri[dfn[m]]=xb;
        if(m!=l)build(x,a[x].l,l,m-1);
        if(m!=r)build(x,a[x].r,m+1,r);
        maintain(x);
    }
    void rorate(int x){
        int y=a[x].fa,z=a[y].fa;        
        if(z){
            if(a[z].l==y)a[z].l=x;
                else a[z].r=x;
        }
        a[x].fa=z;
        a[y].fa=x;
        if(a[y].l==x){
            a[a[x].r].fa=y;
            a[y].l=a[x].r;
            a[x].r=y;
        }else{
            a[a[x].l].fa=y;
            a[y].r=a[x].l;
            a[x].l=y;
        }
        maintain(y);
        maintain(x);
    }
    void splay(int x){
        int y,z;
        for(w=0,y=x;y;y=a[y].fa)st[++w]=y;
        for(z=w;z;--z)pushdown(st[z]);
        while(a[x].fa){
            y=a[x].fa,z=a[y].fa;
            if(z){                
                if((a[y].l==x)^(a[z].l==y))rorate(x);
                    else rorate(y);
            }
            rorate(x);
        }
        rt=x;
    }
    inline int rank(int i){
    	int x=i,ans=a[a[x].l].size+1;
    	while(a[x].fa){
    		if(a[a[x].fa].r==x)ans+=a[a[a[x].fa].l].size+1;
    		x=a[x].fa;
    	}
    	return ans;
    }
    inline int kth(int i){//1<=i<=rt->size
        int x=rt;
        for(;;){
            pushdown(x);
            int y=a[a[x].l].size+1;
            if(y>i)x=a[x].l;
                else if(y<i){
                    i-=y;
                    x=a[x].r;
                }else return x;
        }
    }
    void operator+=(list b){
        if(!b.rt)return;
        if(!rt){
        	rt=b.rt;
        	return;
        }
        int x=rt;
        pushdown(x);
        while(a[x].r)x=a[x].r,pushdown(x);
        splay(x);
        a[rt].r=b.rt;
        a[b.rt].fa=rt;
        maintain(rt);
    }
    void midout(int i){
        if(i){
            pushdown(i);
            midout(a[i].l);
            printf("%d %d\n",a[i].x.second,a[i].v);
            midout(a[i].r);
        }
    }
    int split(int v){
    	if(!v){
    		int x=rt;
    		rt=0;
    		return x;
    	}
        splay(kth(v));
        int x=a[rt].r;
        a[rt].r=0;
        a[x].fa=0;
        maintain(rt);
        return x;
    }
    inline int size(){
        return a[rt].size;
    }
    int sum(int i,int l,int r){
    	int x=rank(l);
    	list c,b;
    	if(x>1){
			c=split(x-1);
    		b=c.split(r-l+1);
    		x=a[c.rt].sum;
    		c+=b;
    		*this+=c;
    	}else{
    		b=split(r-l+1);
    		x=a[rt].sum;
    		*this+=b;
    	}
    	return x;
    }
    int query(int i,int y){
    	pushdown(i);
    	pushdown(a[i].r);
    	pushdown(a[i].l);
    	if(a[a[i].r].ma.first>=y && a[a[i].r].mi.first<=y)return query(a[i].r,y);
    	if(a[i].x.first==y)return a[i].x.second;
    	return query(a[i].l,y);
    }
    int query(int i,int x,int y){
    	splay(x);
    	if(a[x].x.first==y)return a[x].x.second;
    		else return query(a[x].l,y);
    }
	int psum(int i){
		splay(i);
		return a[i].x.first;
	}
}u,v,p,l;
struct tree{
	vector<int> g[N];
	inline void addedge(int x,int y){
		g[x].push_back(y);
	}
	void dfs(int x,int fa){
		dep[x]=dep[fa]+1;
		b[++xb]=1;
		dfn[xb]=x;
		for(unsigned int i=0;i<g[x].size();++i)dfs(g[x][i],x);
		b[++xb]=-1;
		dfn[xb]=x;
	}
}g;
int main(){
	a[0].size=0;
	scanf("%d%d",&n,&m);
	for(i=1;i<=n;++i){
		scanf("%d",&j);
		while(j--){
			scanf("%d",&x);
			g.addedge(i,x);
		}
	}
	g.dfs(1,0);
	xb=0;
	l.build(0,l.rt,1,n<<1);
	while(m--){
		scanf("%d",&j);
		if(j==1){
			scanf("%d%d",&x,&y);
			if(x==y){
				puts("0");
				continue;
			}
			o=l.psum(li[x]);
			q=l.psum(li[y]);
			xx=l.rank(li[x]);
			yy=l.rank(li[y]);
			if(xx>yy)swap(x,y),swap(o,q),swap(xx,yy);
			if(l.rank(ri[y])<=l.rank(ri[x])){
				printf("%d\n",q-o);
				continue;
			}
			u=l.split(xx-1);
			//printf("u.size=%d\n",u.size());
			//u.midout(u.rt);
			v=u.split(yy-xx+1);
			//printf("v.size=%d\n",v.size());
			//v.midout(v.rt);
			k=a[u.rt].mi.second;
			//printf("l.size=%d\n",l.size());
			//l.midout(l.rt);
			l+=u;
			l+=v;
			i=l.psum(li[k]);
			printf("%d\n",o+q-(i<<1)+2);
		}
		if(j==2){
			scanf("%d%d",&x,&y);
			i=l.query(l.rt,li[x],l.psum(li[x])-y);
			k=l.rank(ri[i]);
			u=l.split(k-1);
			o=l.rank(li[x]);
			v=l.split(o-1);
			p=v.split(v.rank(ri[x]));
			a[v.rt].add+=1-y;
			l+=p;
			l+=v;
			l+=u;
		}
		if(j==3){
			scanf("%d",&x);
			i=l.query(l.rt,ri[1],x+1);
			printf("%d\n",i);
		}
		//printf("size=%d\n",l.size());
		//l.midout(l.rt);
	}
    return 0;
}