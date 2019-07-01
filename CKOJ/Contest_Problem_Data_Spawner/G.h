#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int M=50;
const int N=1e5+5;
const int ha=1e9+7;
const unsigned Z=(1<<8)-1;
const unsigned ZZ=(1<<24)-1;
//设字符串总长10w, 则每个字符最多转移50次,最多共500w个创建节点操作
//500w*(26*8(4)+4*3)=110000(58000)w = 550MB 所以用map压缩空间...
//500w*60=30000w  好像也没少多少,还可能浪费更多常数空间
//然而之前我们可以用一个char+short强行存500w(实际足够了)
//于是500w*(26*3+4*3)=45000w = 429MB, 够用了(毒瘤!)

//做法2: 离线, 将所有价值串建AC自动机

struct trie_node{// tot_size=48+4*3=60 char
	//map<char,trie_node *>son;//size = 48, long long=8
	unsigned char son[26*3];
	int v1,v2,len;
	inline unsigned getson(const char &c){
		return (unsigned)son[c*3]<<16|(unsigned)son[c*3+1]<<8|son[c*3+2];
	}
	inline void setson(const char &c,const unsigned &x){
		son[c*3]=x>>16;
		son[c*3+1]=x>>8;
		son[c*3+2]=x;
	}
	trie_node(){v1=v2=len=0;}
};

struct trie{
	trie_node *A;
	unsigned p,Q[M];
	trie(){
		A=(trie_node *)malloc(N*M*sizeof(trie_node));
		clear();
	}
	~trie(){free(A);}
	void clear(){
		memset(A,0,N*M*sizeof(trie_node));
		memset(Q,0,sizeof(Q)); p=1;
	}
	inline unsigned getson(const unsigned &u,unsigned char c){
		c-='a';
		unsigned s=A[u].getson(c);
		if(!s)A[u].setson(c,s=++p);
		A[s].len=A[u].len+1;
		return s;
	}
	inline int modify(char *s,const int &v){
		unsigned t=1;
		while(*s)t=getson(t,*s++);
		int res=v-A[t].v1;
		A[t].v1=v;
		return res*A[t].v2;
	}
	inline int add(char *S){
		int res=0;
		while(*S){
			for(int i=0;i<M;++i){
				if(!Q[i]){
					Q[i]=getson(1,*S);
					res+=A[Q[i]].v1;
					A[Q[i]].v2++;
					break;
				}
				if(Q[i].len==M)
					Q[i]=getson(1,*S);
				else Q[i]=getson(Q[i],*S);
				res+=A[Q[i]].v1;
				A[Q[i]].v2++;
			}
			++S;
		}
		return res;
	}
};


char s[1000055];
int r,Q,x,ans;

int main(){
	trie T;
	scanf("%d",&Q); r=0;
	while(Q--){
		scanf("%d",&x);
		if(x==3){//query
			printf("%d\n",ans);
		} else {
			scanf("%s",s+r);
			if(x==1){
				scanf("%d",&x);
				ans+=T.modify(s+r,x);
			} else {
				ans+=T.add(s+r);
				while(s[r])++r;
			}
		}
	}
	return 0;
}
