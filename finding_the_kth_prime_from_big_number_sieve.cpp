#include <bits/stdc++.h>
using namespace std;
void sieve();
vector<int> vec;
// int arr[90000001];
bool arr[90000001];
int main()
{
    int t, n;
    cin >> t;
    sieve();
    while (t--)
    {
        cin >> n;
        cout << vec[n - 1] << endl;
    }
}
void sieve()
{
    int mx = 90000000;
    // for(int i=0;i<=mx;i++)arr[i]=1;
    arr[0] = arr[1] = true;

    for (int i = 2; i * i <= mx; i++)
    {
        if (arr[i] == false)
        {
            for (int j = i * i; j <= mx; j = j + i)
                arr[j] = true;
        }
    }
    for (int i = 2; i <= mx; i++)
    {
        if (arr[i] == false)
            vec.push_back(i);
    }
}