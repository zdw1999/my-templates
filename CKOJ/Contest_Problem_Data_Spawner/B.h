#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=105;

int main(){
	map<int,int>M;
	vector<int>ans;
	int n,m,x;
	scanf("%d",&n);
	while(n--){
		scanf("%d",&x);
		++M[-x];
	}
	while(m>0&&!M.empty()){
		auto it=M.begin(); ++m;
		while(it!=M.end()&&m>0){
			ans.push_back(it->first); --m;
			if(it->second==1)M.erase(it++);
			else it->second-=1;
		}
	}
	if(m>0)return !printf("-1");
	for(auto &i:ans)printf("%d ",-i);

	return 0;
}
