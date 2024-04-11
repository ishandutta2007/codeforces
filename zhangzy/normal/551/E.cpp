#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int bsz=3000;

int n,q,tot,bel[500500],L[3333],R[3333];
ll a[500500],up[3333];
ll value[3333][3333],siz[3333];
struct P{
	ll val,pos;
}sb;
vector<P>vec[3333],t1,t2;
bool cmp(P p1,P p2){
	return p1.val<p2.val;
}

void fix(int who,int st,int en,int v){
	t1.clear();t2.clear();
	for (int i=0;i<=R[who]-L[who];i++){
		if (vec[who][i].pos<st||vec[who][i].pos>en){
			t1.push_back(vec[who][i]);
		}else{
			t2.push_back((P){vec[who][i].val+v,vec[who][i].pos});
		}
	}
	t1.push_back(sb);t2.push_back(sb);
	vec[who].clear();siz[who]=0;
	int p1=0,p2=0;
	for (int i=0;i<=R[who]-L[who];i++){
		if (t1[p1].val<t2[p2].val){
			vec[who].push_back(t1[p1++]);
		}else{
			vec[who].push_back(t2[p2++]);
		}
		value[who][++siz[who]]=(vec[who][i].val);
	}
	value[who][++siz[who]]=(sb.val);
}

bool fin(int who,ll v){
	v-=up[who];if (v<0) return 0;
	int p=lower_bound(value[who]+1,value[who]+siz[who]+1,(ll)v)-value[who];
	return value[who][p]==v;
}

int main(){
	scanf("%d%d",&n,&q);
	for (int i=1;i<=n;i++){
		tot=bel[i]=(i-1)/bsz+1;
	}
	for (int i=1;i<=tot;i++){
		L[i]=(R[i]=i*bsz)-bsz+1;
	}
	R[tot]=n;
	
	for (int i=1;i<=n;i++){
		scanf("%I64d",&a[i]);
	}
	sb.pos=0;sb.val=6666666666666666;
	for (int i=1;i<=tot;i++){
		vec[i].clear();
		for (int j=L[i];j<=R[i];j++){
			vec[i].push_back((P){a[j],j});
		}
		sort(vec[i].begin(),vec[i].end(),cmp);
		fix(i,L[i],R[i],0);
	}
	memset(up,0,sizeof up);
	for (int type,l,r,v,b1,b2,nnd=0;q--;){
		scanf("%d",&type);
		if (type==1){
			scanf("%d%d%d",&l,&r,&v);
			b1=bel[l];b2=bel[r];
			for (int i=b1+1;i<b2;i++){
				up[i]+=v;
			}
			if (b1==b2){
				fix(b1,l,r,v);
			}else{
				fix(b1,l,R[b1],v);
				fix(b2,L[b2],r,v);
			}
		}else{
			nnd++;
			scanf("%d",&v);
			b1=1;
			while (b1<=tot&&!fin(b1,v)) b1++;
			if (b1>tot){
				printf("-1\n");
				continue;
			}else{
				l=23333333;
				for (int i=0;i<=R[b1]-L[b1];i++){
					if (vec[b1][i].val+up[b1]==v){
						l=min(l,(int)vec[b1][i].pos);
					}
				}
			}
			
			b2=tot;
			while (b2>0&&!fin(b2,v)) b2--;
			if (b2<=0){
				printf("-1\n");
				continue;
			}else{
				r=0;
				for (int i=0;i<=R[b2]-L[b2];i++){
					if (vec[b2][i].val+up[b2]==v){
						r=max(r,(int)vec[b2][i].pos);
					}
				}
			}
			printf("%d\n",r-l);
		}
	}
}