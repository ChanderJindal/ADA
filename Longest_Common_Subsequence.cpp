#include <bits/stdc++.h>
#define limit 50

using namespace std;

int lcs_Naive(string x, string y, int m, int n){
	if (m == 0 || n == 0)
		return 0;
	if (x[m - 1] == y[n - 1])
		return 1 + lcs_Naive(x, y, m - 1, n - 1);
	else
		return max(lcs_Naive(x, y, m, n - 1), lcs_Naive(x, y, m - 1, n));
}

int lcs_DP(string x, string y, int m, int n){
    int L[m + 1][n + 1];
    memset(L,0,sizeof(L));
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;

            else if (x[i - 1] == y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;

            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }
return L[m][n];
}

string rand_str(int n){
	string str = "";
	while (n-->0){
            char ch = 'A' + rand()%26;
		str = str + ch;
	}
return str;
}

int main(){
	srand(time(0));
	int n = rand()%limit, m = rand()%limit;
	string s1 = rand_str(n), s2 = rand_str(m);
	cout<<"Finding Longest Common Subsequence of Strings"<<endl;
	cout<<"String One:\nString - "<<s1<<"\nLength - "<<n<<endl;
	cout<<"String Two:\nString - "<<s2<<"\nLength - "<<m<<endl;
	cout<<"Naive method\nTime Taken = ";
	clock_t time_taken = clock();
	int length = lcs_Naive(s1,s2,n,m);
	time_taken = clock() - time_taken;
	cout<<(float)time_taken/CLOCKS_PER_SEC<<"\nLength of longest common subsequence = "<<length<<endl;
	cout<<"Dynamic Programming method\nTime Taken = ";
	time_taken = clock();
	length = lcs_DP(s1,s2,n,m);
	time_taken = clock() - time_taken;
	cout<<(float)time_taken/CLOCKS_PER_SEC<<"\nLength of longest common subsequence = "<<length<<endl;
	return 0;
}
