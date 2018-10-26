#include<bits/stdc++.h>
using namespace std;
ll a[100010];
int main()
{
    memset(a,0,sizeof(a));
    int n,k;
    ll l;
    cin>>n>>k>>l;
    for(int i=1;i<=n*k;i++)
    {
        scanf("%lld",&a[i]);
    }
    sort(a+1,a+n*k+1);
    priority_queue<ll> bushidi;
    priority_queue<ll> keyizuodi;
    keyizuodi.push(a[1]);
    for(int i=2;i<=n*k;i++)
    {
        if(a[i]<=a[1]+l)
        {
            keyizuodi.push(a[i]);
        }
        else
        {
            bushidi.push(a[i]);
        }
    }
    ll ans=0;
    int jl=0;
    while(!keyizuodi.empty())
    {
        if(bushidi.size()<(k-1))
        {
            int tmp=keyizuodi.top();keyizuodi.pop();
            bushidi.push(tmp);
            continue;
        }
        else
        {
            for(int i=1;i<=k-1;i++)
            {
                bushidi.pop();

            }
            jl++;
            ans+=keyizuodi.top();
                keyizuodi.pop();
        }
    }
    if(jl<n) return 0*puts("0");
    else {
        cout<<ans<<endl;
    }

    return 0;
}
