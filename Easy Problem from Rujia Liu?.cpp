#include <bits/stdc++.h>
#define lli long long int
#define pii pair<int,int>

using namespace std;

const int INF = 1e8;
const int MAXN = 1000005;

int main(){
	int n,q,a,b;
	while(scanf("%d %d",&n,&q)!=EOF){

		vector< vector<int> > num( MAXN , vector<int>() );

		for(int i=0;i<n;i++){
			scanf("%d",&a);
			num[a].push_back(i);
		}

		while(q--){
			scanf("%d %d",&b,&a);
			b--;
			if(b>=num[a].size()) printf("0\n");
			else printf("%d\n",num[a][b]+1);
		}

	}
	return 0;
}
