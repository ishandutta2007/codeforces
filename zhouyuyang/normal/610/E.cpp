#include<bits/stdc++.h>
using namespace std;
const int MAX=2e5+9;
int n,m,k,seg[MAX*4][11][11],lazy[MAX*4],le[MAX*4],ri[MAX*4];
string a,p;
void build(int s=0,int e=n,int id=0)
{
	if (e-s==1) {le[id]=ri[id]=a[s]-'a';return ;}
	int mid=s+e>>1;
	build(s,mid,id*2+1),build(mid,e,id*2+2);
	for (int i=0;i<11;i++) for (int j=0;j<11;j++) seg[id][i][j]=seg[id*2+1][i][j]+seg[id*2+2][i][j];
	seg[id][ri[id*2+1]][le[id*2+2]]++,le[id]=le[id*2+1],ri[id]=ri[id*2+2];
}
void d(int id){for (int i=0;i<11;i++) for (int j=0;j<11;j++) seg[id][i][j]=0;}
void shift(int id,int s,int e,int mid)
{
	if (lazy[id]!=-1)
	{
		d(id*2+1),d(id*2+2);
		seg[id*2+1][lazy[id]][lazy[id]]=mid-s-1,seg[id*2+2][lazy[id]][lazy[id]]=e-mid-1;
		le[id*2+1]=ri[id*2+1]=le[id*2+2]=ri[id*2+2]=lazy[id*2+1]=lazy[id*2+2]=lazy[id];	
	}
	lazy[id]=-1;
}
void upd(int l,int r,int ch,int s=0,int e=n,int id=0)
{
	if (r<=s || e<=l) return; 
	if (l<=s && e<=r){le[id]=ri[id]=lazy[id]=ch,d(id),seg[id][ch][ch]=e-s-1;return ;}
	int mid=s+e>>1;
	shift(id,s,e,mid),upd(l,r,ch,s,mid,id*2+1),upd(l,r,ch,mid,e,id*2+2);
	for (int i=0;i<11;i++) for (int j=0;j<11;j++) seg[id][i][j]=seg[id*2+1][i][j]+seg[id*2+2][i][j];
	seg[id][ri[id*2+1]][le[id*2+2]]++,le[id]=le[id*2+1],ri[id]=ri[id*2+2];
}
int main()
{
	memset(lazy,-1,sizeof lazy),ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>n>>m>>k>>a,build();
	while (m--)
	{
		int t,l,r,ans=1;
		cin>>t;
		if (t==1) cin>>l>>r>>p,upd(l-1,r,p[0]-'a'); else
		{
			cin>>p;
			for (int i=0;i<k;i++) for (int j=i;j<k;j++) ans+=seg[0][p[j]-'a'][p[i]-'a'];
			cout<<ans<<'\n';
		}
	}
}