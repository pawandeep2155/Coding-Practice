#include <iostream> 
#include <vector>
#include <queue>
using namespace std; 

// Number of vertices in the graph 
#define V 5 

int minKey(int key[], bool mstSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < V; v++) 
		if (mstSet[v] == false && key[v] < min) 
			min = key[v], min_index = v; 

	return min_index; 
} 

int primMST(int graph[V][V]) 
{ 
	int parent[V]; 
	int key[V]; 
	bool mstSet[V]; 

	for (int i = 0; i < V; i++) 
		key[i] = INT_MAX, mstSet[i] = false; 

	key[0] = 0; 
	parent[0] = -1; 

	for (int count = 0; count < V - 1; count++) { 
		int u = minKey(key, mstSet); 
		mstSet[u] = true; 
		for (int v = 0; v < V; v++) 
			if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
				parent[v] = u, key[v] = graph[u][v]; 
	} 
    int mst_cost = 0;
    for (int i = 1; i < V; i++) 
		mst_cost += graph[i][parent[i]];
    return mst_cost;
} 

int findKthLargest(int nums[], int n, int k) {
    priority_queue<int,vector<int>,greater<int> >pq;
    for(int i=0;i<k;i++){
        pq.push(nums[i]);
    }
    for(int i=k;i<n;i++){
        if(pq.top()<=nums[i]){
            pq.pop();
        pq.push(nums[i]);
        }
    }
    return pq.top();
}

int main() 
{ 
	int graph[V][V] = { { 0, 2, 0, 6, 0 }, 
						{ 2, 0, 3, 8, 5 }, 
						{ 0, 3, 0, 0, 7 }, 
						{ 6, 8, 0, 0, 9 }, 
						{ 0, 5, 7, 9, 0 } }; 

	int mst_cost = primMST(graph); 
    cout<<"Minimum spanning tree cost"<<mst_cost<<endl;

    int arr[] = {5, 4, 1, 3, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 1;
    int kth_largest = findKthLargest(arr, n, k);
    cout<<"Kth largest "<<kth_largest<<endl;

	return 0; 
} 