#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
typedef long long ll;
#define I inline void
#define IN inline int
I read(int &res){
	res=0;re g=1;register char ch=getchar();
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
const int INF=(1<<30)+(1<<27);
int n,m,p,d,tot,ch[6060000][2];
vector<int>a;
ll ans;
I insert(int x){
	p=1;
	FOR(i,30,0){
		d=(x>>i)&1;
		if(!ch[p][d])ch[p][d]=++tot;
		p=ch[p][d];
	}
}
IN ques(int x){
	p=1;re res=0;
	FOR(i,30,0){
		d=(x>>i)&1;
		if(!ch[p][d]){
			p=ch[p][d^1];
			res+=(1<<i);
		}
		else p=ch[p][d];
	}
	return res;
}
I solve(vector<int>v,int x){
	if(v.empty()||x==-1)return;
	vector<int>v1,v2;
	F(i,0,v.size()-1){
		if((v[i]>>x)&1)v1.push_back(v[i]);
		else v2.push_back(v[i]);
	}
	if(!v1.empty()&&!v2.empty()){
		re sum=INF;
		F(i,1,tot){
			ch[i][0]=ch[i][1]=0;
		}
		tot=1;
		F(i,0,v1.size()-1){
			insert(v1[i]);
		}
		F(i,0,v2.size()-1){
			sum=min(sum,ques(v2[i]));
		}
		ans+=1ll*sum;
	}
	if(!v1.empty())solve(v1,x-1);
	if(!v2.empty())solve(v2,x-1);
}
int main(){
	read(n);
	F(i,1,n){
		read(m);a.push_back(m);
	}
	solve(a,30);
	cout<<ans;
	return 0;
}