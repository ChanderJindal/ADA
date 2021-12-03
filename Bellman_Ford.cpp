#include <bits/stdc++.h>
#define pb push_back
#define limit1 10
#define limit2 20
using namespace std;

typedef vector<int> VI;
typedef pair<int,int> PII;

struct path{
int starting_point, ending_point, distance;
};

struct path* pathway(PII route , int gap);

struct _map_{
int total_points, total_pathways;
vector<struct path> pathways;
};

void print_path(struct path mypath);
struct _map_* make_map(int mypoints,int mypaths,vector<struct path> mypathways);
void print_graph(struct _map_ mymap);
bool flip();
int weight();
PII checker(PII A);
void route_distance(int arr[],int n, int starting_point);
void Bellman_Ford(struct _map_ mymap, int start=0);
void tester();

int main(){
tester();
return 0;
}

void tester(){
srand(time(0));
int total_points = rand()%limit1;
if(total_points < 5)
    total_points = 5;
int total_paths = (6*total_points)/5 ;
//cout<<total_points<<" "<<total_paths<<endl;
VI vect;
vect.reserve(total_points);
for(int i=0;i<total_points;i++)
    vect.pb(i);
set<PII> st;
PII temp;
int i = 0;
while(st.size() != total_paths){
    i = i%total_points;
    temp.first = i;
    vect.erase(vect.begin()+i);
    temp.second = vect[ rand()%vect.size() ];
    //cout<<temp.first<<" "<<temp.second<<endl;
    vect.insert(vect.begin()+i,i);
    st.insert(checker(temp));
    i +=1;
}
vector<struct path> mypaths;
for(const PII &route : st)
    mypaths.pb( *pathway(route,weight()) );
struct _map_* mymap = make_map(total_points,total_paths,mypaths);
print_graph(*mymap);
Bellman_Ford(*mymap,0);
return;
}

void Bellman_Ford(struct _map_ mymap, int start){
	int points = mymap.total_points;
	int pathways = mymap.total_pathways;
	//for(int i = 0 ; i<pathways;i++)
     //   cout<<mymap.pathways[i].starting_point<<" "<<mymap.pathways[i].ending_point<<" "<<mymap.pathways[i].distance<<endl;
	//cout<<"#######################"<<endl;
	int distance[points];
	memset(distance,INT_MAX,sizeof(distance));
	distance[start] = 0;
	for(int i = 1; i < points ; i++){
		for(int j = 0; j < pathways; j++){
 			int u = mymap.pathways[j].starting_point;
			int v = mymap.pathways[j].ending_point;
			int w = mymap.pathways[j].distance;
			//cout<<"U -> "<<u<<" "<<dist[u]<<"  V-> "<<v<<" "<<dist[v]<<" wt-> "<<weight<<endl;
			distance[v] = min(distance[v],distance[u]+w);
		}
	}
	for (int i = 0; i < pathways; i++) {
		int u = mymap.pathways[i].starting_point;
		int v = mymap.pathways[i].ending_point;
		int w = mymap.pathways[i].distance;
		if (distance[u] != INT_MAX &&distance[u] + w < distance[v]) {
			cout<<"This Map contains negative weight cycle!\n";
			return;
		}
	}

	route_distance(distance,points, start);
	return;
}

void route_distance(int arr[],int n, int starting_point){
cout<<"#####################"<<endl;
cout<<"Distance of Points from starting Point "<<starting_point<<" is:\n";
for(int i =0;i<n;i++){
    cout<<starting_point<<" <---> "<<i<<" has gap of "<<arr[i]<<endl;
}
cout<<"#####################"<<endl;
return;
}

PII checker(PII A){
if(A.first>A.second)
    swap(A.first,A.second);
return A;
}
int weight(){
if(flip())
    return rand()%limit2;
return -(rand()%limit2);
}
bool flip(){
return rand()%2;
}

void print_graph(struct _map_ mymap){
cout<<"The current Map has: \n";
cout<<"______________________"<<endl;
cout<<"Vertices = "<<mymap.total_points<<endl;
cout<<"Edges = "<<mymap.total_pathways<<endl;
cout<<"The Edges are:\n";
cout<<"**********************"<<endl;
for(int i =0;i<mymap.pathways.size();i++){
    print_path(mymap.pathways[i]);
    cout<<"______________________"<<endl;
}
cout<<"**********************"<<endl;
return;
}
struct _map_* make_map(int mypoints,int mypaths,vector<struct path> mypathways){
struct _map_* mymap = new _map_;
mymap->total_points = mypoints;
mymap->total_pathways = mypaths;
mymap->pathways = mypathways;
return mymap;
}


struct path* pathway(PII route , int gap){
struct path* mypath = new path;
mypath->starting_point = route.first;
mypath->ending_point = route.second;
mypath->distance = gap;
return mypath;
}

void print_path(struct path mypath){
cout<<"Starting Point = "<<mypath.starting_point<<endl;
cout<<"Ending Point = "<<mypath.ending_point<<endl;
cout<<"Total Distance = "<<mypath.distance<<endl;
return;
}
