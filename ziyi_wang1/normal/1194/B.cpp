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
struct SUM{
	int w,id;
	friend bool operator < (SUM x,SUM y){
		return x.w>y.w;
	}
}rw[50500],cl[50500];
int n,m,T,p1,p2,ans,tot=0,a[404000],sn=0;
char c[404000];
int main(){
	read(T);
	while(T--){
		read(n);read(m);tot=0;
		F(i,1,n){
			rw[i].w=0;
			rw[i].id=i;
		}
		F(i,1,m){
			cl[i].w=0;
			cl[i].id=i;
		}
		F(i,1,n){
			F(j,1,m){
				tot++;
				cin>>c[tot];
				if(c[tot]=='*'){
					a[tot]=1;rw[i].w++;cl[j].w++;	
				}
				else a[tot]=0;
			}
		}
		sort(rw+1,rw+n+1);
		sort(cl+1,cl+m+1);
		p1=1;p2=1;ans=n+m-1-rw[1].w-cl[1].w;
		while(rw[p1+1].w==rw[p1].w&&p1<n)p1++;
		while(cl[p2+1].w==cl[p2].w&&p2<m)p2++;
		sn=1;
		F(i,1,p1){
			F(j,1,p2){
				if(!a[(rw[i].id-1)*m+cl[j].id]){
					sn=0;
					break;
				}
			}
			if(!sn)break;
		}
		ans+=sn;
		printf("%d\n",ans);
	}
    return 0;
}