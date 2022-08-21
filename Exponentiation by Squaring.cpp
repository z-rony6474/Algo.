#include<bits/stdc++.h>
#define nl cout<<endl;
using namespace std;
typedef long long ll;
ll Max=INT_MIN,Min=INT_MAX,mod=1000000007;

ll B_EX(ll a,ll b) 
{
	if(b==0) return 1;
	if(b==1) return a;
	if(b%2==0)
	{
	ll tmp= B_EX(a,b/2);
	return (tmp*tmp)%mod;	
	}
	if(b%2) return (a*B_EX(a,b-1))%mod;
}
int main()
{
	ll a,b;
	cin >> a >> b;
	cout<<B_EX(a,b);
	return 0;
}
