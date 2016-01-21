#include <bits/stdc++.h>
#define lli long long int
#define pii pair<int,int>

using namespace std;

const int INF = 1e8;
const int MAXN = 100005;

int main(){
	int n;
	scanf("%d",&n);

	int id=-1,a;
	double maxi = -1.0 , b;

	for(int i=0;i<n;i++){
		scanf("%d %lf",&a,&b);
		if(b>maxi){
			maxi = b;
			id = a;
		}
	}

	if(maxi>=8.0000000) printf("%d\n",id);
	else printf("Minimum note not reached\n");
	return 0;
}
