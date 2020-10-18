#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

#define R 5 
#define C 4 

using namespace std;

int collect_points(int x, int y1, int y2, int arr[R][C],  vector<vector<vector<int> > > &v){
    if(x >= R or y1 < 0 or y1 >= C or y2 < 0 or y2 >= C)
        return INT_MIN;
    if(x == R-1 and (y1!=0 or y2!=C-1)){
        return INT_MIN;
    }
    if(v[x][y1][y2] != -1)
        return v[x][y1][y2];
    int points = 0;
    int y1_next[] = {-1,-1,-1,0,0,0,1,1,1};
    int y2_next[] = {-1, 0, 1, -1, 0, 1, -1, 0, 1};
    for(int i = 0; i < 9; i++){
        points = max(points, collect_points(x+1, y1+y1_next[i], y2+y2_next[i], arr, v));
    }
    if(y1 == y2)
        points += arr[x][y1];
    else 
        points += arr[x][y1] + arr[x][y2];

    v[x][y1][y2] = points;
    return points;
}

int main(){
    int arr[R][C] = {{3, 6, 8, 2}, 
                     {5, 2, 4, 3}, 
                     {1, 1, 20, 10}, 
                     {1, 1, 20, 10}, 
                     {1, 1, 20, 10}, 
                    }; 
    int x = 0, y1 = 0, y2 = C-1;
    vector<vector<vector<int> > > v(R, vector<vector<int> >(C, vector<int>(C,-1)));
    int points = collect_points(x, y1, y2, arr, v);
    cout<<"Max points collected "<<points<<endl;
    return 0;
}