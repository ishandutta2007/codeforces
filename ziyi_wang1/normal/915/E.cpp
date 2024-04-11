#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
    while(!isdigit(ch)){
        if(ch=='-')g=-1;
        ch=getchar();
    }
    while(isdigit(ch)){
        res=(res<<3)+(res<<1)+(ch^48);
        ch=getchar();
    }
    res*=g;
}
struct Tree{
	int lc,rc,w,laz;
}t[15070000];
int n,m,ans,sum,X,Y,sit,root,tot;
#define L t[k].lc
#define R t[k].rc
I push_down(int k,int l,int r){
	re mid=(l+r)>>1;
	if(!L){
		L=++tot;
		t[L].lc=t[L].rc=t[L].laz=0;
		t[L].w=mid-l+1;
	}
	if(!R){
		R=++tot;
		t[R].lc=t[R].rc=t[R].laz=0;
		t[R].w=r-mid;
	}
	if(t[k].laz==1){
		re mid=(l+r)>>1;
		t[L].w=(mid-l+1);t[R].w=r-mid;
		t[L].laz=t[R].laz=t[k].laz;
		t[k].laz=0;
	}
	else{
		t[L].w=t[R].w=0;
		t[L].laz=t[R].laz=t[k].laz;
		t[k].laz=0;
	}
}
I modi(int &k,int l,int r,int x,int y,int w){
	if(!k){
		k=++tot;
		t[k].lc=t[k].rc=t[k].laz=0;
		t[k].w=r-l+1;
	}
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		if(w==1)t[k].w=(r-l+1);
		else t[k].w=0;
		t[k].laz=w;
		return;
	}
	re mid=(l+r)>>1;
	if(t[k].laz!=0)push_down(k,l,r);
	modi(L,l,mid,x,y,w);modi(R,mid+1,r,x,y,w);
	t[k].w=t[L].w+t[R].w;
}
IN ques(int &k,int l,int r,int x,int y){
	if(x>r||y<l)return 0;	
	if(!k)return min(r,y)-max(l,x)+1;
	if(x<=l&&r<=y)return t[k].w;
	if(t[k].laz!=0)push_down(k,l,r);
	re mid=(l+r)>>1;
	return ques(L,l,mid,x,y)+ques(R,mid+1,r,x,y);
}
int main(){
	read(n);read(m);ans=n;tot=0;
	while(m--){
		read(X);read(Y);read(sit);
		sit--;
		sum=ques(root,1,n,X,Y);
		//cout<<sum<<" ";
		if(!sit){
			ans-=sum;
			modi(root,1,n,X,Y,-1);
		}
		else{
			ans=(ans-sum+(Y-X+1));
			modi(root,1,n,X,Y,1);
		}
		printf("%d\n",ans);
	}	
    return 0;
}