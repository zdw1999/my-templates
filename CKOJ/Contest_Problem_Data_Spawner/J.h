#include<bits/stdc++.h>
#define N 100010
#define ll long long
#define inf 9999999999
using namespace std;
ll a[N];
int main()
{
	memset(a,0,sizeof(a));
    int n;
    scanf("%d",&n);
    ll Sum=0,sum=0,maxx=-inf;
    int l=1,r=1,b=1;
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&a[i]);
        sum+=a[i];
        Sum+=a[i];
        if(sum>maxx)
        {
            l=b;
            r=i;
            maxx=sum;
        }
        if(sum<0)
        {
            sum=0;
            b=i+1;
        }
    }
    sum=0,b=1;
    ll minn=inf;
    int L=1,R=1;
    for(int i=1;i<=n;i++)
    {
        sum+=a[i];
        if(sum<minn)
        {
            L=b;
            R=i;
            minn=sum;
        }
        if(sum>0)
        {
            sum=0;
            b=i+1;
        }
    }
    ll Maxx=Sum-minn;
    if(maxx>Maxx)printf("%lld %d %d\n",maxx,l,r);
    else
    {
        l=R+1>n?1:R+1;
        r=L-1<1?n:L-1;
        printf("%lld %d %d\n",Maxx,l,r);
    }
    return 0;
}
