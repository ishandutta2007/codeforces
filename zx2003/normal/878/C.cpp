#include<bits/stdc++.h>
namespace GenHelper
{
    unsigned z1,z2,z3,z4,b;
    unsigned rand_()
    {
    b=((z1<<6)^z1)>>13;
    z1=((z1&4294967294U)<<18)^b;
    b=((z2<<2)^z2)>>27;
    z2=((z2&4294967288U)<<2)^b;
    b=((z3<<13)^z3)>>21;
    z3=((z3&4294967280U)<<7)^b;
    b=((z4<<3)^z4)>>12;
    z4=((z4&4294967168U)<<13)^b;
    return (z1^z2^z3^z4);
    }
}
void srand(unsigned x)
{using namespace GenHelper;
z1=x; z2=(~x)^0x233333333U; z3=x^0x1234598766U; z4=(~x)+51;}
int rand()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}
template<typename T> class treap{
    private:
        struct node{
            node*l,*r,*a[2];
            int p,size,w;
            T v;
            node(T _v):v(_v){l=r=a[0]=a[1]=NULL,p=rand(),w=size=1;}
            void maintain(){size=w+(l?l->size:0)+(r?r->size:0);}
        };
        node*head,*mi;
        void lturn(node* &x){
            node*t=x->r;
            x->r=t->l;
            t->l=x;
            x->maintain();
            t->maintain();
            x=t;
        }
        void rturn(node* &x){
            node*t=x->l;
            x->l=t->r;
            t->r=x;
            x->maintain();
            t->maintain();
            x=t;
        }
        void ins(node* &o,T y,node*fa,int v){
            if(o==NULL){
                o=new node(y);
                o->a[v^1]=fa;
                o->a[v]=fa->a[v];
                if(fa->a[v])fa->a[v]->a[v^1]=o;
                fa->a[v]=o;
            }else if(y>o->v){
                ins(o->r,y,o,1);
                if(o->r->p>o->p)lturn(o);
            }else if(y<o->v){
                ins(o->l,y,o,0);
                if(o->l->p>o->p)rturn(o);
            }else ++o->w;
            o->maintain();
        }
        void del(node* &x,T y){
            if(x==NULL)return;
            if(y>x->v)del(x->r,y);
                else if(y<x->v)del(x->l,y);
                    else{
                        if(x->w>1){
                            --x->size;
                            --x->w;
                            return;
                        }
                        if(x->l==NULL){
                            node*z=x;
                            if(x->a[0])x->a[0]->a[1]=x->a[1];
                            if(x->a[1])x->a[1]->a[0]=x->a[0];
                            x=x->r;
                            delete z;
                            return;
                        }
                        if(x->r==NULL){
                            node*z=x;
                            if(x->a[0])x->a[0]->a[1]=x->a[1];
                            if(x->a[1])x->a[1]->a[0]=x->a[0];
                            x=x->l;
                            delete z;
                            return;
                        }
                        if(x->l->p>x->r->p){                                        
                            rturn(x);
                            del(x->r,y);
                        }else{
                            lturn(x);
                            del(x->l,y);
                        }
                    }
            if(x!=NULL)--x->size;
        }
    public:
        struct iterator{
            node* x;
            iterator(node*_x=NULL):x(_x){}
            bool operator!=(const iterator&rhs)const{return x!=rhs.x;}
            bool operator==(const iterator&rhs)const{return x==rhs.x;}
            T operator*(){return x->v;}
            iterator operator++(){return x=x->a[1];}
            iterator operator++(int){static node*t;t=x;x=x->a[1];return t;}
            iterator operator--(){return x=x->a[0];}
            iterator operator--(int){static node*t;t=x;x=x->a[0];return t;}
        };
        
        treap(){srand(19260817);}
        inline void insert(T x){
            if(head==NULL)mi=head=new node(x);
                else ins(head,x,NULL,0),mi=mi->a[0]?mi->a[0]:mi;
        }
        inline void erase(T x){
            mi=mi->v==x && mi->w==1?mi->a[1]:mi;del(head,x);
        }
        inline void erase(iterator x){
            erase(*x);
        }
        inline int rank(T y){
            register node*x=head;
            register int ans=0,s;
            while(x!=NULL){
                s=x->l?x->l->size:0;
                if(y==x->v)return ans+s+1;
                if(y>x->v){
                    ans+=s+x->w;
                    x=x->r;
                }else x=x->l;
            }
            return ans+1;
        }
        inline T kth(T y){
            register node*x=head;
            register int u,v;
            for(;;){
                u=x->l?x->l->size:0,v=x->w;
                if(u<y && u+v>=y)return x->v;
                if(y>u+v){
                    x=x->r;
                    y-=u+v;
                }else x=x->l;
            }
        }
        inline iterator prec(T y){
            node*x=head,*t=NULL;
            while(x!=NULL){
                if(x->v>=y)x=x->l;
                    else{
                        t=x;
                        x=x->r;
                    }
            }     
            return t;
        }
        inline iterator succ(T y){
            node*x=head,*t=NULL;
            while(x)
                if(x->v<=y)x=x->r;
                    else{
                        t=x;
                        x=x->l;
                    }
            return t;
        }
        inline iterator find(T v){
            register node*x=head;
            for(;x && x->v!=v;x=v<x->v?x->l:x->r);
            return x;
        }
        inline int count(T v){
            register iterator t=find(v);return t.x?t.x->w:0;
        }
        inline iterator begin(){return mi;}
        inline iterator end(){return NULL;}
};
const int N=50005;
int sz[N],f[N],n,i,k,a[N][12],j,b[12],c[12],l;
struct node{
	int i,x;
	node(int _i=0,int _x=1):i(_i),x(_x){}
	inline bool operator==(const node&rhs)const{return i==rhs.i;}
	inline bool operator!=(const node&rhs)const{return i!=rhs.i;}
	inline bool operator<(const node&rhs)const{return a[i][x]<a[rhs.i][rhs.x];}
	inline bool operator>(const node&rhs)const{return a[i][x]>a[rhs.i][rhs.x];}
};
treap<node> t;
treap<node>::iterator it,en;
std::set<node> s[12];
std::set<node>::iterator it1,it2;
inline int gfa(int x){return f[x]==x?x:f[x]=gfa(f[x]);}
inline void un(int x,int y){x=gfa(x),y=gfa(y);if(x!=y)f[x]=y,sz[y]+=sz[x];}
inline bool cmp(int x,int y){static int i;for(i=1;i<=k;++i)if(a[x][i]>=a[y][i])return 1;return 0;}
int main(){
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;++i){*b=*c=0;
		f[i]=i,sz[i]=1;for(j=1;j<=k;++j){
			scanf("%d",a[i]+j);
			it1=s[j].upper_bound((node){i,j}),it2=it1;
			if(it1!=s[j].begin())b[++*b]=(--it1)->i;
			if(it2!=s[j].end())c[++*c]=it2->i;s[j].insert((node){i,j});
		}
		//printf("%d\n",t.count(3));
		for(j=1;j<=*b;++j)
			for(l=1;l<=*c;++l){
				b[j]=gfa(b[j]),c[l]=gfa(c[l]);
				if(b[j]==c[l] || t.rank(b[j])>t.rank(c[l])){
					for(it=t.find(c[l]),en=t.find(b[j]);it!=en;)
						un((*it).i,b[j]),t.erase(it++);
					un(i,b[j]);
				}
			}
		if(f[i]==i)t.insert(i);
		printf("%d\n",sz[gfa(s[1].rbegin()->i)]);
	}
	return 0;
}