#include <bits/stdc++.h>

using namespace std;

const int MAXN = 30;

char cad[1005];
vector<string> res;

struct Trie{

	int id;
	Trie *hijos[MAXN];

	Trie(){
		id = 0;
		for(int i=0;i<MAXN;i++)
			hijos[i] = '\0';
	}

	void Inserta(char s,int nivel,int aux,int p){

		if(aux==nivel) return;

		if(hijos[s - 'a']=='\0'){
			hijos[s - 'a'] = new Trie();
			hijos[s - 'a']->id = p;
		}

		for(int i=0;i<MAXN;i++)
			if(hijos[i]!='\0' && (hijos[i]->id)<p)
				hijos[i]->Inserta( s , nivel , aux + 1 , p );
	}

	void Genera(string aux){

		if(aux.size()) res.push_back(aux);

		aux += "a";
		for(int i=0;i<MAXN;i++)
			if(hijos[i]!='\0'){
				aux[ aux.size() - 1 ] = i + 'a';
				hijos[i]->Genera( aux );
			}
	}

};

int main(){

	while(scanf("\n%s",cad)!=EOF){
		int len = strlen(cad);

		Trie *grafo = new Trie();
		res.clear();

		for(int j=0;j<len;j++)
			grafo->Inserta( cad[j] , len , 0 , j );

		grafo->Genera("");

		for(int i=0;i<res.size();i++)
			printf("%s\n",res[i].c_str());
		printf("\n");

		for(int i=0;cad[i];i++) cad[i] = '\0';
	}
	return 0;
}
