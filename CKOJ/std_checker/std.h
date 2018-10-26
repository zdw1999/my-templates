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

#define N 200005
ll A[N];
std::priority_queue<ll>Q;

int main(){
    memset(A,0,sizeof(A));
    ll n,k,l,i,j,ans=0;
    while(!Q.empty())Q.pop();
    scanf("%lld%lld%lld",&n,&k,&l);
    for(i=1;i<=n*k;++i)
        scanf("%lld",A+i);
    std::sort(A+1,A+n*k+1);
    for(i=1;i<=n*k;++i){
        if(A[i]-A[1]<=l)Q.push(A[i]);
        else break;
    }ll tt=n*k-i+1;
    if(Q.size()<n)return !printf("0\n");
    while(n--){
        if(tt>=k-1)ans+=Q.top(),Q.pop(),tt-=k-1;
        else {
            tt=k-1-tt;
            while(tt--)Q.pop();
            ans+=Q.top();
        }
    }return !printf("%lld\n",ans);
}
