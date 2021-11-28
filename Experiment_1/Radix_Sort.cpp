#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit 100000000 // 1e8

typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

VI countSort(VI vect2, int exp){
    VI vect;
    vect.reserve(vect2.size());
	int count[10];
    memset(count,0,sizeof(count));

	for (int i = 0; i < vect2.size(); i++)
		count[(vect2[i] / exp) % 10]++;

	for (int i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (int i = vect2.size() - 1; i >= 0; i--) {
		vect[count[(vect2[i] / exp) % 10] - 1] = vect2[i];
		count[(vect2[i] / exp) % 10]--;
	}
    return vect;

}

void radixsort(VI &vect){
	int m = *max_element(vect.begin(),vect.end());

	for (int exp = 1; m / exp > 0; exp *= 10)
		vect = countSort(vect, exp);
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
    cout<<"For n = "<<n<<", in Radix Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    radixsort(vect);
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    radixsort(vect);
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    radixsort(vect);
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

//This Code is made by Chander Jindal