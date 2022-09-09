#include<bits/stdc++.h>
const int N=100005,mo=998244353,p=1000003,invp=993335002;
char c[N];
int n,i,l,r,l1[N],id,le,x,y,z,a1,a2,a3,ans;
int h1[N],add1,h2[N],add2,mi[N],mii[N];
int ch[N<<1][26],step[N<<1],pre[N<<1],mn[N<<1],a[N<<1],b[N<<1],lst,xb;
int main(){
	n=fread(c+1,1,N,stdin);while(!isalpha(c[n]))--n;lst=xb=1;
	for(i=*mi=*mii=1;i<=n;++i){
		mi[i]=1ll*mi[i-1]*p%mo;mii[i]=1ll*mii[i-1]*invp%mo;
		int np,p,q,nq;
		x=c[i]-'a';step[np=++xb]=step[p=lst]+1;
		for(;p && !ch[p][x];p=pre[p])ch[p][x]=np;
		if(p){
			q=ch[p][x];
			if(step[p]+1!=step[q]){
				step[nq=++xb]=step[p]+1;mn[nq]=N;
				memcpy(ch[nq],ch[q],104);
				pre[nq]=pre[q],pre[q]=pre[np]=nq;
				for(;ch[p][x]==q;p=pre[p])ch[p][x]=nq;
			}else pre[np]=q;
		}else pre[np]=1;
		mn[lst=np]=i;
	}
	for(i=1;i<=xb;++i)++b[step[i]];
	for(i=1;b[i];++i)b[i]+=b[i-1];
	for(i=1;i<=xb;++i)a[b[step[i]]--]=i;
	for(i=xb;i;--i){x=a[i];if(mn[pre[x]]>mn[x])mn[pre[x]]=mn[x];}
	for(i=x=1;;++i){
		if(!ch[x][c[n-i+1]-'a']){--i;break;}
		l1[i]=mn[x=ch[x][c[n-i+1]-'a']];
		if(l1[i]>=n-i+1){--i;break;}
	}
	if(l1[i]==n-i)--i;
	l=r=n-i;h1[l]=h2[l]=c[l]-'a';le=1;id=l;
	for(;i>=0;--i){
		for(;l>l1[i]+1;){
			--l;h2[l]=(1ll*p*h2[l+1]+c[l]-'a')%mo;
			h1[l]=mo-1ll*add1*mi[l]%mo;add1=(add1+1ll*mii[l]*(c[l]-'a'))%mo;
			if(r-l+1>=le+2){
				x=(h1[l+le+1]+1ll*add1*mi[l+le+1])%mo;
				y=(h2[l]+1ll*add2*mii[l])%mo;
				if(l+le+2<=r)z=(h2[l+le+2]+1ll*add2*mii[l+le+2])%mo;
					else z=0;
				y=(y+mo-1ll*mi[le+2]*z%mo)%mo;
				if(y==x)le+=2,id=l;
			}
		}
		for(;r<n-i;){
			++r;h1[r]=(1ll*p*h1[r-1]+c[r]-'a')%mo;
			h2[r]=mo-1ll*add2*mii[r]%mo;add2=(add2+1ll*mi[r]*(c[r]-'a'))%mo;
			if(r-l+1>=le+2){
				x=(h1[r]+1ll*add1*mi[r])%mo;
				if(r-le-2>=l)z=(h1[r-le-2]+1ll*add1*mi[r-le-2])%mo;
					else z=0;
				x=1ll*mii[r+1-l-le-2]*(x+mo-z)%mo;
				y=(y+mo-1ll*mi[le+2]*z%mo)%mo;
				if(x==y)le+=2,id=r-le-1;
			}
		}
		if(le+i*2>ans)ans=le+i*2,a1=l1[i]-i+1,a2=id,a3=n-i+1;
	}
	l=n-a3+1;printf("%d\n",(a3<=n?2:0)+(a2?1:0));
	if(a3<=n)printf("%d %d\n",a1,l);
	if(a2)printf("%d %d\n",a2,ans-l*2);
	if(a3<=n)printf("%d %d\n",a3,l);
	return 0;
}