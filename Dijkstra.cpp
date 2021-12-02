#include <bits/stdc++.h>
#define limit 100
using namespace std;

void DijkstrasTest();

int main() {
  DijkstrasTest();
  return 0;
}

class Node;
class Edge;

void Dijkstras();
vector<Node*>* AdjacentRemainingNodes(Node* node);
Node* ExtractSmallest(vector<Node*>& nodes);
int Distance(Node* node1, Node* node2);
bool Contains(vector<Node*>& nodes, Node* node);
void PrintShortestRouteTo(Node* destination);
void PrintGraph();
vector<Node*> nodes;
vector<Edge*> edges;

class Node {
   public:
  Node(char id)
    : id(id), previous(NULL), distanceFromStart(INT_MAX) {
    nodes.push_back(this);
  }

   public:
  char id;
  Node* previous;
  int distanceFromStart;
};

class Edge{
   public:
  Edge(Node* node1, Node* node2, int distance)
    : node1(node1), node2(node2), distance(distance){
    edges.push_back(this);
  }
  bool Connects(Node* node1, Node* node2) {
    return (
      (node1 == this->node1 &&
       node2 == this->node2) ||
      (node1 == this->node2 &&
       node2 == this->node1));
  }

   public:
  Node* node1;
  Node* node2;
  int distance;
};

///////////////////
void DijkstrasTest() {
  Node* a = new Node('A');
  Node* b = new Node('B');
  Node* c = new Node('C');
  Node* d = new Node('D');
  Node* e = new Node('E');
  Node* f = new Node('F');
  Node* g = new Node('G');

srand(time(0));

  Edge* e1 = new Edge(a, c, rand()%limit);
  Edge* e2 = new Edge(a, d, rand()%limit);
  Edge* e3 = new Edge(b, c, rand()%limit);
  Edge* e4 = new Edge(c, d, rand()%limit);
  Edge* e5 = new Edge(b, f, rand()%limit);
  Edge* e6 = new Edge(c, e, rand()%limit);
  Edge* e7 = new Edge(e, f, rand()%limit);
  Edge* e8 = new Edge(d, g, rand()%limit);
  Edge* e9 = new Edge(g, f, rand()%limit);

  PrintGraph();
  a->distanceFromStart = 0;  // set start node
  Dijkstras();
  PrintShortestRouteTo(f);
}

///////////////////

void PrintGraph(){
    const int size_ = edges.size();
    cout<<"The paths in the given graph are as following:\n";
    for(int i = 0 ; i < size_ ; i++){
        Edge* edge = edges[i];
        cout<<edge->node1->id<<" to "<<edge->node2->id<<" has distance of "<<edge->distance<<"\n";
    }
    cout<<"\n";
return;
}

void Dijkstras(){
  while (nodes.size() > 0) {
    Node* smallest = ExtractSmallest(nodes);
    vector<Node*>* adjacentNodes = AdjacentRemainingNodes(smallest);

    const int size = adjacentNodes->size();
    for (int i = 0; i < size; ++i) {
      Node* adjacent = adjacentNodes->at(i);
      int distance = Distance(smallest, adjacent) + smallest->distanceFromStart;

      if (distance < adjacent->distanceFromStart)
        adjacent->distanceFromStart = distance,adjacent->previous = smallest;
    }
    delete adjacentNodes;
  }
}

// Find the node with the smallest distance,
// remove it, and return it.
Node* ExtractSmallest(vector<Node*>& nodes){
  int size_ = nodes.size();
  if (size_ == 0) return NULL;
  int smallestPosition = 0;
  Node* smallest = nodes.at(0);
  for(int i = 1; i < size_; ++i){
    Node* current = nodes.at(i);
    if (current->distanceFromStart < smallest->distanceFromStart){
      smallest = current;
      smallestPosition = i;
    }
  }
  nodes.erase(nodes.begin() + smallestPosition);
  return smallest;
}

// Return all nodes adjacent to 'node' which are still in the 'nodes' collection.
vector<Node*>* AdjacentRemainingNodes(Node* node){
  vector<Node*>* adjacentNodes = new vector<Node*>();
  const int size_ = edges.size();
  for (int i = 0; i < size_; ++i){
    Edge* edge = edges.at(i);
    Node* adjacent = NULL;
    if (edge->node1 == node)
      adjacent = edge->node2;
    else if (edge->node2 == node)
      adjacent = edge->node1;
    if (adjacent && Contains(nodes, adjacent))
      adjacentNodes->push_back(adjacent);
  }
  return adjacentNodes;
}

// Return distance between two connected nodes
int Distance(Node* node1, Node* node2) {
  const int size = edges.size();
  for (int i = 0; i < size; ++i) {
    Edge* edge = edges.at(i);
    if (edge->Connects(node1, node2)) {
      return edge->distance;
    }
  }
  return -1;  // disconnected a.k.a. issue
}

// Does the 'nodes' vector contain 'node'
bool Contains(vector<Node*>& nodes, Node* node) {
  const int size = nodes.size();
  for (int i = 0; i < size; ++i) {
    if (node == nodes.at(i)) {
      return true;
    }
  }
  return false;
}

void PrintShortestRouteTo(Node* destination) {
  Node* previous = destination;
  cout << "Distance from start: "
     << destination->distanceFromStart << endl;
  while (previous) {
    cout << previous->id << " ";
    previous = previous->previous;
  }
  cout << endl;
}
