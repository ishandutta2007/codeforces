#include<bits/stdc++.h>
#define LL long long
using namespace std;
int read(){
	char ch=getchar(); int w=1,c=0;
	for(;!isdigit(ch);ch=getchar()) if (ch=='-') w=-1;
	for(;isdigit(ch);ch=getchar()) c=(c<<1)+(c<<3)+(ch^48);
	return w*c;
}
const int M=1010;
struct node{
	int x,y;
}a[M],b[M],f[M][M],ans;
int n;
map<pair<int,int> ,int > mp;
int main(){
	n=read();
	for (int i=1;i<=n;i++){
		a[i]=(node){read(),read()};
	}
	for (int i=1;i<=n;i++){
		b[i]=(node){read(),read()};
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			f[i][j]=(node){a[i].x+b[j].x,a[i].y+b[j].y};
			mp[make_pair(f[i][j].x,f[i][j].y)]++;
			if (mp[make_pair(f[i][j].x,f[i][j].y)]==n)
			ans=f[i][j];
		}
	}
	cout<<ans.x<<" "<<ans.y<<"\n";
	return 0;
}