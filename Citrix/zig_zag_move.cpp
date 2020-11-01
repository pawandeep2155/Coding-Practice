#include <map>
#include <vector>
#include <iostream>
#include <limits.h>
#include <stack>

using namespace std;

bool is_valid(vector<pair<int, int> > &path){
    int n = path.size();
    if(n <= 1)
        return true;
    if(n==2)
        return path[0].first == path[1].first;
    if(n%2 == 0){
        return (path[n-1].first == path[n-2].first) and (path[1].second == path[n-1].second);
    }
    else{
        return (path[0].second == path[n-1].second);
    }
}

void collect_points(int index, int n, vector<vector<int> > &points, vector<pair<int, int> > &path, int &max_points){
    if(!is_valid(path))
        return;
    max_points = max(max_points, ((int)path.size())/2);
    if(index == n)
        return;
    collect_points(index+1, n, points, path, max_points);
    path.push_back(make_pair(points[index][0], points[index][1]));
    collect_points(index+1, n, points, path, max_points);
    path.pop_back();
}

int main(){
    int points[][2] = {{0,0}, {3, 3}, {2, 3}, {0, 2}, {2, 0}, {0, 3}};
    int n = sizeof(points) / sizeof(points[0]);
    vector<vector<int> > pointv(n, vector<int>(2, 0));
    for(int i = 0; i < n; i++){
        pointv[i][0] = points[i][0], pointv[i][1] = points[i][1];
    }
    sort(pointv.begin(), pointv.end());
    int max_points = 0;
    vector<pair<int, int> > path;
    collect_points(0, n, pointv, path, max_points);
    cout<<"Max points collect "<<max_points<<endl;
    return 0;
}