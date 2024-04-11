#include <cstdio>
const int N=10;
int T,n,c,tx,ty,x[N],y[N];
template<typename T>T rv(T x){return x>T()?x:-x;}
int dis(int u,int v){return rv(x[u]-x[v])+rv(y[u]-y[v]);}
void print(bool p){puts(p?"YES":"NO");}
int main(){
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=0;i<3;++i)scanf("%d %d",&x[i],&y[i]);
		scanf("%d %d",&tx,&ty);
		for(int i=0;i<3;++i)if(dis(i,(i+1)%3)==1&&dis(i,(i+2)%3)==1)c=i;
		if(x[c]==1&&y[c]==1){print(tx==1||ty==1);continue;}
		if(x[c]==1&&y[c]==n){print(tx==1||ty==n);continue;}
		if(x[c]==n&&y[c]==1){print(tx==n||ty==1);continue;}
		if(x[c]==n&&y[c]==n){print(tx==n||ty==n);continue;}
		if(((x[c]+y[c])&1)^((tx+ty)&1))print(true);
		else print((x[c]&1)==(tx&1));
	}
	return 0;
}