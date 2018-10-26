#include<bits/stdc++.h>
#define ll long long
using namespace std;

int n,a,x;

int main(){
	scanf("%d",&n); a=0;
	for(int i=1;i<=n;++i)
		scanf("%d",&x),a+=x;
	return !printf("%d\n",a);
}
