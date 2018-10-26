/*************************************************

	Program: Fast I/O System
	Author: zdw1999
	Last Update: 2018-10-11 9:00
	
	Usage: 
		init_num_table();                    //at begin
		(FastInput) IN.file_init(stdin);     //at begin
		(FastInput) OUT.flush(stdout);       //at end

*************************************************/

#ifndef MY_FASTIO_H
	
	#define MY_FASTIO_H
		
	namespace zdw{

		void readint(int &x){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9')x=(x<<3)+(x<<1)+s-'0';
			if(c=='-')x=-x;
		}

		void readll(ll &x){
			char s=getchar(),c=0;
			while(~s&&s<'0'||s>'9')c=s,s=getchar(); x=s-'0';
			while(~(s=getchar())&&s>='0'&&s<='9')x=(x<<3)+(x<<1)+s-'0';
			if(c=='-')x=-x;
		}

		void _readint(char *&s,int &x){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9')x=(x<<3)+(x<<1)+w-'0';
			if(c=='-')x=-x;
		}

		void _readll(char *&s,ll &x){
			char w=*s,c;
			while(w&&w<'0'||w>'9')w=*++s;
			if(!w){x=-1;return;} c=*(s-1); x=w-'0';
			while((w=*++s)&&w>='0'&&w<='9')x=(x<<3)+(x<<1)+w-'0';
			if(c=='-')x=-x;
		}

	/*
		void _putint(const int &x){int t=x/10;if(t)_putint(t);putchar(x-t*10+'0');}
		void putint(const int &x){x<0?putchar('-'),_putint(-x):_putint(x);}

		void _putll(const ll &x){ll t=x/10;if(t)_putll(t);putchar(x-t*10+'0');}
		void putll(const ll &x){x<0?putchar('-'),_putll(-x):_putll(x);}

		void __putint(char *&s,const int &x){int t=x/10;if(t)__putint(s,t);*s++=x-t*10+'0';}
		void _putint(char *&s,const int &x){x<0?*s++='-',__putint(s,-x):__putint(s,x);}

		void __putll(char *&s,const ll &x){ll t=x/10;if(t)__putll(s,t);*s++=x-t*10+'0';}
		void _putll(char *&s,const ll &x){x<0?*s++='-',__putll(s,-x):__putll(s,x);}
	*/

		char __num_table[500001];

		void init_num_table(){
			for(int i=0;i<100000;++i){
				//sprintf(__num_table+i*5,"%05d",i);
				char *t=__num_table+i*5;
				t[0]=i/10000+'0';
				t[1]=(i/1000)%10+'0';
				t[2]=(i/100)%10+'0';
				t[3]=(i/10)%10+'0';
				t[4]=i%10+'0';
			}
		}

		void putint(int x){
			if(x<0)putchar('-'),x=-x;
			if(x<=9){putchar(x+'0');return;}
			char w[11],*p=w,*t; *p=0;
			int z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*p)putchar(*p--);
		}

		void putll(ll x){
			if(x<0)putchar('-'),x=-x;
			if(x<=9){putchar(x+'0');return;}
			char w[20],*p=w,*t; *p=0;
			ll z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*p)putchar(*p--);
		}

		void _putint(char *&s,int x){
			if(x<0)*s++='-',x=-x;
			if(x<=9){*s++=x+'0';return;}
			char w[11],*p=w,*t; *p=0;
			int z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*s++=*p--); --s;
		}

		void _putll(char *&s,ll x){
			if(x<0)*s++='-',x=-x;
			if(x<=9){*s++=x+'0';return;}
			char w[20],*p=w,*t; *p=0;
			ll z;
			while(x>9999){
				z=x/100000; t=__num_table+(x-z*100000)*5;
				p[1]=t[4]; p[2]=t[3]; p[3]=t[2]; p[4]=t[1]; p[5]=t[0];
				x=z; p+=5;
			}t=__num_table+x*5;
			t[1]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p[4]=t[1],p+=4,0:
				t[2]>'0'?p[1]=t[4],p[2]=t[3],p[3]=t[2],p+=3,0:
					t[3]>'0'?p[1]=t[4],p[2]=t[3],p+=2,0:
						t[4]>'0'?*++p=t[4],0:0;
			while(*s++=*p--); --s;
		}

		class FastInput{
		public:
			static const int MXL=83886080; //缓冲区大小(80MB)
			char *buf,*tt; int sz;         //由于判正负需要判上一位故预留1字节

			FastInput(int SZ=MXL){buf=(char*)malloc((sz=SZ)+1);tt=buf+1;*buf=*tt=0;}
			~FastInput(){free(buf);}

			void file_init(FILE *F){
				buf[fread(buf+1,1,sz,F)]=0;
				tt=buf+1;
			}

			void readint(int &x){_readint(tt,x);}
			void readll(ll &x){_readll(tt,x);}
			char getchar(){return *tt?*tt++:-1;}
			void getchar(char &c){c=(*tt?*tt++:-1);}
			void getstr(char *s){
				char w;
				while((w=*tt)&&w=='\r'||w=='\n'||w==' ')++tt;
				while((w=*tt)&&w!='\r'&&w!='\n'&&w!=' ')*s++=w,++tt;
				*s=0;
			}
			void getline(char *s){
				char w;
				while((w=*tt)&&w!='\r'&&w!='\n')*s++=w,++tt;
				tt+=*tt=='\r'?1:0; tt+=*tt=='\n'?1:0; *s=0;
			}

		};

		class FastOutput{
		public:
			static const int MXL=83886080; //缓冲区大小(80MB)
			char *buf,*tt; int sz;

			FastOutput(int SZ=MXL){buf=(char*)malloc(sz=SZ);tt=buf;}
			~FastOutput(){free(buf);}

			void flush(FILE *F){
				if(tt==buf)return;
				fwrite(buf,1,tt-buf,F);
				tt=buf;
			}

			void putint(const int &x){_putint(tt,x);}
			void putll(const ll &x){_putll(tt,x);}
			void putchar(const char &c){*tt++=c;}
			void putstr(char *s){while(*tt++=*s++);--tt;}

		};

	}

#endif
