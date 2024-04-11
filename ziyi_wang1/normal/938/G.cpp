#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
#define C(x,y) memset(x,y,sizeof(x))
#define STS system("pause")
template<class D>I read(D &res){
	res=0;register D g=1;register char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')g=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		res=(res<<3)+(res<<1)+(ch^48);
		ch=getchar();
	}
	res*=g;
}
typedef pair<int,int>pii;
map<pii,int>mp;
struct Edge{
	int x,y,w,s,t;
}e[404000];
struct Query{
	int x,y;	
}q[202000];
struct E{
	int x,y,s;
}now;
int n,m,tot,Q,sit,X,Y,W,cnt;
int fa[202000],f[202000],dep[202000];
vector<int>vec[808000];
struct B{
	int b[40];
	I add(int x){
		FOR(i,30,0){
			if(!((x>>i)&1))continue;
			if(!b[i]){
				b[i]=x;return;
			}
			x^=b[i];
		}
	}
	IN ques(int x){
		FOR(i,30,0){
			//if(!((x>>i)&1))continue;
			if((x^b[i])<x)x^=b[i];
		}
		return x;
	}
}bas;
IN find(int x){return fa[x]==x?x:find(fa[x]);}
IN dis(int x){return fa[x]==x?0:f[x]^dis(fa[x]);}
#define all 1,1,cnt
#define lt k<<1,l,mid
#define rt k<<1|1,mid+1,r
I modi(int k,int l,int r,int x,int y,int w){
	if(x>r||y<l)return;
	if(x<=l&&r<=y){
		vec[k].emplace_back(w);return;
	}
	re mid=(l+r)>>1;
	modi(lt,x,y,w);modi(rt,x,y,w);
}
I solve(int k,int l,int r,B b){
	stack<E>st;
	vector<int>A;
	for(auto p:vec[k]){
		X=e[p].x;Y=e[p].y;W=dis(X)^dis(Y)^e[p].w;
		re fx=find(X),fy=find(Y);
		if(fx==fy)b.add(W);
		else {
			if(dep[fx]>dep[fy])swap(fx,fy),swap(X,Y);
			now=(E){fx,fy,0};
			fa[fx]=fy;f[fx]=W;
			if(dep[fx]==dep[fy])dep[fy]++,now.s=1;
			st.emplace(now);
		}
	}
	if(l==r){
		//cout<<dis(q[l].x)<<" "<<dis(q[l].y)<<endl;
		//FOR(i,30,0)cout<<b.b[i]<<" ";
		//cout<<endl;
		printf("%d\n",b.ques(dis(q[l].x)^dis(q[l].y)));
	}
	else{
		re mid=(l+r)>>1;
		solve(lt,b);solve(rt,b);
	}
	while(!st.empty()){
		f[fa[st.top().x]=st.top().x]=0;dep[st.top().y]-=st.top().s;st.pop();
	}
}
int main(){
	read(n);read(m);tot=0;
	F(i,1,n)fa[i]=i;
	F(i,1,m){
		++tot;
		read(e[tot].x);read(e[tot].y);read(e[tot].w);
		mp.insert(make_pair(make_pair(e[tot].x,e[tot].y),tot));
		e[tot].s=1;e[tot].t=-1;
	}
	read(Q);cnt=1;
	F(i,1,Q){
		read(sit);read(X);read(Y);
		if(sit==1){
			++tot;
			e[tot].x=X;e[tot].y=Y;read(e[tot].w);
			mp.insert(make_pair(make_pair(e[tot].x,e[tot].y),tot));
			e[tot].s=cnt;e[tot].t=-1;
		}
		if(sit==2)e[mp[make_pair(X,Y)]].t=cnt-1;
		if(sit==3){
			q[cnt].x=X;q[cnt].y=Y;cnt++;
		}
	}
	cnt--;
	F(i,1,tot){
		if(e[i].t==-1)e[i].t=cnt;
		if(e[i].s<=e[i].t)modi(all,e[i].s,e[i].t,i);
	}
	solve(all,bas);
	return 0;
}