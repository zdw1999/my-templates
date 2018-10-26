#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=200005;
int A[N],n,Q,a;
vector<int>P[N];
char s[N];

void updata(int x,int v){for(auto &i:P[x])A[i]+=v;}

int main(){

	cin>>n>>Q;
	scanf("%s",s+1);

	memset(A,0,sizeof(A));
	for(int j=0;j<N;++j)
		P[j].clear();
	for(int i=1;i<N;++i){
		for(int j=i;j<N;j+=i){
			P[j].push_back(i);
			if(s[j]=='1')++A[i];
		}
	}

	while(Q--){
		scanf("%d",&a);
		if(a==1){
			scanf("%d",&a); s[a]^=1;
			updata(a,s[a]&1?1:-1);
		} else if(a==2){
			scanf("%d",&a);
			printf("%d\n",A[a]);
		}
	}

	return 0;
}
