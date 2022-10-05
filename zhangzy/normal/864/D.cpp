#include<bits/stdc++.h>
using namespace std;
int n,a[202000],cnt[202000]={0},pos=1,ans=0,mus[202000]={0};
queue<int>q;

int main(){
	scanf("%d",&n);
	for (int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	for (int i=1;i<=n;i++){
		if (!cnt[i]){
			q.push(i);
			ans++;
		}
	}
	for (int i=1;i<=n;i++){
		if (cnt[a[i]]==1) continue;
		if (mus[a[i]]){
			cnt[a[i]]--;
			a[i]=q.front();
			q.pop();
		}else{
			if (q.front()<a[i]){
				cnt[a[i]]--;
				a[i]=q.front();
				q.pop();
			}else{
				mus[a[i]]=1;
			}
		}
	}
	printf("%d\n",ans);
	for (int i=1;i<=n;printf("%d ",a[i++]));
}