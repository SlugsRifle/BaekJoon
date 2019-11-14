#include <bits/stdc++.h>

#define lli long long int

using namespace std;

lli F(lli N, lli S, lli E) {
	lli sum = 0, i;
	for (i = S ; i <= E ; i++) {
		sum = sum + N / i;
	}
	return sum;
}

int main() {
	lli N, S, E;
	int Q, i;
	scanf("%d", &Q);
	for (i = 1 ; i <= Q ; i++) {
		scanf("%lld %lld %lld", &N, &S, &E);
		printf("%lld\n", F(N, S, E));
	}
	return 0;
}

