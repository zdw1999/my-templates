#include <bits/stdc++.h>
#define ll long long

namespace Solve_C{
	
	ll n,ans;
	
	ll culc(ll x){
		ll res=0;
		while(x)res+=x%3,x/=3;
		return res;
	}
	
	void Solve(){
		scanf("%lld",&n); ans=0;
		while(n>2)++ans,n=culc(n);
		printf("%lld %lld\n",ans,n);
	}
	
};

int main(){
	
	int T;
	
	for(std::cin>>T;T--;)
		Solve_C::Solve();
	
	return 0;
}
