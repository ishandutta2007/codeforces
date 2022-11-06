#include<stdio.h>
#include<deque>
std::deque<int>Q;
int g[3002][3002],h[3002][3002],n,m,x,y,z,a,b;long long ans=0;
int main(){
	scanf("%d%d%d%d%d%d%d%d",&n,&m,&a,&b,&g[1][1],&x,&y,&z);
	for(int i=1;i<=n;i++){
		for(int j=2;j<=m;j++)g[i][j]=((long long)g[i][j-1]*x+y)%z;
		g[i+1][1]=((long long)g[i][m]*x+y)%z;
	}
	for(int i=1;i<=n;i++){Q.clear();
		for(int j=1;j<=m;j++){
			while(!Q.empty()&&g[i][Q.back()]>=g[i][j])Q.pop_back();
			Q.push_back(j);if(Q.front()<=j-b)Q.pop_front();
			h[i][j]=g[i][Q.front()];
		}
	}
	for(int j=1;j<=m;j++){Q.clear();
		for(int i=1;i<=n;i++){
			while(!Q.empty()&&h[Q.back()][j]>=h[i][j])Q.pop_back();
			Q.push_back(i);if(Q.front()<=i-a)Q.pop_front();
			g[i][j]=h[Q.front()][j];
		}
	}
	for(int i=a;i<=n;i++)for(int j=b;j<=m;j++)ans=ans+g[i][j];
	printf("%lld",ans);
}