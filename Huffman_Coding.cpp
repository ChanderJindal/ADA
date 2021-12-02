// C++(STL) program for Huffman Coding with STL
#include <bits/stdc++.h>
#define pb push_back
#define limit1 26
#define limit2 1000

using namespace std;

typedef vector<int> VI;
typedef vector<char> VC;

// huffman nodes
struct min_heap_node {

	char data; // key / value
	unsigned freq; // frequency
	min_heap_node *left, *right; //children

	min_heap_node(char data, unsigned freq){ //constructor type
		left = right = NULL;
		this->data = data;
		this->freq = freq;
	}
};

struct compare{  // compare function to be used for minheap nodes only
	bool operator()(min_heap_node* l, min_heap_node* r){
		return (l->freq > r->freq);
	}
};

void print_huffman_code(struct min_heap_node* root, string str);
void Huffman_Code(VC data, VI freq, int size);

VI make_vector_int(int n);
VC make_vector_char(int n);
void print_VI(VI vect);
void print_VC(VC vect);

int main(){

    srand(time(0));
    int n = rand()%limit1;

    VC vect_val = make_vector_char(n);
    VI vect_freq = make_vector_int(n);
    cout<<"For an array of values:\n";
    print_VC(vect_val);
    cout<<"And their frequencies:\n";
    print_VI(vect_freq);
    cout<<"\nTheir Huffman code is:\n";

	Huffman_Code(vect_val, vect_freq, n);

	return 0;
}

VI make_vector_int(int n){
    VI vect,temp;
    vect.reserve(n),temp.reserve(n);
    for(int i = 0 ; i< limit2;i++)
    temp.pb(i);
    for(int i = 0 ; i < n;i++){
            int idx = rand()%temp.size();
        vect.pb( temp[idx] );
    temp.erase(temp.begin()+idx);
    }
    return vect;
}
VC make_vector_char(int n){
    VC vect;
    VI temp;
    temp.reserve(n);
    vect.reserve(n);
    for(int i = 0 ; i< limit1;i++)
        temp.pb('A'+i);
    for(int i = 0 ; i < n;i++){
            int idx = rand()%temp.size();
        vect.pb( temp[idx] );
    temp.erase(temp.begin()+idx);
    }
    return vect;
}
void print_VI(VI vect){
    for(auto it = vect.begin();it != vect.end();it++)
    cout<<*it<<" ";
    cout<<endl;
    return;
}
void print_VC(VC vect){
    for(auto it = vect.begin();it != vect.end();it++)
    cout<<*it<<" ";
    cout<<endl;
    return;
}
void print_huffman_code(struct min_heap_node* root, string str){
	if (!root)
		return;

	if (root->data != '#')
		cout<<root->data<<": "<<str<<endl;

	print_huffman_code(root->left, str + "0");
	print_huffman_code(root->right, str + "1");
}
void Huffman_Code(VC data, VI freq, int size){
	struct min_heap_node *left, *right, *top;

	priority_queue<min_heap_node*, vector<min_heap_node*>, compare> minHeap;
    //priority_queue type min_heap_node pointer, behaves like mine_heap_node pointer vector, with special comparator

	for (int i = 0; i < size; ++i)
		minHeap.push(new min_heap_node(data[i], freq[i]));

	while (minHeap.size() != 1){
		left = minHeap.top();
		minHeap.pop();

		right = minHeap.top();
		minHeap.pop();

        // took left and right element 
        // left is 2n + 0 , right is 2n + 1
		top = new min_heap_node('#', left->freq + right->freq);
        // mix of left and right, using '#' as empty key 
		top->left = left;
		top->right = right;

		minHeap.push(top);
	}

	// Print Huffman codes using
	// the Huffman tree built above
	print_huffman_code(minHeap.top(), "");
}

//This Code is made by Chander Jindal
