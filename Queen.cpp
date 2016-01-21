#include <bits/stdc++.h>

using namespace std;

int main(){
	int x,y,x1,y1;

	while(scanf("%d %d %d %d",&x,&y,&x1,&y1) && x){
		int u = y;
		int p = x;

		vector< vector<bool> > mat( 10 , vector<bool>(10) );
		if(x==x1 && y==y1){
			printf("0\n");
			continue;
		}

		while(y<=8 && x<=8){
			mat[x][y] = true;
			y++;
			x++;
		}

		y = u;
		x = p;
		while(y && x){
			mat[x][y] = true;
			y--;
			x--;
		}

		y = u;
		x = p;
		while(y<=8 && x){
			mat[x][y] = true;
			y++;
			x--;
		}

		y = u;
		x = p;
		while(y && x<=8){
			mat[x][y] = true;
			y--;
			x++;
		}

		y = u;
		x = p;
		while(x){
			mat[x][y] = true;
			x--;
		}

		y = u;
		x = p;
		while(x<=8){
			mat[x][y] = true;
			x++;
		}

		y = u;
		x = p;
		while(y){
			mat[x][y] = true;
			y--;
		}

		y = u;
		x = p;
		while(y<=8){
			mat[x][y] = true;
			y++;
		}

		if(mat[x1][y1]) printf("1\n");
		else printf("2\n");
	}
	return 0;
}
