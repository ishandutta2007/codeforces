#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=3e5+5,M=N*3;
int n,i,j,l,r,scnt,s1;
bool bb[M];int w1[M],bbel[M];ll w2[M];
struct seg{
	int l,r,c,bel;
	bool operator<(const seg&rhs)const{return r<rhs.r;}
};
set<seg>S;
vector<int>ve[N],in[N],out[N];
void del(seg s){S.erase(s);out[i].push_back(s.c);}
void ins(seg s){
	s.c=++scnt;w1[scnt]=s.r-s.l+1;w2[scnt]=1ll*w1[scnt]*s.bel;bbel[scnt]=s.bel;
	S.insert(s);in[i].push_back(s.c);ve[s.bel].push_back(s.c);
}
ll s2,s3,s4,k;
void rmv(int x){if(bb[x])bb[x]=0,s1-=w1[x],s2-=w2[x];}
void calc(int lm){
	s1=s2=s3=s4=0;
	memset(bb+1,0,scnt);
	for(i=1,j=0;i<=n;++i){
		for(int x:out[i])rmv(x);for(int x:in[i])if(bbel[x]>=j)bb[x]=1,s1+=w1[x],s2+=w2[x];
		for(;s1>lm || !j;++j)for(int x:ve[j])rmv(x);s3+=s2-1ll*s1*(j-1);s4+=i-j+1;
	}
}
int main(){
	ios::sync_with_stdio(0);cin.tie(0);
	cin>>n>>k;
	S.insert((seg){1,1<<30,0,0});
	for(i=1;i<=n;++i){
		cin>>l>>r;--r;
		auto it=S.lower_bound((seg){0,l,0,0});
		if(it->l<l)ins((seg){it->l,l-1,0,it->bel});
		if(it->r>=r){
			seg tmp=*it;del(*it);if(r<tmp.r)tmp.l=r+1,ins(tmp);
		}else{
			for(;it!=S.end() && it->r<=r;)del(*it++);
			if(it!=S.end() && it->l<=r){seg tmp=*it;del(*it);tmp.l=r+1;ins(tmp);}
		}
		ins((seg){l,r,0,i});
	}
	calc(1<<30);ll ts3=s3;k=s4-k;
	int le=0,ri=1e9,mid;
	for(;le<ri;){
		mid=le+ri>>1;
		calc(mid);if(s4>=k)ri=mid;else le=mid+1;
	}
	calc(le);
	cout<<ts3-(s3-1ll*(s4-k)*le)<<endl;
	return 0;
}