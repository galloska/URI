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
	int mini = INF;

	for(int i=0;i<n;i++){
		scanf("%d",&a);
		if(a<mini){
			mini = a;
			id = i;
		}
	}

	printf("%d\n",id+1);
	return 0;
}
