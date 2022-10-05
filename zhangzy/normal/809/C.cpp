#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
#define mod 1000000007
#define nsz (1<<now)
#define thep (pair<int,pii>){up,(pii){x,y}}
#define ok 256
using namespace std;
int a[1100][1100],r[258][258][258],s[258][258][258];

map<pair<int,pii>,pii>mp;
void operator += (pii &p1,pii p2){
	p1.fi+=p2.fi; if (p1.fi>=mod) p1.fi-=mod;
	p1.se+=p2.se; if (p1.se>=mod) p1.se-=mod;
}

pii C(int x,int y,int up,int now){
	if (x<=0||y<=0||up<=0) return (pii){0,0};
	if (x>y) swap(x,y);
	
	for (;y<=nsz&&now;now--);
	up=min(up,nsz<<1);
	
	if (y<=ok) return (pii){s[min(up,ok)][x][y],r[min(up,ok)][x][y]};
	if (mp.count(thep)) return mp[thep];
	
	pii res=(pii){0,0},t;
	
	t=C(min(x,nsz),min(y,nsz),up,now);
	res+=t;
	
	t=C(x-nsz,min(y,nsz),up-nsz,now);
	t.fi=(t.fi+(ll)t.se*nsz)%mod;
	res+=t;
	
	t=C(min(x,nsz),y-nsz,up-nsz,now);
	t.fi=(t.fi+(ll)t.se*nsz)%mod;
	res+=t;
	
	t=C(x-nsz,y-nsz,up,now);
	res+=t;
	
	mp[thep]=res;
	//printf(" %d %d %d %d(%d)  %d,%d\n",x,y,up,now,nsz,res.fi,res.se);
	return res;
}

void mcp(int sz,int x,int y,int ex){
	for (int i=1;i<=sz;i++)
		for (int j=1;j<=sz;j++)
			a[x+i][y+j]=a[i][j]+ex;
}

int main(){
	a[1][1]=a[2][2]=1;
	a[1][2]=a[2][1]=2;
	for (int i=1;i<10;i++){
		mcp(1<<i,1<<i,0,1<<i);
		mcp(1<<i,0,1<<i,1<<i);
		mcp(1<<i,1<<i,1<<i,0);
	}
	memset(s,0,sizeof s);
	for (int up=1;up<=256;up++)
		for (int i=1;i<=256;i++)
			for (int j=1;j<=256;j++){
				s[up][i][j]=s[up][i-1][j]+s[up][i][j-1]-s[up][i-1][j-1]+(a[i][j]>up?0:a[i][j]);
				r[up][i][j]=r[up][i-1][j]+r[up][i][j-1]-r[up][i-1][j-1]+(a[i][j]>up?0:1);
			}
				
	int T,x,xx,y,yy,k;
	for (scanf("%d",&T);T--;){
		scanf("%d%d%d%d%d",&x,&y,&xx,&yy,&k);
		printf("%I64d\n",((ll)C(xx,yy,k,30).fi-C(x-1,yy,k,30).fi-C(xx,y-1,k,30).fi+C(x-1,y-1,k,30).fi+mod*233ll)%mod);
	}
}