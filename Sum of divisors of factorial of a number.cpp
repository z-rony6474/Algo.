// C++ program to find sum of divisors in n!
#include<bits/stdc++.h>
#include<math.h>
using namespace std;

// allPrimes[] stores all prime numbers less than or equal to n.
vector<int> allPrimes;
// Fills above vector allPrimes[] for a given n
void sieve(int n)
{
	
	vector<bool> prime(n+1, true);

	for (int p = 2; p*p <= n; p++)
	{
		if (prime[p] == true)
		{
			for (int i = p*2; i <= n; i += p)
			prime[i] = false;
		}
	}
	for (int p = 2; p <= n; p++)
		if (prime[p])
			allPrimes.push_back(p);
}

// Function to find all result of factorial number
int factorialDivisors(int n)
{
	sieve(n);
	
	int result = 1;

	// find exponents of all primes which divides n
	// and less than n
	for (int i = 0; i < allPrimes.size(); i++)
	{
		// Current divisor
		int p = allPrimes[i];

		// Find the highest power (stored in exp)'
		// of allPrimes[i] that divides n using
		// Legendre's formula.
		int exp = 0;
		while (p <= n)
		{
			exp = exp + (n/p);
			p = p*allPrimes[i];
		}

		// Using the divisor function to calculate
		// the sum
		result = result*(pow(allPrimes[i], exp+1)-1)/
									(allPrimes[i]-1);
	}

	// return total divisors
	return result;
}
int main()
{
	cout << factorialDivisors(4);
	return 0;
}
