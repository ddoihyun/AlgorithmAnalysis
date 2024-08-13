#include <iostream>

using namespace std;

int BinomialCoefficient_Recurrsive(int n, int k){
  if ( (n < 0) || (k < 0) || (k > n) ) return -1;
  else{
    // case 1: C(n,0) = 1
    if(k == 0) return 1;
    // case 2: C(n,n) = 1
    else if(k == n) return 1;
    // case 3: C(0,k) = 0
    else if(n == 0 && k != 0) return 0;
    // C(n,k) = C(n-1, k-1) + C(n-1, k)
    else 
    return BinomialCoefficient_Recurrsive(n-1, k-1) + BinomialCoefficient_Recurrsive(n-1, k);}}

int BinomialCoefficient_DP(int n, int k) {
    if (n < 0 || k < 0 || k > n) return -1;

    int dp[n + 1][k + 1];

    for (int i = 0; i <= n; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= k; ++i)
        dp[i][i] = 1;

    for (int i = 2; i <= n; ++i) {
        for (int j = 1; j < i && j <= k; ++j) 
            dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];}

    return dp[n][k];}

int main(void){
  int n, k;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter k: ";
  cin >> k;

  int ret1 = BinomialCoefficient_Recurrsive(n, k);
  if(ret1 == -1) printf("Wrong input. Try again!\n");
  printf("Binomial Coefficient(Recurrsive) for n=%d, k=%d: %d\n", n, k, ret1);
  int ret2 = BinomialCoefficient_DP(n, k);
  printf("Binomial Coefficient(Dynamic Program) for n=%d, k=%d: %d\n", n, k, ret2);
  return 0;}