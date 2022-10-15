#include<cstdio>
#include<cctype>

#define maxn 202202

template<class T>

inline T read(){
    T r=0,f=0;
    char c;
    while(!isdigit(c=getchar()))f|=(c=='-');
    while(isdigit(c))r=(r<<1)+(r<<3)+(c^48),c=getchar();
    return f?-r:r;
}

int n,l,r,c[maxn],cnt[maxn],del[maxn];

bool used[maxn];

inline void change(){
	int ans=0;
	for(int i=1;i<=l;i++)
	    ans+=!used[i];
	printf("%d\n",ans);
}

int cntl[maxn],cntr[maxn];

inline void workl(){
	int ans=0;
	int d=(l-r)/2;
	for(int i=1;i<=l&&d;i++){
		if(used[i])continue;
		if(cntl[c[i]]<2)continue;
		ans++,cntl[c[i]]-=2,d--;
	}
	for(int i=1;i<=n;i++)
		ans+=cntr[i];
    ans+=2*d;
	printf("%d\n",ans);
}

inline void workr(){
	int ans=0;
	int d=(r-l)/2;
	for(int i=l+1;i<=n&&d;i++){
		if(del[c[i]]){
			del[c[i]]--;
			continue;
		}
		if(cntr[c[i]]<2)continue;
		ans++,cntr[c[i]]-=2,d--;
	}
	for(int i=1;i<=n;i++)
		ans+=cntl[i];
    ans+=2*d;
	printf("%d\n",ans);
}

inline void work(){
	n=read<int>();
	l=read<int>();
	r=read<int>();
	for(int i=1;i<=n;i++)
		c[i]=read<int>(),cntl[i]=cntr[i]=del[i]=0;
	for(int i=1;i<=l;i++)cntl[c[i]]++;
	for(int i=l+1;i<=n;i++)cntr[c[i]]++;
	for(int i=1;i<=l;i++){
		used[i]=0;
		if(!cntr[c[i]])continue;
		cntl[c[i]]--,cntr[c[i]]--;
		del[c[i]]++;
		used[i]=1;
	}
    if(l==r)return change();
	else if(l>r)return workl();
	else return workr();
}

int main(){
	int t=read<int>();
	while(t--)work();
    return 0;
}