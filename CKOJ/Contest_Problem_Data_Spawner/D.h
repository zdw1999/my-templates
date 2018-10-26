#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e6+5;
int A[N];

int main(){
	int T,P,l; ll x;
	cin>>T>>P;
	A[0]=0; A[1]=A[2]=1;
	for(l=3;l<N;++l){
		A[l]=(A[l-2]+A[l-1])%P;
		if(A[l]==0&&A[l-1]==1)break;
	}
	while(T--){
		scanf("%lld",&x);
		printf("%d\n",A[x%l]);
	}
	return 0;
}
