#include <bits/stdc++.h>
#define ll long long

namespace Solve_E{
	
	const int N=10005;
	
	struct node{node *nxt;int t;node(node *a=0,int b=0):nxt(a),t(b){}}*G[N];
	inline void insert(int f,int t){G[f]=new node(G[f],t);}
	inline void clear(node *&x){if(!x)return;clear(x->nxt);delete x;x=0;}
	
	long long V[N],n,m,f[N][105];
	std::map<int,long long>F[N];/*
	template<class __A,class __B>
	class Hash{
	private:
		static const int size=2000;
		__B *hash; __A *O; int sz;
	public:
		Hash(int hash_size=size){ sz=hash_size;
			hash=(__B *)malloc(sizeof(__B)*sz);
			O=(__A *)malloc(sizeof(__A)*sz);
			memset(O,0xff,sizeof(__A)*sz);
		}~Hash(){free(O);free(hash);}
		__B &operator [](const __A &_O){
			int loc=_O%sz;
			while(~O[loc]&&O[loc]!=_O){
				++loc;
				if(loc>=sz)loc=0;
			}if(!~O[loc])hash[O[loc]=_O]=0;
			return hash[loc];
		}
		void clear(){memset(O,0xff,sizeof(__A)*sz);}
	};Hash<int,long long>F[N];*/
	
	void init(){
		for(int i=0;i<=n;++i){
			F[i].clear();
			clear(G[i]);
		}memset(f,0xff,sizeof(f));
		scanf("%lld%lld",&n,&m);
		for(int i=1,t;i<=n;++i){
			scanf("%lld%d",&V[i],&t);
			insert(t,i);
		}
	}
	
	long long Solve_std(int now,int mem){
		if(mem==0)return 0;
		if(mem==1)return V[now];
		if(F[now][mem])return F[now][mem];
		//long long *tmp=(long long*)malloc(S[now]*sizeof(long long));
		long long ret=0,tmp,tt=0;
		for(node *i=G[now];i;i=i->nxt)
			ret+=Solve_std(i->t,mem-1);
		for(node *i=G[now];i;i=i->nxt){
			tmp=Solve_std(i->t,mem)-Solve_std(i->t,mem-1);
			if(tmp>tt)tt=tmp;
		}return F[now][mem]=ret+V[now]+tt;
	}
	
	long long Solve_std(){return Solve_std(G[0]->t,m);}
	
	long long fuck(int now,int mem){
		if(~f[now][mem])return f[now][mem];
		if(mem==1)return f[now][mem]=V[now];
		if(mem==0)return f[now][mem]=0;
		for(node *j=G[now];j;j=j->nxt)fuck(j->t,mem);
		f[now][0]=0; f[now][1]=V[now];
		for(int i=2;i<=mem;++i){
			long long t=0,tt=0;
			for(node *j=G[now];j;j=j->nxt)
				t+=f[j->t][i-1];
			for(node *j=G[now];j;j=j->nxt){
				t+=(f[j->t][i]-f[j->t][i-1]);
				if(t>tt)tt=t;
				t-=(f[j->t][i]-f[j->t][i-1]);
			}f[now][i]=std::max(f[now][i-1],tt+V[now]);
		}return f[now][mem];
	}
	
	long long fuck(){return fuck(G[0]->t,m);}
};

int main(){
	
	int T;
	scanf("%d",&T);
	
	while(T--){
		
		Solve_E::init();
		
		long long out=/*Solve_E::Solve_std()*/Solve_E::fuck();/*
		long long ans=now_data_num<6?Solve_E::fuck():-1;
		
		if(~ans&&ans!=out){
			fprintf(stderr,"Error on test #%d !\n",now_data_num);
			fprintf(stderr,"Ans=%lld, Out=%lld.\n",ans,out);
			
			continue;
		} else fprintf(stderr,"Ans=%lld\n",out);
		*/
		printf("%lld\n",out);
		
	}
	
	return 0;
	
}
