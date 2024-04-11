#include<bits/stdc++.h>
using namespace std;
bool vis[1000];
int T,h,op,q[100],l,r,a[10],b[10],sz,s,st1[100],s1[100],st2[100],s2[100];
bool getlist(int a[],int &sz,int x){
	op++;
	printf("? %d\n",x);
	fflush(stdout);
	scanf("%d",&sz);
	for(int i=1;i<=sz;++i)
		scanf("%d",&a[i]);
	random_shuffle(a+1,a+sz+1);
	if(sz==2){
		printf("! %d\n",x);
		fflush(stdout);
		return 1;
	}
	return 0;
}
int main(){
	srand(time(0));
	scanf("%d",&T);
	while(T--){
		scanf("%d",&h),s=1<<h,op=0;
		for(int i=1;i<s;++i)vis[i]=0;
		int bg=rand()%(s-1)+1,dep=0;
//		int bg=10,dep=4;
		if(getlist(a,sz,bg))continue;
		vis[bg]=1;
//		printf("[<%d>]",a[1]);
		if(sz==1){
			bg=a[1],dep=h-1;
			vis[bg]=1;
		} else {
			int lc=a[1],ld=0,rc=a[2],o=a[3],rd=0,t1=0,t2=0;
			while(1){
				ld++;
				st1[++t1]=lc,vis[lc]=1;
				if(getlist(a,sz,lc))goto _end;
				if(sz==1)break;
				else {
					for(int i=1;i<=3;++i)if(!vis[a[i]])lc=a[i];
					for(int i=1;i<=3;++i)if(!vis[a[i]]&&lc!=a[i])s1[t1]=a[i];
				}
			}
			while(1){
				rd++;
				st2[++t2]=rc,vis[rc]=1;
				if(getlist(a,sz,rc))goto _end;
				if(sz==1)break;
				else {
					for(int i=1;i<=3;++i)if(!vis[a[i]])rc=a[i];
					for(int i=1;i<=3;++i)if(!vis[a[i]]&&rc!=a[i])s2[t2]=a[i];
				}
			}
//			printf("[%d]",bg);
			if(ld==rd)bg=o,dep=h-ld-1;
			else if(ld<rd)bg=s2[(rd-ld)/2],dep=h-ld-(rd-ld)/2-1;
			else bg=s1[(ld-rd)/2],dep=h-rd-(ld-rd)/2-1; 
		}
		vis[bg]=1;
		if(dep==1){
			printf("! %d\n",bg);
			fflush(stdout);
			goto _end;
		}
		while(dep>3){
			if(getlist(a,sz,bg))goto _end;
			int lc,ld=0,t1=0,rc;
			vis[bg]=1;
			for(int i=1;i<=3;++i)if(!vis[a[i]])
				lc=a[i];
			for(int i=1;i<=3;++i)if(!vis[a[i]]&&lc!=a[i])
				rc=a[i];
			while(1){
				ld++;
				st1[++t1]=lc,vis[lc]=1;
				
//				printf("[lc=%d,%d]\n",lc,s1[t1]);
				if(getlist(a,sz,lc))goto _end;
				if(sz==1)break;
				else {
					for(int i=1;i<=3;++i)if(!vis[a[i]])lc=a[i];
					for(int i=1;i<=3;++i)if(!vis[a[i]]&&lc!=a[i])s1[t1]=a[i];
				}
			}
//			printf("[%d,%d,%d]",ld,dep,bg);
			if(ld==h-dep)dep--,bg=rc;
			else bg=s1[(ld-(h-dep))/2],dep-=(ld-(h-dep))/2+1;
//			printf("[->%d]\n",bg);
		}
//		printf("[final:%d,%d]\n",bg,dep);
		l=r=0,q[r++]=bg;
		while(l<r&&op<=15){
			int u=q[l++];vis[u]=1;
			if(getlist(a,sz,u))goto _end;
			for(int i=1;i<=sz;++i)if(!vis[a[i]])
				q[r++]=a[i];
		}
		printf("! %d\n",q[l]);
		fflush(stdout);
		_end:;
	}
}