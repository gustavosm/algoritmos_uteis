#include <bits/stdc++.h>


using namespace std;
typedef long long int lli;
typedef pair<lli, lli> ii;

//calcula em O(logn) o n-esimo numero de fibonacci % mod
ii fast_doubling(lli n, lli mod) 
{
	if(n == 1) return ii(1, 1);
	else if(n == 2) return ii(1, 2);
	
	ii aux = fast_doubling(n/2, mod);
	ii ret;
	
	ret.first = (aux.first * (aux.second * 2 + mod - aux.first)) % mod;
	ret.second = ((lli)pow(aux.first, 2) + (lli)pow(aux.second, 2)) % mod;
	 
	return (!(n & 1)? ret : ii(ret.second, (ret.first+ret.second)%mod));
}

int main()
{
	cout << fast_doubling(50, 100000007).first << '\n';
}
