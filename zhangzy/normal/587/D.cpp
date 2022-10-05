#include<bits/stdc++.h>
using namespace std;

namespace ts{
	#define top _top
    const int tsv=1001000,tse=10001000;
    int n,ans[tsv];
    struct R{
        int to,nex;
    }r[tse];
    int hea[tsv<<1],cnt,bel[tsv<<1],blt,st[tsv<<1],top,dfn[tsv<<1],dft,low[tsv<<1];
      
    void RE(){
        memset(hea,0,sizeof hea);cnt=0;
        memset(bel,0,sizeof bel);blt=0;
        memset(dfn,0,sizeof dfn);dft=0;
    }
    void A(int u,int v){
        r[++cnt]=(R){v,hea[u]};hea[u]=cnt;
    }
    void must(int x,int x2,int y,int y2){
        A(x<<1|x2,y<<1|y2);
        A(y<<1|y2^1,x<<1|x2^1);
    }
    void XX(int x,int x2,int y,int y2){ // can't be together
        //printf("XX::%d %d %d %d\n",x,x2,y,y2);
        must(x,x2,y,y2^1);
    }
    void dfs(int x){
        low[x]=dfn[x]=++dft;
        st[++top]=x;
        int y;
        for (int i=hea[x];i>0;i=r[i].nex){
            y=r[i].to;
            if (!dfn[y]){
                dfs(y);
                low[x]=min(low[x],low[y]);
            }else{
                if (!bel[y]){
                    low[x]=min(low[x],dfn[y]);
                }
            }
        }
        if (low[x]==dfn[x]){
            bel[x]=++blt;
            while (st[top]!=x){
                bel[st[top]]=blt;
                top--;
            }
            top--;
        }
    }
    bool realmain(int _n){
        n=_n; int u,v;
        for (int i=2;i<=(n<<1|1);i++){
            if (!bel[i]){
                top=0;
                dfs(i);
            }
        }
        for (int i=1;i<=n;i++){
            if (bel[i<<1|0]==bel[i<<1|1]) return 0;
            ans[i]=bel[i<<1|0]>bel[i<<1|1]?1:0;
        }
          
        return 1;
    }
	#undef top
}

vector<int>allp[101000];
map<int,vector<int> >cp[101000];

int n, m, tim[101000], tot;

void mostone(vector<int>vec){
	if (vec.size()<=1) return;
	for (int i=0;i<vec.size();++i){
		ts::must(vec[i],1,tot+1+i,1);
	}
	for (int i=1;i<vec.size();++i){
		ts::must(vec[i],1,tot+1+i-1,0);
		ts::must(tot+1+i,0,tot+1+i-1,0);
	}
	tot+=vec.size();
}

bool chk(int lim){
	ts::RE(); tot=m;
	for (int i=1;i<=n;++i){
		mostone(allp[i]);
	}
	for (int i=1;i<=n;++i)
		for (auto o:cp[i]){
			vector<int>vec=o.second;
			if (vec.size()>2) return 0;
			if (vec.size()<2) continue;
			ts::XX(vec[0],0,vec[1],0);
		}
	for (int i=1;i<=m;++i)
		if (tim[i]>lim){
			ts::A(i<<1|1,i<<1|0);
		}
	return ts::realmain(tot);
}

int main(){
	cin>>n>>m;
	for (int i=1;i<=m;++i){
		int x, y, c;
		cin>>x>>y>>c>>tim[i];
		allp[x].push_back(i);
		allp[y].push_back(i);
		cp[x][c].push_back(i);
		cp[y][c].push_back(i);
	}
	int l=0, r=1e9+7, res=-1;
	while (l<=r){
		int mid=l+r>>1;
		if (chk(mid)){
			res=mid; r=mid-1;
		}else{
			l=mid+1;
		}
	}
	if (res==-1){
		puts("No");
		return 0;
	}
	chk(res);
	puts("Yes");
	int tot=0;
	for (int i=1;i<=m;++i) tot+=ts::ans[i];
	cout<<res<<' '<<tot<<endl;
	for (int i=1;i<=m;++i) if (ts::ans[i]) cout<<i<<' ';
	cout<<endl;
}