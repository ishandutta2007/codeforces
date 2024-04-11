#include<bits/stdc++.h>
using namespace std;
#define re register int
#define F(x,y,z) for(re x=y;x<=z;x++)
#define FOR(x,y,z) for(re x=y;x>=z;x--)
#define I inline void
#define IN inline int
typedef long long ll;
I read(int &res){
    re g=1;register char ch=getchar();res=0;
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
struct E{
	int to,nt;
}e[202000],t[202000];
#define T e[k].to
#define D t[k].to
int n,m,head[101000],h[101000],sum,tot=-1,X,Y,a[100100],v[101000],f[101000];
int dep[101000],siz[101000],son[101000],fa[100100],id[101000],top[101000];
int s[101000],num,sn,b[101000];
I add(int x,int y){
	//cout<<"!"<<x<<" "<<y<<endl;
	t[++sum].to=y;
	t[sum].nt=h[x];
	h[x]=sum;
	t[++sum].to=x;
	t[sum].nt=h[y];
	h[y]=sum;
}
I D_1(int x,int fat,int depth){
	dep[x]=depth;siz[x]=1;fa[x]=fat;son[x]=-1;
	re maxi=-1;
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fat)continue;
		D_1(T,x,depth+1);
		siz[x]+=siz[T];
		if(siz[T]>maxi)maxi=siz[T],son[x]=T;
	}
}
I D_2(int x,int fat,int topi){
	top[x]=topi;id[x]=++tot;//cout<<x<<" "<<id[x]<<endl;
	if(son[x]!=-1)D_2(son[x],x,topi);
	for(re k=head[x];k!=-1;k=e[k].nt){
		if(T==fat||T==son[x])continue;
		D_2(T,x,T);
	}
}
inline bool bbb(int x,int y){
	return id[x]<id[y];
}
IN ques_lca(int x,int y){
	while(top[x]!=top[y]){
		if(dep[top[x]]<dep[top[y]])swap(x,y);
		x=fa[top[x]];
	}
	if(dep[x]>dep[y])swap(x,y);
	return x;
}
I insert(int x){
	if(num<=1){s[++num]=x;return;}
	re lca=ques_lca(x,s[num]);
	if(s[num]==lca){s[++num]=x;return;}
	while(num>1&&id[s[num-1]]>=id[lca])add(s[num-1],s[num]),num--;
	if(s[num]!=lca)add(s[num],lca),s[num]=lca;
	s[++num]=x;
}
IN D_3(int x,int fat){	
	re ans=0,cnt=0;
	for(re k=h[x];k!=-1;k=t[k].nt){
		if(D==fat)continue;
		ans+=D_3(D,x);cnt+=b[D];b[D]=0;
	}
	if(v[x])b[x]=1,ans+=cnt;
	else if(cnt>1)b[x]=0,ans++;
	else b[x]=cnt;
	h[x]=-1;
	return ans;
}
int main(){
	read(n);
	memset(head,-1,(n+1)<<2);
	F(i,1,n-1){
		read(X);read(Y);
		e[++tot].to=Y;
		e[tot].nt=head[X];
		head[X]=tot;
		e[++tot].to=X;
		e[tot].nt=head[Y];
		head[Y]=tot;
	}
	D_1(1,0,1);
	tot=0;
	D_2(1,0,1);
	memset(h,-1,sizeof(h));
	read(m);
	while(m--){
		read(tot);sum=-1;sn=1;
		F(i,1,tot){
			read(a[i]);
			v[a[i]]=1;
		}
		sort(a+1,a+1+tot,bbb);
		s[1]=1;s[0]=0;num=1;
		F(i,1,tot){
			if(v[fa[a[i]]]){
				printf("-1\n");
				sn=0;break;
			}
		}
		if(!sn){
			F(i,1,tot)v[a[i]]=0;
			continue;
		}
		F(i,1,tot){
			if(a[i]==1)continue;insert(a[i]);
		}
		while(num)add(s[num-1],s[num]),num--;
		//system("pause");
		printf("%d\n",D_3(1,0));
		F(i,1,tot)v[a[i]]=0,b[a[i]]=0;
	}
    return 0;
}