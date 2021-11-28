#include <bits/stdc++.h>
using namespace std;
#define limit1 10
#define limit2 100
#define pb push_back

typedef vector<int> VI;
typedef vector<VI> VVI;

int dp[limit1][limit1];

int Matrix_Chain_Multiplication(VI vect, int i, int j){
	if (i == j)
		return 0;

	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = INT_MAX;
	for (int k = i; k < j; k++){
		dp[i][j] = min(dp[i][j],
             Matrix_Chain_Multiplication(vect, i, k)+ Matrix_Chain_Multiplication(vect, k + 1, j)+ vect[i - 1] * vect[k] * vect[j]);
	}
	return dp[i][j];
}

VI make_vector(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(rand()%limit2);
    return vect;
}

void print_vector(VI vect){
for(int i =0;i<vect.size();i++)
    cout<<vect[i]<<" ";
cout<<endl;
return;
}

int main(){
    srand(time(0));
    int n = rand()%limit1;
    VI vect = make_vector(n);
	memset(dp, -1, sizeof dp);
	cout<<"For size of Matrices as follows:\n";
	print_vector(vect);
	cout << "Minimum number of multiplications required is "<< Matrix_Chain_Multiplication(vect,1, n-1);
}

//This Code is made by Chander Jindal
