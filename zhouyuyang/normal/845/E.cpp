#include<bits/stdc++.h>
using namespace std;

int n,m,k,fx[555],fy[555],now;

struct L{
	int st,en,height,type;
}l[5555],tmp;
int g;
map<int,int>mp;
map<int,int>::iterator it;
int to[5555],tid,las;
int p1,p2,h,c[5555];

bool cmp(L l1,L l2){
	return l1.height<l2.height;
}

bool check(){
	g=0;
	for (int i=1;i<=k;i++){
		l[++g]=(L){max(0,fx[i]-now-1),min(n,fx[i]+now),max(1,fy[i]-now),1};
		l[++g]=(L){max(0,fx[i]-now-1),min(n,fx[i]+now),min(m+1,fy[i]+now+1),-1};	
	}
	l[++g]=(L){0,n,m,0};
	l[++g]=(L){0,n,1,0};
	mp.clear();mp[0]=mp[n]=1;
	for (int i=1;i<=g;i++){
		mp[l[i].st]=mp[l[i].en]=1;
	}
	tid=0;
	for (it=mp.begin();it!=mp.end();it++){
		to[mp[(int)it->first]=++tid]=(int)it->first;
	}
	for (int i=1;i<=g;i++){
		l[i].st=mp[l[i].st];l[i].en=mp[l[i].en];
	}
	sort(l+1,l+g+1,cmp);
	p1=1;p2=n;h=-1;
	memset(c,0,sizeof c);
	for (int i=1;i<=g;i=las){
		tmp=l[i];
		if (tmp.height!=1){
			for (int j=1;j<tid;j++){
				if (c[j]<=0){
					if (tmp.height-1-h>now) return 0;
				}
			}
		}
		if (tmp.height>m) return 1;
		for (las=i;l[las].height==l[i].height;las++){
			tmp=l[las];
			for (int j=tmp.st;j<tmp.en;j++){
				c[j]+=tmp.type; 
			}
		}
		for (int j=1;j<tid;j++){
			if (c[j]<=0){
				if (h==-1) h=l[i].height+now;
				if (abs(l[i].height-h)>now) return 0;
				p1=max(p1,to[j+1]-now);
				p2=min(p2,to[j]+1+now);
				if (p1>p2) return 0;
			}
		}
	}
	return 1;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for (int i=1;i<=k;i++) scanf("%d%d",&fx[i],&fy[i]);
	int l=0,r=1010001000,ans;
	for (;l<=r;){
		now=(l+r)>>1;
		if (check()){
			r=(ans=now)-1;
		}else{
			l=now+1;
		}
	}
	cout<<ans;
}