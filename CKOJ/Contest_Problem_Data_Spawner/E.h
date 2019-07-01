//#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;

const int N=1e5+5;
int A[N],n;

int main(){
	memset(A,0,sizeof(A));
	scanf("%d",&n);
	for(int i=1,x;i<=n;++i){
		scanf("%d",&x);
		++A[x];
	}
	ll ans=0;
	for(int i=n-1,l=0,r=n-1;i>=0;--i){
		while(A[i]>1){
			while(A[i]>1&&r>i){
				if(!A[r]){
					ans+=r-i;
					++A[r];
					--A[i];
				}
				--r;
			}
			while(A[i]>1&&l<i){
				if(!A[l]){
					ans+=n-(i-l);
					++A[l];
					--A[i];
				}
				++l;
			}
		}
	}
	return !printf("%lld\n",ans);
}
