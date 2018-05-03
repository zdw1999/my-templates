#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define ull unsigned long long
#define eps 1e-10

#define qry(it,x) for(__typeof((x).begin()) it=(x).begin();it!=(x).end();++it)
#define count_intbit(x) __builtin_popcount(x)

template<class _Tp>inline _Tp abs(const _Tp &x){return x<0?-x:x;}
template<class _Tp>inline _Tp max(const _Tp &a,const _Tp &b){return a>b?a:b;}
template<class _Tp>inline _Tp min(const _Tp &a,const _Tp &b){return a<b?a:b;}
template<class _Tp>inline void inc(_Tp &a,const _Tp &b){if(a<b)a=b;}
template<class _Tp>inline void dec(_Tp &a,const _Tp &b){if(a>b)a=b;}
template<class _Tp>inline void swp(_Tp &a,_Tp &b){_Tp c=a;a=b;b=c;}
template<class _Tp>inline bool operator ==(const _Tp &A,const _Tp &B){return !memcmp(&A,&B,sizeof(_Tp));}

#define N 1000005
struct p{ll x,y;p(){}}P[N];
std::map<ll,ll>M1,M2;
ll A[N],n,a,b,t,ans;

int main(){
	M1.clear(); M2.clear();
	memset(P,0,sizeof(P));
	scanf("%lld%lld%lld",&n,&a,&b);
	for(int i=1;i<=n;++i){
		scanf("%lld%lld%lld",&t,&P[i].x,&P[i].y);
		A[i]=a*P[i].x-P[i].y;
	}
	for(int i=1;i<=n;++i){
		++M1[P[i].x*(ll)1e9+P[i].y];
		++M2[A[i]];
	}
	for(int i=1;i<=n;++i)
		ans+=M2[A[i]]-M1[P[i].x*(ll)1e9+P[i].y];
	return !printf("%lld\n",ans);
}
