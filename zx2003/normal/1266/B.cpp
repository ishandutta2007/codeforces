#include<bits/stdc++.h>
int t;
long long x;
int main(){
	for(scanf("%d",&t);t--;)scanf("%lld",&x),puts(x>14 && 1<=x%14 && x%14<=6?"YES":"NO");
}