#include<cstdio>
#include<cstdlib>
#include<ctime>
#include<cstring>
class treap{
    public:
        struct node{
            node *l,*r;
            int p,size,w;
            int v;//kg
            node(int _v):v(_v){
                l=r=NULL;
                p=rand();
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
                            node*z=x;
                            x=x->r;
                            delete z;
                            return;
                        }
                        if(x->r==NULL){
                            node*z=x;
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
        void insert(int x){
            ins(head,x);
        }
        void erase(int x){
            del(head,x);
        }
        int rank(int y){
            node*x=head;
            int ans=0;
            while(x!=NULL){
                int s=0;
                if(x->l!=NULL)s=x->l->size;
                if(y==x->v)return ans+s+1;
                if(y>x->v){
                    ans+=s+x->w;
                    x=x->r;
                }else x=x->l;
            }
            return ans+1;
        }
        int lessnum(int y){
            return rank(y)-1;
        }
        int morenum(int y){
            node*x=head;
            int ans=0;
            while(x!=NULL){
                int s=0;
                if(x->r!=NULL)s=x->r->size;
                if(y==x->v)return ans+s;
                if(y<x->v){
                    ans+=s+x->w;
                    x=x->l;
                }else x=x->r;
            }
            return ans;
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
        int prev(int y){
            node*x=head,*t=NULL;
            while(x!=NULL){
                if(x->v>=y)x=x->l;
                    else{
                        t=x;
                        x=x->r;
                    }
            }     
            if(t==NULL)return -(1<<30);
                else return t->v;
        }
         int succ(int y){
             node*x=head,*t=NULL;
             while(x!=NULL){
                 if(x->v<=y)x=x->r;
                     else{
                         t=x;
                         x=x->l;
                     }
             }
             if(t==NULL)return 1<<30;
                 else return t->v;
         }
         int size(){
         	 if(head==NULL)return 0;
             return head->size;
         }
         bool find(int y){
             node*x=head;
             for(;x!=NULL &&x->v!=y;y>x->v?x=x->r:x=x->l);
             return x!=NULL;
         }
}t; 
const int N=1000005;
inline int idx(char c){
	if(c=='A')return 0;
	if(c=='C')return 1;
	if(c=='G')return 2;
	if(c=='T')return 3;
	return 4;
}
char c[N],cc[15],e[15];
int n,i,j,k,q,o,x,y,ans,l,r;
treap a[5][15][15],*s;
int main(){
	srand(time(0));
	scanf("%s",c+1);
	n=strlen(c+1);
	for(i=1;i<=n;++i)
		for(j=1;j<=10;++j)a[idx(c[i])][j][i%j].insert(i);
	scanf("%d",&q);
	while(q--){
		scanf("%d",&o);
		if(o&1){
			scanf("%d%s",&x,cc);
			j=idx(c[x]);
			for(i=1;i<=10;++i)a[j][i][x%i].erase(x);
			j=idx(*cc);
			for(i=1;i<=10;++i)a[j][i][x%i].insert(x);
			c[x]=*cc;
		}else{
			scanf("%d%d%s",&l,&r,e+1);
			j=strlen(e+1);
			ans=0;
			for(i=1;i<=j;++i){
				s=&a[idx(e[i])][j][(l+i-1)%j];
				ans+=s->rank(r+1)-s->rank(l);
			}
			printf("%d\n",ans);
		}
	}
	return 0;
}