#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit 10000

typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

void heapify(VI vect, int n, int i){
	int largest = i; 
	int l = 2 * i + 1; 
	int r = 2 * i + 2; 

	if (l < n && vect[l] > vect[largest])
		largest = l;

	if (r < n && vect[r] > vect[largest])
		largest = r;

	if (largest != i) {
		swap(vect[i], vect[largest]);

		heapify(vect, n, largest);
	}
}

void heapSort(VI &vect, int n){
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(vect, n, i);

	for (int i = n - 1; i > 0; i--) {
		swap(vect[0], vect[i]);
		heapify(vect, i, 0);
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
    if(n<1000){
        n += 1000;
    }
    cout<<"For n = "<<n<<", in Heap Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    heapSort(vect,vect.size());
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    heapSort(vect,vect.size());
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    heapSort(vect,vect.size());
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

//This Code is made by Chander Jindal