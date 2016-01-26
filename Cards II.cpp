#include <bits/stdc++.h>
#define lli long long int

using namespace std;

const int MAXN = 10005;

lli num[MAXN];
lli dp[3][MAXN];

int main(){
	int n;
	lli a;

	while(scanf("%d",&n)!=EOF){

		for(int i=0;i<n;i++)
			scanf("%lld",&num[i]);

		for(int i=n-1;i>=0;i--)
			for(int j=i;j<n;j++){
				if(i==j){
					dp[i&1][j] = 0;
					continue;
				}

				if( ( j - i + 1 )&1 )
					dp[i&1][j] = max( dp[( i + 1 )&1][j] , dp[i&1][j-1] );
				else
					dp[i&1][j] = max( dp[( i + 1 )&1][j] + num[i] , dp[i&1][j-1] + num[j] );
			}

		printf("%lld\n",dp[0][n-1]);
	}
	return 0;
}
