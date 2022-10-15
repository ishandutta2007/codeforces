#include<bits/stdc++.h>
using namespace std;
#define re register ll
#define Fr(x,y,z) for(re x=y;x<=z;x++)
#define I inline void
typedef long long ll;
char t[202000],s[202000],a[202000];
ll n,m,len,pos,sum[202000][2],ans;
struct Trie{
	int ch[202000][27],tot,siz[202000],fail[202000];
	I getfail(){
		queue<int>q;
		Fr(i,1,26){
			if(ch[0][i]){
				fail[ch[0][i]]=0;
				q.push(ch[0][i]);
			}
		}
		while(!q.empty()){
			re p=q.front();q.pop();
			Fr(i,1,26){
				if(ch[p][i]){
					fail[ch[p][i]]=ch[fail[p]][i];
					siz[ch[p][i]]+=siz[fail[ch[p][i]]];
					q.push(ch[p][i]);
				}
				else ch[p][i]=ch[fail[p]][i];
			}
		}
	}
}pf,sf;
int main(){
	scanf("%s",t+1);
	n=strlen(t+1);
	scanf("%lld",&m);pf.tot=sf.tot=0;
	Fr(i,1,m){
		scanf("%s",s+1);
		len=strlen(s+1);
		pos=0;
		Fr(i,1,len){
			if(!pf.ch[pos][s[i]-'a'+1]){
				pf.ch[pos][s[i]-'a'+1]=++pf.tot;
			}
			pos=pf.ch[pos][s[i]-'a'+1];
		}
		pf.siz[pos]++;
		reverse(s+1,s+1+len);
		pos=0;
		Fr(i,1,len){
			if(!sf.ch[pos][s[i]-'a'+1])sf.ch[pos][s[i]-'a'+1]=++sf.tot;
			pos=sf.ch[pos][s[i]-'a'+1];
		}
		sf.siz[pos]++;
	}
	pf.getfail();
	sf.getfail();
	Fr(i,1,n){
		a[i]=t[n-i+1];
	}
	pos=0;
	Fr(i,1,n){
		pos=pf.ch[pos][t[i]-'a'+1];
		sum[i][1]=1ll*pf.siz[pos];
	}
	pos=0;
	Fr(i,1,n){
		pos=sf.ch[pos][a[i]-'a'+1];
		sum[i][0]=1ll*sf.siz[pos];
	}
	Fr(i,1,n){
		ans+=(sum[i][1]*sum[n-i][0]);
	}
	cout<<ans;
    return 0;
}