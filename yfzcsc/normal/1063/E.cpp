#include<bits/stdc++.h>
#define maxn 1010
using namespace std;
int ptr,n,a[maxn],b[maxn],vs[maxn];
char s[maxn][maxn];
void print(){
	for(int i=1;i<=n;++i)puts(s[i]+1);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]),b[a[i]]=i;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
			s[i][j]='.';
	int pos=0;
	for(int i=n;i>=1&&pos==0;--i)
		if(a[i]!=i)pos=i;
	if(pos==0){
		printf("%d\n",n);
		print();
		return 0;
	}
	printf("%d\n",n-1);
	for(int i=1,j;i<pos;++i)if(!vs[i]){
		if(b[i]==i)continue;
		vector<int>G;
		for(j=i;!vs[j];j=b[j])
			G.push_back(j),vs[j]=1;
		int bg=max_element(G.begin(),G.end())-G.begin();
		if(G[bg]!=pos){
			int mxs=0,P,Q,zptr=ptr+G.size()-1;
			for(int k=(bg==G.size()-1?0:bg+1);k!=bg;k=(k==G.size()-1?0:k+1)){
				int nw=zptr--;
				int pos=b[G[k]];
				if(pos>G[k]){
					s[nw][G[k]]='\\';
					s[nw][pos]='\\';
				} else if(pos<G[k]){
					s[nw][G[k]]='/';
					s[nw][pos]='/';
				}
			}
			ptr+=G.size()-1;
			s[zptr+1][pos]='\\';
			s[++ptr][pos]='/';
			s[ptr][b[G[bg]]]='/';
		} else {
			int mxs=0,P,Q,zptr=n;
			for(int k=(bg==G.size()-1?0:bg+1);k!=bg;k=(k==G.size()-1?0:k+1)){
				int nw=zptr--;
				int pos=b[G[k]];
				if(pos>G[k]){
					s[nw][G[k]]='\\';
					s[nw][pos]='\\';
				} else if(pos<G[k]){
					s[nw][G[k]]='/';
					s[nw][pos]='/';
				}
			}
		}
	}
	print();
}