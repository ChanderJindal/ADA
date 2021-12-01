#include <bits/stdc++.h>
#define pb push_back
#define lli long long int
using namespace std;

typedef vector<int> VI;

lli minCostBST(VI key,VI freq, int n) {
   lli cost[n][n];
   memset(cost,0,sizeof(cost));
   for (int i = 0; i < n; i++)
      cost[i][i] = freq[i];

   for(int length=2; length<=n; length++){
      for(int i=0; i<=n-length+1; i++){
         int j = i+length-1;
         cost[i][j] = INT_MAX;
    for(int r=i; r<=j; r++){
    lli c = ((r > i)?cost[i][r-1]:0)+((r < j)?cost[r+1][j]:0)+accumulate(freq.begin()+i,freq.end()+j+1,0);
    if(c < cost[i][j])
        cost[i][j] = c;
    }
      }
   }

   return cost[0][n-1];
}

// A utility function to get sum of
// array elements freq[i] to freq[j]

VI make_vector(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(rand()%10);
    return vect;
}

void printer(VI vect){
for(auto it=vect.begin();it!=vect.end();it++)
    cout<<*it<<" ";
cout<<endl;
}

int main(){
    srand(time(0));
    int n = rand()%5;
    VI key = make_vector(n),freq = make_vector(n);
    cout<<"The Keys :\n";
    printer(key);
    cout<<"\nThe Frequency :\n";
    printer(freq);
	cout<<"\nThe resultant Cost of Optimal BST is "<<minCostBST(key, freq, n)<<endl;
	return 0;
}
//This Code is made by Chander Jindal

