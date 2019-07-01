#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=105;
const int ha=1e9+7;

class powmod{
private:
	static const int z=15;//y<2^(z*2)
	static const int sz=1<<z;
	static const int L=sz-1;
	int P[sz],Q[sz],ha;
public:
	powmod():ha(1){}
	void init(int x,int mod){
		P[0]=Q[0]=1; ha=mod;
		for(int i=1;i<sz;++i)
			P[i]=(long long)P[i-1]*x%ha;
		Q[1]=(long long)P[L]*x%ha;
		for(int i=2;i<sz;++i)
			Q[i]=(long long)Q[i-1]*Q[1]%ha;
	}
	inline int query(const int &y){
		return (long long)P[y&L]*Q[y>>z]%ha;
	}
}A[N];

int main(){
	int n,m,x;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&x);
		A[i].init(x,ha);
	}
	scanf("%d",&m);
	while(m--){
		scanf("%d",&x);
		long long ans=0;
		for(int i=1;i<=n;++i)
			ans+=A[i].query(x);
		printf("%lld\n",ans%ha);
	}
	return 0;
}
