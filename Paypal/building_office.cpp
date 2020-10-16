#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <limits.h>

#define pr pair<int,int>
using namespace std;

int building_office(int x, int y, int w, int h, int count, int max_count, vector<pr> &buildings){
    int office_required;
    if(x > w or y > h)
        return INT_MAX;
    if(count == max_count){
        office_required = INT_MIN;
        for(int i = 1; i <= w; i++){
            for(int j = 1; j <= h; j++){
                int distance = INT_MAX;
                for(int k = 0; k < buildings.size(); k++){  // Nearest office distance
                    distance = min(distance, abs(i-buildings[k].first) + abs(j-buildings[k].second));
                }
                office_required = max(office_required, distance);
            }
        }
    }
    else{
        int next_x = (y==h)?x+1:x;
        int next_y = (next_x>x)?0:y+1;
        int b1 = building_office(next_x, next_y, w, h, count, max_count, buildings);
        buildings.push_back(make_pair(x, y));
        int b2 = building_office(next_x, next_y, w, h, count+1, max_count, buildings);
        buildings.pop_back();
        office_required = min(b1, b2);
    }
    return office_required;
}

int main(){
    int w = 2, h = 3, n = 2;
    vector<pr> buildings;
    int distance = building_office(1, 1, w, h, 0, n, buildings);
    cout<<"Max distance from office building "<<distance<<endl;
    return 0;
}