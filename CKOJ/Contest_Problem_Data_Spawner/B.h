#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main(){
    ll T,a,b,c,d,e,f;
    cin>>T;
    while(T--){
		scanf("%lld%lld%lld%lld%lld%lld",&a,&b,&c,&d,&e,&f);
		ll ans=0,x;
		ans+=x=min(b,d); b-=x; d-=x;
		ans+=x=min(c,e); c-=x; e-=x;
		ans+=x=min(a,f); a-=x; f-=x;

		x=min(a,d); a-=x; d-=x;
		x=min(b,e); b-=x; e-=x;
		x=min(c,f); c-=x; f-=x;

		ans-=a+b+c;
		printf("%lld\n",ans);
    }
    return 0;
}
