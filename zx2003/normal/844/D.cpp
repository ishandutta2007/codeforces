#include<bits/stdc++.h>
using namespace std;
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
int read()
{
    using namespace GenHelper;
    int a=rand_()&32767;
    int b=rand_()&32767;
    return a*32768+b;
}
class treap{
    private:
        struct node{
            node *l,*r;
            int p,size,w;
            int v;//kg
            node(int _v):v(_v){
                l=r=NULL;
                p=read();
                w=size=1;
            }
            void maintain(){
                size=w;
                if(l!=NULL)size+=l->size;
                if(r!=NULL)size+=r->size;
            }
        };
        node*head;
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
        void ins(node* &o,int y){
            if(o==NULL)o=new node(y);
                else if(y>o->v){
                    ins(o->r,y);
                    if(o->r->p>o->p)lturn(o);
                }else if(y<o->v){
                    ins(o->l,y);
                    if(o->l->p>o->p)rturn(o);
                }else ++o->w;
            o->maintain();
        }
           void del(node* &x,int y){
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
                            x=x->r;
                            return;
                        }
                        if(x->r==NULL){
                            x=x->l;
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
        void insert(int x){
            ins(head,x);
        }
        void erase(int x){
            del(head,x);
        }
        int kth(int y){
            node*x=head;
            for(;;){
                int u=0,v=x->w;
                if(x->l!=NULL)u=x->l->size;
                if(u<y && u+v>=y)return x->v;
                if(y>u+v){
                    x=x->r;
                    y-=u+v;
                }else x=x->l;
            }
        }
}t;
int n,i,st,id,ma,x,u,v,a,b,mi;
int main(){
	scanf("%d%d%d",&n,&st,&x);
	srand(time(0)+5);
	for(i=1;i<=n;++i)if(i!=st)t.insert(i);
	
	printf("? %d\n",st);
	fflush(stdout);
	scanf("%d%d",&mi,&b);
	fflush(stdout);
	
	if(mi>=x)return printf("! %d\n",mi),fflush(stdout),0;
	
	ma=mi;
	id=st;
	for(i=2;i<=900 && i<=n;++i){
		u=read()%(n-i+1)+1;
		v=t.kth(u); 
		
		printf("? %d\n",t.kth(u));
		fflush(stdout);
		scanf("%d%d",&a,&b);
		fflush(stdout);
		
		t.erase(v);
		if(a<x && a>ma)ma=a,id=v;
	}
	for(u=id;i<1997 && u>=0;++i){
		
		printf("? %d\n",u);
		fflush(stdout);
		scanf("%d%d",&a,&b);
		fflush(stdout);
		
		if(a>=x)return printf("! %d\n",a),fflush(stdout),0;
		u=b;
	}
	puts("! -1");
	fflush(stdout);
	return 0;
}