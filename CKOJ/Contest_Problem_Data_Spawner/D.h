#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>

namespace Solve_D{
	
	const int MXL=67200000;
	char buf[MXL],*tt;
	
	void readint(char *&s,int &x){
		while(*s&&*s<'0'||*s>'9')++s; x=*s++-'0';
		while(*s&&*s>='0'&&*s<='9')x=(x<<3)+(x<<1)+*s++-'0';
	}
	
	void file_init(){
		buf[fread(buf,1,MXL,stdin)]=0;
		tt=buf;
	}
	
	void _putint(const int &x){
		int t=x/10;
		if(t)_putint(t);
		putchar(x-t*10+'0');
	}
	
	void putint(const int &x){x<0?putchar('-'),_putint(-x):_putint(x);}
	
	const int MXN=200005;
	const int MXM=2000005;
	
	struct node{node *nxt;int t;node(node *a=0,int b=0):nxt(a),t(b){}}_G[MXN<<1],*G[MXN]; int gtop;
	inline void insert(int f,int t){_G[gtop].nxt=G[f];_G[gtop].t=t;G[f]=_G+gtop++;}
	inline void clear(){memset(G,gtop=0,sizeof(G));}
	
	int fa[MXN],A[MXM],B[MXM],C[MXN],D[MXN],f[MXN],n,m,tflg;
	int tp(const int &x){return f[x]==x?x&&C[fa[f[x]]]?f[x]=tp(fa[f[x]]):x:f[x]=tp(f[x]);}
	//void u(int x,int y){x=tp(x);y=tp(y);x!=y?D[x]<D[y]?f[y]=x:f[x]=y;}
	
	void bfs(int st){
		int Q[MXN],l,r; Q[l=r=0]=st;
		fa[st]=1; D[st]=1;
		while(l<=r){
			int now=Q[l++];
			for(node *i=G[now];i;i=i->nxt)
				if(!fa[i->t])
					D[i->t]=D[fa[Q[++r]=i->t]=now]+1;
		}fa[st]=0;
	}
	
	void init(){
		//scanf("%d%d",&n,&m);
		readint(tt,n); readint(tt,m);
		memset(f,0,sizeof(f));
		memset(C,0,sizeof(C));
		memset(fa,0,sizeof(fa));
		D[0]=0; C[0]=1; clear();
		for(int i=2,t;i<=n;++i){
			//scanf("%d",&t);
			readint(tt,t);
			insert(t,i);
			insert(i,t);
		}for(int i=1;i<=m;++i){
			//scanf("%d%d",A+i,B+i);
			readint(tt,A[i]);
			readint(tt,B[i]);
		}bfs(1);
	}
	
	inline int color(const int &a,const int &b,const int &c){
		
		if(C[a]&&C[b]){
			if(tp(a)==tp(b))return tp(a);//end1
			if(D[tp(a)]==D[tp(b)])return f[a]=f[b]=color(fa[f[a]],fa[f[b]],c);
			return D[tp(a)]>D[tp(b)]?fa[a]=color(fa[f[a]],b,c):f[b]=color(a,fa[f[b]],c);
		}
		
		if(!C[a]&&!C[b]){
			if(a==b){//end2
				C[a]=c;
				if(C[fa[a]])return f[a]=tp(fa[a]);
				else return f[a]=a;
			}
			if(D[a]>D[b]){C[a]=c;return f[a]=color(fa[a],b,c);}
			if(D[a]<D[b]){C[b]=c;return f[b]=color(a,fa[b],c);}
			C[a]=C[b]=c; return f[a]=f[b]=color(fa[a],fa[b],c);
		}
		
		if(C[a]){
			if(D[tp(a)]>D[b])return f[a]=color(fa[f[a]],b,c);
			C[b]=c; return f[b]=color(a,fa[b],c);
		}
		
		//if C[b]
		if(D[tp(b)]>D[a])return f[b]=color(a,fa[f[b]],c);
		C[a]=c; return f[a]=color(fa[a],b,c);
		
	}
	
	void Solve(){
		for(int i=m;i>=1;--i){
			tflg=i;
			color(A[i],B[i],i);
		}
		for(int i=1;i<=n;++i)
			putint(C[i]),putchar('\n');//printf("%d\n",C[i]);
	}
	
};


int main(){
	
	int T;scanf("%d",&T);
	Solve_D::file_init();
	
	while(T--){
		Solve_D::init();
		Solve_D::Solve();
	}
	
	return 0;
}
