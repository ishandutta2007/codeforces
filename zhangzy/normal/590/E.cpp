#include<bits/stdc++.h>
using namespace std;

const int N=10001000;

int n; char s[N];

bitset<777>G[777];

namespace ac{
  int ch[N][2],fai[N],fa[N],cnt,id[N];
  int qu[N],qt;
  void init(){
    memset(ch,0,sizeof ch);
    cnt=1; for (int i=0;i<2;++i) ch[0][i]=1;
    memset(fai,0,sizeof fai);
  }
  int add(char *s,int who){
    int l=strlen(s),p=1,c;
    for (int i=0;i<l;++i){
      c=s[i]-'a';
      if (!ch[p][c]){
		ch[p][c]=++cnt;
		fa[cnt]=p;
	  }
      p=ch[p][c];
    }
	id[p]=who;
    return p;
  }
  void build(){
    queue<int>q;
    for (;!q.empty();) q.pop();
    q.push(1); qt=0;
    int x,y;
    for (;!q.empty();){
      x=q.front(); q.pop(); qu[++qt]=x;
      for (int i=0;i<2;++i)
		if (y=ch[x][i]){
			fai[y]=ch[fai[x]][i];
			q.push(y);
		}else{
			ch[x][i]=ch[fai[x]][i];
		}
    }
  }

  	int las[N];
	void fuck(){
		for (int it=1;it<=cnt;++it){
			int i=qu[it];
			las[i]=las[fai[i]];
			if (id[i]){
				if (las[i]){
					G[id[i]][las[i]]=1;
					//printf("   fai %d %d\n",id[i],las[i]);
				}
				las[i]=id[i];
			}
		}
		for (int i=1;i<=cnt;++i)
			if (id[i]){
				int p=fa[i];
				while (p>1){
					//printf(" - %d %d\n",id[i],p);
					if (las[p]){
						G[id[i]][las[p]]=1;
						//printf("   els %d %d\n",id[i],las[p]);
					}
					p=fa[p];
				}
			}
	}
}

int pre[777], nex[777], usd[777];

int fin(int x){
	for (int i=1;i<=n;++i){
		if (usd[i]||!G[x][i]) continue;
		usd[i]=1;
		if (!pre[i]||fin(pre[i])){
			pre[i]=x;
			nex[x]=i;
			return 1;
		}
	}
	return 0;
}

int main(){
	ac::init();
	cin>>n;
	for (int i=1;i<=n;++i){
		scanf("%s",s);
		ac::add(s,i);
	}
	ac::build();
	ac::fuck();
	for (int i=1;i<=n;++i)
		for (int j=1;j<=n;++j)
			if (G[j][i])
				G[j]|=G[i];
	for (int i=1;i<=n;++i){
		G[i][i]=0;
		G[i][0]=0;
	}

	// for (int i=1;i<=n;++i){
	// 	for (int j=1;j<=n;++j)
	// 		if (G[i][j]){
	// 			printf(" %d %d\n",i,j);
	// 		}
	// }

	int ans=0, an[777];
	for (int i=1;i<=n;++i){
		memset(usd,0,sizeof usd);
		fin(i);
	}
	for (int i=1;i<=n;++i){
		if (!pre[i]) an[++ans]=i;
	}
	for (int fl=1;fl;){
		fl=0;
		for (int i=1;i<=ans;++i)
			for (int j=1;j<=ans;++j)
				if (G[an[i]][an[j]]){
					fl=1;
					an[i]=nex[an[i]];
				}
	}
	cout<<ans<<endl;
	for (int i=1;i<=ans;++i) cout<<an[i]<<' ';
	cout<<endl;
}