#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	while(scanf("%d",&n) && n){
		int a = 1;
		int b = n;

		vector<int> num;
		while(a<b){
			num.push_back(b);
			num.push_back(a);
			a++;
			b--;
		}

		if(n&1) num.push_back(a);

		int pos = 0;

		unordered_map<int,int> s;

		for(int i=0;i<n;i++)
			s[i] = 1;

		for(int i=0;i<n;i++)
			s[ ( ( i + 1 ) - num[i] + n ) % n ] = 0;

		for(int i=0;i<n;i++)
			if(s[i]){
				pos = i;
				break;
			}

		for(int i=0;i<n;i++,pos++){
			if(i) printf(" ");
			printf("%d",num[ pos % n ]);
		}
		printf("\n");
	}
	return 0;
}
