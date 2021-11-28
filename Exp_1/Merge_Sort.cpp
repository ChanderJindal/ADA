#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define limit 100000
typedef vector<int> VI;

void printer(VI vect){
	for (int i = 0; i < vect.size(); i++)
		cout << vect[i] << " ";
}

VI mergeSort(VI &vect){
    if(vect.size() < 2)
    return vect;
    int mid = vect.size()/2;
    VI R_vect , L_vect;
    for(int i =0;i<mid;i++)
        L_vect.pb(vect[i]);

    for(int i =mid;i<vect.size();i++)
        R_vect.pb(vect[i]);
    L_vect = mergeSort(L_vect);
    R_vect = mergeSort(R_vect);
    int l = 0,r = 0,m = 0;
    while (l < L_vect.size() && r < R_vect.size()){
        if(L_vect[l] < R_vect[r]){
            vect[m] = L_vect[l];
            ++l;
        }else{
            vect[m] = R_vect[r];
            ++r;
        }
        ++m;
    }
    while (l < L_vect.size()){
        vect[m] = L_vect[l];
        ++l;
        ++m;
    }
    while (r < R_vect.size()){
        vect[m] = R_vect[r];
        ++r;
        ++m;
    }
return vect;
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
    if(n<10000){
        n += 10000;
    }
    cout<<"For n = "<<n<<", in Merge Sort the time for the following arrays is:"<<endl;
    VI vect = rand_VI(n);
    clock_t time_taken = clock();
    mergeSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For Random array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = asc_VI(n);
    time_taken = clock();
    mergeSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For ascending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    vect = dec_VI(n);
    time_taken = clock();
    mergeSort(vect);
    time_taken = clock() - time_taken;
    cout<<"For descending sorted array sorting : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
	return 0;
}

