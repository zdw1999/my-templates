#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
	int T=100000,nd=now_data_num,P=random(2,2333);
	ll n=nd<4?nd<2?10:100000:1e18;//mx
	printf("%d %d\n",T,P);
	while(T--){
		ll x=random(1,n);
		printf("%lld\n",x);
	}
}
