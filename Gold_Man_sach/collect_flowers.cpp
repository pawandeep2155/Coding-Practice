    // OPTIMAL SOLUTION
    
    #include <iostream>
	#include <queue>
	#include <vector>
	#include <map>
     
    using namespace std;
     
    const int MaxN = (int)2e3 + 10;
    const int MOD = (int)1e9 + 7;
    const int INF = 1e9;
     
    int m, n;
    int a[MaxN][MaxN], ptr;
    int visited[MaxN][MaxN];
    int sizes[MaxN * MaxN];
    int who[MaxN * MaxN], sz[MaxN * MaxN];
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
     
    int getWho(int v) {
    	return v == who[v] ? v : who[v] = getWho(who[v]);
    }
     
    int main() {
    //	freopen("input.txt", "r", stdin);
    //	ios::sync_with_stdio(false); cin.tie(NULL);
    	scanf("%d%d", &n, &m);
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			scanf("%d", &a[i][j]);
    		}
    	}
    	for (int i = 1; i <= n; ++i) {
    		for (int j = 1; j <= m; ++j) {
    			if (visited[i][j] != 0) {
    				continue;
    			}
    			queue < pair < int, int > > q;
    			q.push(make_pair(i, j));
    			visited[i][j] = ++ptr;
    			int qt = 1;
    			while (!q.empty()) {
    				int x = q.front().first, y = q.front().second;
    				q.pop();
    				for (int k = 0; k < 4; ++k) {
    					int nx = x + dx[k], ny = y + dy[k];
    					if (!visited[nx][ny] && a[nx][ny] == a[x][y]) {
    						visited[nx][ny] = ptr;
    						q.push(make_pair(nx, ny));
    						qt++;
    					}
    				}
    			}
    			sizes[ptr] = qt;
    		}
    	}
    	map < pair < int, int >, vector < pair < int, int > > > ed;
    	int ans = 0;
    	for (int i = 1; i <= ptr; ++i) {
    		who[i] = i;
    		sz[i] = sizes[i];
    		ans = max(ans, sz[i]);
    	}
    	for (int x = 1; x <= n; ++x) {
    		for (int y = 1; y <= m; ++y) {
    			for (int k = 0; k < 4; ++k) {
    				int nx = x + dx[k], ny = y + dy[k];
    				if (a[nx][ny] <= a[x][y]) {
    					continue;
    				}
    				ed[make_pair(a[x][y], a[nx][ny])].push_back(make_pair(visited[x][y], visited[nx][ny]));
    			}
    		}
    	}
    	for (auto &vec : ed) {
    		vector < int > changed;
    		for (auto &it : vec.second) {
    			int x = it.first, y = it.second;
    			changed.push_back(x);
    			changed.push_back(y);
    			int xx = getWho(x), yy = getWho(y);
    			if (xx == yy) {
    				continue;
    			}
    			if (rand() & 1) {
    				swap(xx, yy);
    			}
    			who[xx] = yy;
    			sz[yy] += sz[xx];
    			ans = max(ans, sz[yy]);
    		}
    		for (auto &it : changed) {
    			sz[it] = sizes[it];
    			who[it] = it;
    		}
    	}
    	printf("%d\n", ans);
    	return 0;
    }
     


// MY BRUTE FORCE WORKING SOLUTION
// #include <iostream>
// #include <string>
// #include <vector>
// #include <limits.h>
// #include <queue>
// #include <math.h>
// #include <algorithm>

// using namespace std;

// struct Node{
//     int x, y;
// };

// int bfs(int graph[][3], vector<vector<bool> > &visited, int nodex, int nodey, int M, int N, int colour1, int colour2){
//     queue<Node> q;
//     Node node = {nodex, nodey};
//     q.push(node);
//     visited[nodex][nodey] = true;
//     int comp = 1;
//     while(!q.empty()){
//         node = q.front();
//         q.pop();
//         int neighbor_x[] = {-1, 0, 0, 1};
//         int neighbor_y[] = {0, -1, 1, 0};
//         for(int i = 0; i < 4; i++){
//             int nx = node.x + neighbor_x[i], ny = node.y + neighbor_y[i];
//             if(nx >= 0 and nx <M and ny >= 0 and ny < N and !visited[nx][ny] 
//                 and (graph[nx][ny]==colour1 or graph[nx][ny] == colour2)){
//                 Node neighbor = {nx, ny};
//                 visited[nx][ny] = true;
//                 q.push(neighbor);
//                 comp++;
//             }
//         }
//     }
//     cout<<nodex<<" "<<nodey<<" "<<colour1<<" "<<colour2<<" "<<comp<<endl;
//     return comp;
// }

// int main(){
//     int M = 3, N = 3;
//     int graph[][3] = {{1, 1, 3}, {1, 1, 1}, {2, 2, 1}};

//     int max_comp = 1;

//     for(int i = 1; i <= 3; i++){
//         for(int j = i; j <= 3; j++){
//             vector<vector<bool> > visited(M, vector<bool>(N, false));
//             for(int k = 0; k < M; k++){
//                 for(int l = 0; l < N; l++){
//                     if(!visited[k][l])
//                         max_comp = max(max_comp, bfs(graph, visited, k, l, M, N, i, j));
//                 }
//             }
//         }
//     }

//     cout<<"Max components with 2 colours is "<<max_comp<<endl;
//     return 0;
// }