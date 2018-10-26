#pragma GCC optimize(3)
#include <bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;

const int N=1e5+5;
ll C[N],L[N],R[N],A[N],B[N],T,n,m,h;

int32_t main(){
	cin>>T;// errmsg("%lld\n",T);
	while(T--){
		set<ll>S;
		cin>>n>>m;
		for(int i=1;i<=m;++i)
			scanf("%d%d%d",L+i,R+i,A+i);
		cin>>h;
		for(int i=1;i<=h;++i){
			scanf("%d",B+i);
			S.insert(B[i]);
		}
		for(int i=m;i>=1;--i){
			auto st=S.lower_bound(L[i]);
			auto ed=S.upper_bound(R[i]);
			while(st!=ed){
				C[*st]=A[i];
				S.erase(st++);
			}
			if(S.empty())break;
		}
		for(auto it=S.begin();it!=S.end();)C[*it]=0,S.erase(it++);
		for(int i=1;i<=h;++i)
			printf(i==h?"%d\n":"%d ",C[B[i]]);
	}
	return 0;
}

