#include<bits/stdc++.h>
const int N=305;
int lv;
int n,t,i,j,su[N];
int ask(int l,int r){
	int nv,ret;
	printf("? %d %d\n",l,r);fflush(stdout);
	scanf("%d",&nv);
	ret=nv-lv;lv=nv;return ret;
}
char c[N];
bool rev[N];
void solve1(int tp){
	for(i=n-1;i>0;i-=2){
		int v;
		for(;v=ask(1,i),abs(v%2)==n%2;)
			for(j=1;j<=n;++j)rev[j]^=1;
		if(tp==0)su[i]=(i-v)/2,rev[1]?su[i]=i-su[i]:0;
		for(j=1;j<=i;++j)rev[j]^=1;
	}
}
void E(){
	printf("! %s\n",c+1);exit(0);
}
void solve2(int i){
	int v,x,z=rev[i],ov=lv;
	bool fl1=0,fl2=0;
	for(;;){
		v=ask(i,i+1);
		if(abs(v%2)==(i+1)%2)for(fl1^=1,j=1;j<=i+1;++j)rev[j]^=1;
			else for(fl2^=1,j=i;j<=n;++j)rev[j]^=1;
		if(fl1==0 && fl2==1)break;
	}
	v=lv-ov;x=(n-i+1-v)/2;if(z)x=(n-i+1)-x;
	if(x==t-su[i])c[i]='0',c[i-1]='1';else c[i]='1',c[i-1]='0';
}
void solve3(int i){
	int v,x,z=rev[i],ov=lv;
	bool fl1=0,fl2=0;
	for(;;){
		v=ask(i,i);
		if(abs(v%2)==(n-i+1)%2)for(fl1^=1,j=i;j<=n;++j)rev[j]^=1;
			else for(fl2^=1,j=1;j<=i;++j)rev[j]^=1;
		if(fl1==0 && fl2==1)break;
	}
	v=lv-ov;x=(i-v)/2;if(z)x=i-x;
	if(x==su[i-1])c[i]='0',c[i+1]='1';else c[i]='1',c[i+1]='0';
}
int main(){
	scanf("%d%d",&n,&t);lv=t;
	if(n==1){c[1]='0'+t;E();}
	solve1(0);solve1(1);if(rev[1]){ask(1,n);for(i=1;i<=n;++i)rev[i]^=1;}
	if(n%2==1){
		for(i=2;i<n;i+=2)if(i==1)c[i]=su[i]+'0';else{
			if(su[i]==su[i-2]+2)c[i]=c[i-1]='1';
				else if(su[i]==su[i-2]+0)c[i]=c[i-1]='0';
						else if(n%2==1)solve2(i);
		}
	}else{
		for(i=n-1;i>0;i-=2)if(i==1)c[i]=su[i]+'0';else{
			if(su[i]==su[i-2]+2)c[i]=c[i-1]='1';
				else if(su[i]==su[i-2]+0)c[i]=c[i-1]='0';
					else solve3(i-1);
		}
	}
	c[n]=t-su[n-1]+'0';
	E();
	return 0;
}