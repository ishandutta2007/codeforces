#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=1007;
int n,x,y;
inline int qry(vector<int>vec){
	cout<<"? "<<vec.size()<<" ";
	for(int x:vec)cout<<x<<" ";cout<<endl;
	int z=read();
	if(z==y || (z==(x^y)))return 1;
	return 0;
}
bool vis[10];
int main(){
	n=read(),x=read(),y=read();
	int p1=0,p2=0,p=0;
	for(int j=__lg(n);~j;j--){
		vector<int>vec;
		for(int i=1;i<=n;i++)if(i>>j&1)vec.push_back(i);
		if(qry(vec))p=j,vis[j]=1;
	}
	p2=1<<p;
	for(int j=__lg(n);~j;j--){
		if(p==j)continue;
		vector<int>vec;
		for(int i=1;i<=n;i++)if((i>>j&1) && (i>>p&1))vec.push_back(i);
		if(!vec.empty() && qry(vec)){
			p2|=1<<j;
			if(!vis[j])p1|=1<<j;
		}else if(vis[j])p1|=1<<j;
	}
	if(p1>p2)swap(p1,p2);
	printf("! %d %d\n",p1,p2);
	return 0;
}