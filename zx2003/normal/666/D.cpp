#include<bits/stdc++.h>
using namespace std;
struct P{
	int x,y;
	inline void in(){scanf("%d%d",&x,&y);}
	inline void out(){printf("%d %d\n",x,y);}
	inline void rev(){swap(x,y);}
}a[4],b[4];
int T,i,j,ans,p[4],z[4],zz[4],x,ass[6],mt[6][6];
bool FL=0;
inline void work(int x,int y,int ox,int oy,int hh,int i,int tp){
	int w=hh==0?a[y].y-a[x].y:a[y].x-a[x].x,ww=hh==0?a[x].x-a[y].x:a[x].y-a[y].y;
	if(ox==oy && ox==hh){
		if(w)FL=1;
		mt[5][x]+=tp;mt[5][y]-=tp;mt[5][4]+=tp*ww;
		return;
	}
	if(ox!=oy){
		if(ox==hh)swap(x,y),swap(ox,oy),w*=-1,ww*=-1,tp*=-1;
		mt[i][x]=1;mt[i][4]=w;
		mt[5][y]-=tp;mt[5][4]+=tp*ww;
		return;
	}
	mt[i][x]=1;mt[i][y]=-1;mt[i][4]=w;
	mt[5][4]+=tp*ww;
}
inline bool gauss(){
	int i,j,k,t;
	for(i=1;i<5;++i){
		for(j=i;j<6;++j)if(mt[j][i-1])break;
		if(j!=i)for(k=0;k<5;++k)swap(mt[i][k],mt[j][k]);
		if(!mt[i][i-1])return 0;
		for(j=1;j<6;++j)if(j!=i && mt[j][i-1])
			for(t=mt[j][i-1]/mt[i][i-1],k=0;k<5;++k)mt[j][k]-=mt[i][k]*t;
	}
	if(mt[5][4])return 0;
	for(i=1;i<5;++i){
		t=mt[i][4]/mt[i][i-1];
		ass[i]=t;if(ass[i]*mt[i][i-1]!=mt[i][4])return 0;
	}
	return 1;
}
int main(){
	for(scanf("%d",&T);T--;){
		ans=-1;
		for(i=0;i<4;++i)a[i].in();
		for(i=0;i<16;++i){
			for(j=0;j<4;++j)p[j]=j;
			do{
				if(i==0 || i==15){
					if(i==15)for(j=0,swap(p[0],p[2]);j<4;++j)a[j].rev();
					if(a[p[0]].y!=a[p[1]].y || a[p[2]].y!=a[p[3]].y || a[p[0]].y<=a[p[3]].y);else{
						int c=a[p[0]].y-a[p[3]].y;
						z[0]=0;z[1]=c+a[p[0]].x-a[p[1]].x;
						z[3]=a[p[0]].x-a[p[3]].x;z[2]=z[3]+c+a[p[3]].x-a[p[2]].x;
						memcpy(zz,z,16);sort(z,z+4);x=z[3]-z[0]+1>>1;
						if(ans==-1 || x<ans){
							ans=x;
							x=-(z[0]+z[3])/2;for(j=0;j<4;++j)b[p[j]]=a[p[j]],b[p[j]].x+=zz[j]+x;
							if(i==15)for(j=0;j<4;++j)b[j].rev();
						}
					}
					if(i==15)for(j=0,swap(p[0],p[2]);j<4;++j)a[j].rev();
				}else{
if(i==7 && p[0]==3 && p[1]==0 && p[2]==1 && p[3]==2)
++i,--i;
					for(j=1;j<6;++j)memset(mt[j],0,sizeof mt[j]);FL=0;
					work(p[0],p[1],i>>p[0]&1,i>>p[1]&1,0,1,1);
					work(p[1],p[2],i>>p[1]&1,i>>p[2]&1,1,2,1);
					work(p[2],p[3],i>>p[2]&1,i>>p[3]&1,0,3,0);
					work(p[3],p[0],i>>p[3]&1,i>>p[0]&1,1,4,0);
					if(FL)continue;
					mt[5][4]*=-1;
					if(!gauss())continue;
					int mx=0;for(j=1;j<5;++j)mx=max(mx,abs(ass[j]));
					if(ans==-1 || mx<ans){
						ans=mx;
						for(j=0;j<4;++j)b[j]=a[j],(i>>j&1?b[j].y:b[j].x)+=ass[j+1];
					}
				}
			}while(next_permutation(p,p+4));
		}
		printf("%d\n",ans);if(ans!=-1)for(i=0;i<4;++i)b[i].out();
	}
}