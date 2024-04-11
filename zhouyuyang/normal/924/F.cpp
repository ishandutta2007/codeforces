#include<bits/stdc++.h>
#define mo 1000000000000000007ll
#define ll long long
#define gc getchar
using namespace std;

void upd(ll &x,ll y){
	x+=y;
}
struct node{
	int nxt;
	ll sta,v[10];
	node(){
		nxt=0;
		memset(v,0,sizeof(v));
	}
};
struct state{
	#define Mo 100007
	vector<node> nodes;
	int head[Mo];
	state(){
		memset(head,-1,sizeof(head));
	}
	size_t size() const{
		return nodes.size();
	}
	void sum(){
		for (int i=0;i<nodes.size();i++)
			for (int j=1;j<=9;j++)
				upd(nodes[i].v[j],nodes[i].v[j-1]);
	}
	void update(int at,ll key,ll v){
		int tmp=key%Mo;
		for (int i=head[tmp];i!=-1;i=nodes[i].nxt)
			if (nodes[i].sta==key){
				upd(nodes[i].v[at],v);
				return;
			}
		node now;
		now.nxt=head[tmp];
		head[tmp]=nodes.size();
		now.v[at]=v;
		now.sta=key;
		nodes.push_back(now);
	}
	ll find(int at,ll key){
		int tmp=key%Mo;
		for (int i=head[tmp];i!=-1;i=nodes[i].nxt)
			if (nodes[i].sta==key)
				return nodes[i].v[at];
		return 0;
	}
}f[11][20];
ll c[2][20],bit[15];
bitset<200> vis[15],pre[200],tmp;

struct big{
	int a[35],len;
	void read(){
		memset(a,0,sizeof(a)); 
		len=0;
		char ch=gc();
		for (;ch<'0'||ch>'9';ch=gc());
		for (;ch>='0'&&ch<='9';ch=gc())
			a[len++]=ch-48;
	}
	ll mod(){
		ll ans=0;
		for (int i=0;i<len;i++)
			ans=(10ll*ans+a[i])%mo;
		return ans;
	}
	void plus(){
		a[len-1]++;
		for (int i=len-1;i>=1;i--)
			a[i-1]+=a[i]/10,a[i]%=10;
		if (a[0]>9){
			a[0]=1;
			for (int i=1;i<=len;i++)
				a[i]=0;
			len++;
		}
	}
}L,R;

void dfs(int dep,int cnt,int sum,ll msk){
	int mx=sum+(18-cnt)*dep;
	if (!dep){
		for (int i=sum>>1;i>=0;i--)
			if (vis[dep+1][i]){
				int dif=sum-i-i;
				if (dif>1)
					f[dif][0].update(0,msk,1);
				break;
			}
		return;
	}
	tmp=pre[mx>>1];
	if (sum>>1) tmp^=pre[(sum>>1)-1];
	if ((vis[dep+1]&tmp)==tmp) return;
	vis[dep]=vis[dep+1];
	dfs(dep-1,cnt,sum,msk);
	for (;cnt<18;){
		vis[dep]|=vis[dep]<<dep;
		dfs(dep-1,++cnt,sum+=dep,msk+=bit[dep]);
	}
}
ll solve(int dif,big lim){
	ll ans=0,msk=0;
	int len=lim.len;
	state *F=f[dif];
	for (int i=0;i<len;i++)
		if (len-i>18){
			for (int j=0;j<lim.a[i];j++)
				ans+=F[len-i-1].find(9,msk);
		}
		else if (lim.a[i]){
			ans+=F[len-i].find(lim.a[i]-1,msk);
			msk+=bit[lim.a[i]];
		}
	return ans;
}
ll solve2(big lim){
	int len=lim.len;
	ll ans=0; int part=0;
	for (int i=0;i<len;i++){
		int odd=lim.a[i]>>1,even=lim.a[i]-odd;
		ans+=c[part][len-1-i]*odd+c[part^1][len-1-i]*even;
		part^=lim.a[i]&1;
	}
	return ans;
}
inline ll read(){
	ll x=0;
	char ch=gc();
	for (;ch<'0'||ch>'9';ch=gc());
	for (;ch>='0'&&ch<='9';ch=gc())
		x=x*10-48+ch;
	return x;
}
int main(){
	pre[0][0]=1;
	for (int i=1;i<=190;i++)
		pre[i]=pre[i-1],pre[i][i]=1;
	c[0][0]=1;
	for (int i=1;i<=18;i++)
		c[0][i]=c[1][i]=5ll*(c[0][i-1]+c[1][i-1])%mo;
	bit[1]=1;
	for (int i=2;i<10;i++)
		bit[i]=bit[i-1]<<5;
	vis[10].set(0);
	dfs(9,0,0,0);
	for (int i=2;i<10;i++){
		f[i][0].sum();
		for (int j=0;j<18;j++){
			state &cur=f[i][j],&nxt=f[i][j+1];
			for (int id=0,sz=cur.size();id<sz;id++){
				int cnt=j; ll way=cur.nodes[id].v[9];
				ll msk=cur.nodes[id].sta,tmp=msk;
				for (int k=1;k<10;k++,tmp>>=5){
					int rem=tmp&31;
					if (!rem) continue;
					cnt+=rem; nxt.update(k,msk-bit[k],way);
				}
				if (cnt<18)
					nxt.update(0,msk,way);
			}
			nxt.sum();
		}
	}
	int Q=read();
	while (Q--){
		L.read(); R.read();
		R.plus();
		int k=read();
		ll ans=R.mod()-L.mod();
		if (!k){
			ans-=solve2(R)-solve2(L);
			for (int i=2;i<10;i+=2)
				ans-=solve(i,R)-solve(i,L);
		}
		else
			for (int i=k+1;i<10;i++)
				ans-=solve(i,R)-solve(i,L);
		printf("%lld\n",(ans%mo+mo)%mo);
	}
	return 0; 
}