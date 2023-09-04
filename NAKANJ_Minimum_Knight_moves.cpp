#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
const int INF = 1e9+9;
const int N = 1e5+9;
bool visited[8][8];
int level[8][8];
int getX(string str){
	return str[0]-'a';
}
int getY(string str){
	return str[1]-'1';
}
vector<pair<int,int>>moves={
	{2,1},{2,-1},
	{-2,1},{-2,-1},
	{1,2},{-1,2},
	{-1,-2},{1,-2}
};
bool isValid(int x,int y){
	if(x>=0 && y>=0 && x<8 && y<8){
		return true;
	}
	else return false;
}
int bfs(string src,string dist){
	int srcX = getX(src);
	int srcY = getY(src);
	int distX = getX(dist);
	int distY = getY(dist);
	queue<pair<int,int>> Q;
	Q.push({srcX,srcY});
	visited[srcX][srcY] = true;
	level[srcX][srcY]=0;
	while(!Q.empty()){
		pair<int,int> p = Q.front();
		Q.pop();
		int x = p.first;
		int y = p.second;
		for(auto it:moves){
			int childX = x+it.first;
			int childY = y+it.second;
			if(isValid(childX,childY)==false) continue;
			Q.push({childX,childY});
			visited[childX][childY] = true;
			level[childX][childY] = level[x][y]+1;
		}
		if(level[distX][distY]!=INF){
			break;
		}
	}
	return level[distX][distY];
}
void reset(){
	for(int i=0;i<8;i++){
		for(int j=0;j<8;j++){
			visited[i][j] = false;
			level[i][j] = INF;
		}
	}
}
int main(){
	code();
	int tt;	cin >> tt;
	while(tt--){
		reset();
		string str1,str2;	cin >> str1 >> str2;
		cout << bfs(str1,str2) << endl;
	}
}
