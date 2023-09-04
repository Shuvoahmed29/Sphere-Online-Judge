#include<bits/stdc++.h>
using namespace std;
void code(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif 
}
// #define int long long
const int M = 1e7+7;
int binaryExp(int a,int b){
	int ans = 1;
	while(b){
		if(b&1){
			ans = (ans *1LL* a)%M;
		}
		a = (a*1LL*a)%M;
		b = b>>1;
	}
	return ans%M;
}
int32_t main(){
	code();
	int n,k;
	while(1){
		cin >> n >> k;
		if(n==0 && k==0) break;
		int x = (binaryExp(n,k)+2*binaryExp(n-1,k));
		int y = (binaryExp(n,n)+2*binaryExp(n-1,n-1));
		int z = (x+y)%M;
		cout << z << endl;
	}
}
