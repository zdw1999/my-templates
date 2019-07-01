#include<bits/stdc++.h>
#define N 100010
#define ull unsigned long long
using namespace std;

int Mp[N<<1];
char str[N],Ma[N<<1];

void Manacher(int len)
{
    int l=0;
    Ma[l++]='$';
    Ma[l++]='#';
    for(int i=0; i<len; i++)
    {
        Ma[l++]=str[i];
        Ma[l++]='#';
    }
    Ma[l]=0;
    int mx=0,id=0;
    for(int i=0; i<l; i++)
    {
        Mp[i]=mx>i?min(Mp[2*id-i],mx-i):1;
        while(Ma[i+Mp[i]]==Ma[i-Mp[i]])Mp[i]++;
        if(i+Mp[i]>mx)
        {
            mx=i+Mp[i];
            id=i;
        }
    }
}

map<ull,int>book;

bool check(int l,int mid)
{
    ull sum=0;
    for(int i=l; i<=mid; i++)
        sum=sum*23+(str[i]-'A'+1);
    if(book[sum])return false;
    book[sum]=1;
    return true;
}

int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        book.clear();
        scanf("%s",str);
        int len=strlen(str);
        Manacher(len);
        int maxx=0;
        for(int i=0; i<2*len+2; i++)
            if(Mp[i]-1>maxx)maxx=Mp[i]-1;
        int ans=0,l,mid;
        for(int i=0; i<2*len+2; i++)
            if(Mp[i]-1==maxx)
            {
                if(maxx&1)
                {
                    mid=i/2-1;
                    l=(mid-maxx/2);
                }
                else
                {
                    mid=i/2;
                    l=mid-maxx/2;
                    mid--;
                }
                if(check(l,mid))
                    ans++;
            }
        printf("%d\n",ans);
    }
    return 0;
}
