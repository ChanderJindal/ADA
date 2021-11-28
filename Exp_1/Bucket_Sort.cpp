#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit1 10000
#define limit2 1000000

typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

void bucketSort(VI &vect){
  int max_val = *max_element(vect.begin(), vect.end());
  int bucket[max_val+1];
  memset(bucket,0,sizeof(bucket));
  for(int i = 0; i < vect.size(); i++)
    bucket[vect[i]]++;
  for(int i = 0, j = 0; i <= max_val; i++){
    while (bucket[i] > 0){
      vect[j++] = i;
      bucket[i]--;
    }
  }
  return;
}

VI rand_VI(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(rand()%limit2);
    return vect;
}

VI asc_VI(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(i);
    return vect;
}
VI dec_VI(int n){
    VI vect;
    vect.reserve(n);
    for(int i = n-1 ; i >= 0;i--)
        vect.pb(i);
    return vect;
}

int main(){
    srand(time(0));
    int n = rand()%limit2;
    if(n<100000){
        n += 100000;
    }
    cout<<"For n = "<<n<<", in Bucket Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    bucketSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    bucketSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    bucketSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

//This Code is made by Chander Jindal