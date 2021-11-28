#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit 10000
typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

int partition_ (VI &vect, int low, int high){
	int pivot = vect[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++){
		if (vect[j] < pivot){
			i++;
			swap(vect[i], vect[j]);
		}
	}
	swap(vect[i + 1], vect[high]);
	return (i + 1);
}

void quickSort(VI &vect, int low, int high){
	if (low < high){
		int pi = partition_(vect, low, high);
		quickSort(vect, low, pi - 1);
		quickSort(vect, pi + 1, high);
	}
    return;
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
    cout<<"For n = "<<n<<", in Quick Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    quickSort(vect,0,n-1);
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    quickSort(vect,0,n-1);
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    quickSort(vect,0,n-1);
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

