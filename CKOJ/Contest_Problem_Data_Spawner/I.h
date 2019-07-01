#include<bits/stdc++.h>
#define ll long long
#define N 100100
#define PI acos(-1.0)
#define mod 1000000007
#define inf 0x3f3f3f3f
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MAX_LONG_LONG 9223372036854775807
#define MIN_LONG_LONG -9223372036854775808
using namespace std;
int T,n;
ll ans,dp[N][5];//dp[i][j]第i回合，j动作时一共有多少种打法
//设 0为正手推球，1为下旋球 ，2为上旋球，3为正手攻球，4为拉弧圈
int main()
{
	memset(dp,0,sizeof(dp));
    dp[1][0]=1;
    dp[1][1]=1;
    dp[1][2]=1;
    dp[1][3]=1;
    dp[1][4]=1;
    for(int i=2; i<=100000; i++)
        for(int j=0; j<5; j++)
           for(int h=0; h<5; h++)
           {
               if(h==1&&j==2)continue;
               if(h==4&&j==3)continue;
               dp[i][j]=(dp[i][j]+dp[i-1][h])%mod;
           }
	scanf("%d",&T);
    while(T--)
    {
    	scanf("%d",&n);
        ans=0;
        for(int i=0; i<5; i++)
            ans+=dp[n][i];
        ans%=mod;
        printf("%lld\n",ans);
    }
    return 0;
}
/*
int k[N];
ll ans;
int n;
void dfs(int step)
{
    if(step==n)
    {
        ans++;
        ans%=mod;
        return;
    }
    for(int i=0; i<5; i++)
    {
        if(step&&k[step-1]==1&&i==2)continue;
        if(step&&k[step-1]==4&&i==3)continue;
        k[step]=i;
        dfs(step+1);
    }
}
int main()
{
    while(~scanf("%d",&n))
    {
        ll x=5;
        ans=0;
        for(int i=1; i<n; i++)
            x=x*5%mod;
        dfs(0);
        printf("%lld %lld\n",x,ans);
    }
    return 0;
}*/
/*
2
23
3
105
4
479
5
2185
6
9967
7
45465
8
207391
9
946025
10
4315343
11
19684665
*/

