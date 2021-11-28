#include <bits/stdc++.h>

using namespace std;
#define pb push_back
#define limit1 10000000
#define limit2 100000000


typedef vector<int> VI;


int Linear_search(VI vect, int item){
    for(int i = 0; i < vect.size(); i++)
        if (vect[i] == item)
            return i;
    return -1;
}

int Binary_search(VI vect, int l, int r, int item){
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (vect[mid] == item)
            return mid;
        if (vect[mid] > item)
            return Binary_search(vect, l, mid - 1, item);
        return Binary_search(vect, mid + 1, r, item);
    }
}

VI make_vector(int n){
    VI vect;
    vect.reserve(n);
    for(int i = 0 ; i < n;i++)
        vect.pb(rand()%limit2);
    return vect;
}


int main(){
    srand(time(0));
    int n = rand()%limit2;
    if(n<limit1)
        n += limit1;

    VI vect = make_vector(n);

    cout<<"For n = "<<n<<", for Linear Search, time taken:"<<endl;
    clock_t time_taken = clock();
    Linear_search(vect,vect[0]);
    time_taken = clock() - time_taken;
    cout<<"For First element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Linear_search(vect,vect[n/2]);
    time_taken = clock() - time_taken;
    cout<<"For Middle element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Linear_search(vect,vect[n-1]);
    time_taken = clock() - time_taken;
    cout<<"For Last element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Linear_search(vect,limit2);
    time_taken = clock() - time_taken;
    cout<<"For Non-existing element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;

    cout<<"\n\n"<<endl;

    cout<<"For n = "<<n<<", for Binary Search, time taken:"<<endl;
    time_taken = clock();
    Binary_search(vect,0,n-1,vect[0]);
    time_taken = clock() - time_taken;
    cout<<"For First element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Binary_search(vect,0,n-1,vect[n/2]);
    time_taken = clock() - time_taken;
    cout<<"For Middle element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Binary_search(vect,0,n-1,vect[n-1]);
    time_taken = clock() - time_taken;
    cout<<"For Last element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;
    time_taken = clock();
    Binary_search(vect,0,n-1,limit2);
    time_taken = clock() - time_taken;
    cout<<"For Non-existing element in array : "<<(float)time_taken/CLOCKS_PER_SEC<<endl;

	return 0;
}

//This Code is made by Chander Jindal
