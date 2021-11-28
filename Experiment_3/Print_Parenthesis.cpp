#include <bits/stdc++.h>
#define limit1 10
#define limit2 100
#define pb push_back

using namespace std;

typedef vector<int> VI;

void printParenthesis(int i, int j, int n, int* bracket,char& name){
	if (i == j) {
		cout<<name++;
		return;
	}

	cout<<"(";
	printParenthesis(i, *((bracket + i * n) + j), n,bracket, name);

	printParenthesis(*((bracket + i * n) + j) + 1, j, n,bracket, name);
	cout<<")";
}

void matrixChainOrder(VI vect){
	int m[vect.size()][vect.size()];
	int bracket[vect.size()][vect.size()];
	for (int i = 1; i < vect.size(); i++)
		m[i][i] = 0;

	for (int L = 2; L < vect.size(); L++){
		for (int i = 1; i < vect.size() - L + 1; i++){
			int j = i + L - 1;
			m[i][j] = INT_MAX;
			for (int k = i; k <= j - 1; k++){
				int q = m[i][k] + m[k + 1][j]+ vect[i - 1] * vect[k] * vect[j];
				if (q < m[i][j]){
					m[i][j] = q;
					bracket[i][j] = k;
				}
			}
		}
	}
	char name = 'A';

	cout<<"Optimal Parenthesization is : ";
	printParenthesis(1, vect.size() - 1, vect.size(), (int*)bracket, name);
	cout<<"\nOptimal Cost is : " << m[1][vect.size() - 1]<<endl;
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
	cout<<"For size of Matrices as follows:\n";
	print_vector(vect);
    matrixChainOrder(vect);
}

//This Code is made by Chander Jindal
