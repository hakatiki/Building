//
//  main.cpp
//  Playground 2
//
//  Created by Takáts Bálint on 2018. 01. 10..
//  Copyright © 2018. Takáts Bálint. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <chrono>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;
class rect{
public:
    rect() = default;
    rect(int a,int b,int c,int d){bax = a; bay = b ; jfx = c; jfy = d;};
    int bax, bay, jfx, jfy;
};
long long int sum = 0, diff = 0;
int a,b,c,d;
unordered_map<int,vector<pair<int,int>>> map_x; // also x cord
unordered_map<int,vector<pair<int,int>>> map_y; // also x cord
int builds;
rect arr [100000];
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //ifstream in("/Users/takatsbalint/Documents/Projects/Playground 2/Playground 2/base.txt");
    auto be = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> builds;;
    for(int i = 0; i < builds; i++){
        cin >> a >> b >> c >> d;
        sum += (c - a) * 2 + (d - b) * 2;
        
        map_x[a].push_back({b,d});
        map_x[c].push_back({b,d});
        
        map_y[b].push_back({a,c});
        map_y[d].push_back({a,c});
    }
    for(auto i: map_x){
        sort(i.second.begin(),i.second.end());
        for(int j = 0; j < i.second.size()-1;j++){
            for(int k = j + 1; k < i.second.size();k++){
                int mini = min(i.second[j].second,i.second[k].second);
                int maxi = max(i.second[j].first,i.second[k].first);
                if (mini-maxi > 0 ){
                    diff += mini-maxi;
                }
                if (i.second[j].second < i.second[k].second){
                    j = k - 1;
                    break;
                }
                j = k;
            }
        }
    }
    for(auto i: map_y){
        sort(i.second.begin(),i.second.end());
        for(int j = 0; j < i.second.size()-1;j++){
            for(int k = j + 1; k < i.second.size();k++){
                int mini = min(i.second[j].second,i.second[k].second);
                int maxi = max(i.second[j].first,i.second[k].first);
                if (mini-maxi > 0 ){
                    diff += mini-maxi;
                }
                if (i.second[j].second < i.second[k].second){
                    j = k - 1;
                    break;
                }
                j = k;
            }
        }
    }
    auto e = chrono::high_resolution_clock::now();
    //cout << chrono::duration_cast<chrono::milliseconds>(e-be).count()<< "\n";
    cout<< sum - diff * 2 << "\n";
}
