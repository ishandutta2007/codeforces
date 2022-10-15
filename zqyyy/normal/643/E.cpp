#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=5e5+7,D=60;
int n,Q,fa[N];
double f[N][D+7];
int main(){
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	Q=read(),n=1;
	for(int i=1;i<=D;i++)f[1][i]=1;
	while(Q--){
		int opt=read(),x=read();
		if(opt==1){
			fa[++n]=x,x=n;
			vector<int>vec;
			for(int i=1;i<=D;i++)f[x][i]=1;
			for(int i=1;i<=D+1 && x;i++)vec.push_back(x),x=fa[x];
			for(int i=vec.size()-1;i>1;i--)f[vec[i]][i]/=(f[vec[i-1]][i-1]+1)/2;
			for(int i=1;i<(int)vec.size();i++)f[vec[i]][i]*=(f[vec[i-1]][i-1]+1)/2;
		}else{
			double ans=D-1;
			for(int i=D-1;i;i--)ans-=f[x][i];
			printf("%.10lf\n",ans);
		}
	}
	return 0;
}