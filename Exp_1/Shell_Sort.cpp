#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit 100000000 // 1e8

typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

void shellSort(VI &vect) {
  for (int interval = vect.size() / 2; interval > 0; interval /= 2) {
    for (int i = interval; i < vect.size(); i += 1) {
      int temp = vect[i];
      int j;
      for (j = i; j >= interval && vect[j - interval] > temp; j -= interval) {
        vect[j] = vect[j - interval];
      }
      vect[j] = temp;
    }
  }
}

VI rand_VI(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(rand()%limit);
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
    int n = rand()%limit;
    if(n<10000000){ // 1e7
        n += 10000000;
    }
    cout<<"For n = "<<n<<", in Shell Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    shellSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    shellSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    shellSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

//This Code is made by Chander Jindal