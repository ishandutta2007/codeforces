#include <bits/stdc++.h>
using namespace std;
const int N=15;
int n,m,match[N],f[N];
struct Point{
	int x,y;
	void read(){
		scanf("%d%d",&x,&y);
	}
}a[N],b[N];
int cross(Point a,Point b,Point c){
	return (b.x-a.x)*(c.y-a.y)-(c.x-a.x)*(b.y-a.y);
}
int _cross(Point a,Point b,Point c){
	int ans=cross(a,b,c);
	return ans==0?0:(ans/abs(ans));
}
bool check(Point a,Point b,Point c,Point d){
	return _cross(a,c,d)*_cross(b,c,d)<0;
}
bool check2(Point a,Point b,Point c,Point d){
	return check(a,b,c,d)&&check(c,d,a,b);
}
bool dfs(int k){
	if (k>n)
		return 1;
	for (int i=1;i<=n;i++)
		if (!f[i]){
			bool flag=0;
			for (int j=1;j<k&&!flag;j++)
				if (check2(a[k],b[i],a[j],b[match[j]]))
					flag=1;
			if (flag)
				continue;
			match[k]=i;
			f[i]=1;
			if (dfs(k+1))
				return 1;
			f[i]=0;
		}
	return 0;
}
int main(){
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;i++)
		a[i].read();
	for (int i=1;i<=m;i++)
		b[i].read();
	if (n!=m){
		puts("No");
		return 0;
	}
	memset(f,0,sizeof f);
	puts(dfs(1)?"Yes":"No");
	return 0;
}