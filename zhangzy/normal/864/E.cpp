#include<bits/stdc++.h>
using namespace std;

int n,f[23333],to=0,ans,used[23333];
struct P{
	int tim,val,id;
}t;
vector<P>v[2333];
vector<int>fa[2333];

int main(){
	scanf("%d",&n);
	int x,y,z;
	for (int i=1;i<=n;i++){
		scanf("%d%d%d",&x,&y,&z);
		if (x>=y) continue;
		v[y].push_back((P){x,z,i});
	}
	int w;
	for (int i=1;i<=2000;i++){
		for (int j=0;j<(int)v[i].size();j++){
			t=v[i][j];
			for (int k=i;k>t.tim;k--){
				if (f[k-t.tim]+t.val>f[k]){
					f[k]=f[k-t.tim]+t.val;
					fa[k]=fa[k-t.tim];
					fa[k].push_back(t.id);
				}
			}
		}
	}
	used[0]=1;
	for (int i=1;i<=4444;i++){
		ans=max(ans,f[i]);
	}
	for (int i=4444;i>0;i--){
		if (ans==f[i]){
			printf("%d\n%d\n",f[i],fa[i].size());
			for (int j=0;j<(int)fa[i].size();j++) printf("%d ",fa[i][j]);
			return 0;
		}
	}
}