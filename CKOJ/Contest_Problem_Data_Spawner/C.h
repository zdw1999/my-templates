#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dis(ll a,ll b,ll c,ll d){return abs(c-a)+abs(d-b);}

int main(){
	ll T,a,b,c,d;
	cin>>T;
	while(T--){
		scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
		ll ans=dis(a,b,c,d);
		ans=min(ans,dis(-a,b,c,d)+1);
		ans=min(ans,dis(a,-b,c,d)+1);
		ans=min(ans,dis(-a,-b,c,d)+1);
		printf("%lld\n",ans);
	}
	return 0;
}
