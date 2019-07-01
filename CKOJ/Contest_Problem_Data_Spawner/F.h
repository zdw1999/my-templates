#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
zdw::StringDoubleHash H(N);
zdw::StringDoubleHashResult R[N];
char s[N];

int main(){

	int n,Q,a,b,x,y,l,r,m;
	scanf("%d%d",&n,&Q);
	for(int i=1;i<=n;++i){
		scanf("%s",s);
		R[i].clear();
		R[i]=H.culc_hash(s,strlen(s));
	}

	while(Q--){
		scanf("%d%d%d%d",&a,&x,&b,&y); --x; --y;
		l=0,r=min(R[a].len-x,R[b].len-y),m;
		while(r>0&&l<r){
			m=l+r+1>>1;
			//errmsg("%lld %lld\n\n",H.gethash(R[a],x,x+m-1),H.gethash(R[b],y,y+m-1));
			if(H.gethash(R[a],x,x+m-1)!=H.gethash(R[b],y,y+m-1))r=m-1;
			else l=m;
		}
		printf("%d\n",l);
	}

	return 0;
}
