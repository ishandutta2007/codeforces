#include<bits/stdc++.h>
using namespace std;

int n,m,t,ans;
bitset<16724>cur,now;
char s[100724];
int fa[35724],curfa[35724];
int st[18724],top,sum[18724],pos[35724];
int id,cnt,bas=17724,the;

int curGF(int x){
	return curfa[x]==x? x: curfa[x]=curGF(curfa[x]);
}
int GF(int x){
	return fa[x]==x? x: fa[x]=GF(fa[x]);
}

int main(){
	scanf("%d%d",&n,&m);
	for (int nnd=1;nnd<=n;nnd++){
		cur=now; now.reset();
		memcpy(curfa,fa,sizeof fa);
		
		top=0;
		for (int i=1;i<=m;i++){
			if (curfa[i]) {
				t=curGF(i);
				if (st[top]!=t) st[++top]=t;
			}
		}
		sort(st+1,st+top+1);
		sum[0]=bas; for (int i=1;i<=top;i++) sum[i]=sum[i-1]+(st[i-1]!=st[i]),pos[st[i]]=sum[i];
		id=sum[top];
		
		scanf("%s",s);
		for (int j=0;j<m/4;j++){
			t=isdigit(s[j])? s[j]-'0': s[j]-'A'+10;
			for (int k=0;k<4;k++)
				now[j*4+4-k]=!!(t&(1<<k));
		}
		//for (int i=1;i<=m;i++) printf("%d",now[i]?1:0); printf("\n");
		
		memset(fa,0,sizeof fa);
		for (int i=bas;i<=bas*2;i++) fa[i]=i;
		for (int i=1;i<=m;i++)
			if (now[i]&&cur[i])
				fa[i]=pos[curfa[i]];
		for (int i=2;i<=m;i++){
			if (fa[i]) continue;
			if (now[i]&&now[i-1]&&fa[i-1]){
				fa[i]=GF(i-1);
				if (now[i+1]&&fa[i+1]){
					if (GF(i)!=GF(i+1)){
						ans--;
						fa[fa[i]]=fa[i+1];
					}
				}
			}
		}
		
		for (int i=m-1;i>0;i--){
			if (fa[i]) continue;
			if (now[i]&&now[i+1]&&fa[i+1]){
				fa[i]=GF(i+1);
				if (now[i-1]&&fa[i-1]){
					if (GF(i)!=GF(i-1)){
						ans--;
						fa[fa[i]]=fa[i-1];
					}
				}
			}
		}
		
		for (int i=1;i<=m;i++){
			if (now[i]&&!fa[i]){
				if (now[i-1]){
					fa[i]=fa[i-1];
				}else{
					fa[i]=++id;
					ans++;
				}
			}
		}
	}
	cout<<ans;
}