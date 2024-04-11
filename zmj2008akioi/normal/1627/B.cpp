#include <cstdio>
#include <vector>
#include <algorithm>
int t,n,m;
std::vector<int> vector;
inline int abs(int x){return x>0?x:(-x);}
int dis(int sx,int sy,int tx,int ty){return abs(sx-tx)+abs(sy-ty);}
inline int max(int x,int y){return x>y?x:y;}
int main(){
	scanf("%d",&t);
	do{
		scanf("%d %d",&n,&m);
		vector.clear();
		for(register int i=1;i<=n;++i)for(register int j=1;j<=m;++j)vector.push_back(max(max(dis(1,1,i,j),dis(n,1,i,j)),max(dis(1,m,i,j),dis(n,m,i,j))));
		std::sort(vector.begin(),vector.end());
		for(register int i=0;i<(int)vector.size();++i)printf("%d ",vector[i]);
		putchar('\n');
	}while(--t);
	return 0;
}