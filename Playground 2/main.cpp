//
//  main.cpp
//  Playground 2
//
//  Created by Takáts Bálint on 2018. 01. 10..
//  Copyright © 2018. Takáts Bálint. All rights reserved.
//

#include <iostream>
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
unordered_multimap<int,int> map_x;
unordered_multimap<int,int> map_y;
int builds;
rect arr [100000];
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //ifstream in("/Users/takatsbalint/Documents/Projects/Playground 2/Playground 2/base.txt");
    auto b = chrono::high_resolution_clock::now();
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //map_x.reserve(builds);
    cin >> builds;
    map_x.reserve(builds);
    map_y.reserve(builds);
    for(int i = 0;i < builds; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        sum += (c - a) * 2 + (d - b) * 2;
        arr[i] = {a,b,c,d};
        map_x.insert({a,i});
        map_y.insert({b,i});
    }
    for (int i = 0; i < builds; i++){
        auto r = map_x.equal_range(arr[i].jfx);
        for(auto j = r.first; j != r.second;j++){
            int mini = min(arr[i].jfy,arr[j->second].jfy);
            int maxi = max(arr[i].bay,arr[j->second].bay);
            if (mini-maxi>0 ){
                diff += mini-maxi;
            }
            /*if ((arr[i].bay <= arr[j->second].bay && arr[i].jfy >= arr[j->second].bay) ||
                (arr[i].bay <= arr[j->second].jfy && arr[i].jfy >= arr[j->second].jfy) ||
                (arr[i].bay >=arr[j->second].bay && arr[i].jfy <= arr[j->second].jfy) ){
                //cout <<min(arr[i].jfy,arr[j->second].jfy)-max(arr[i].bay,arr[j->second].bay)<< "\n";
                diff += min(arr[i].jfy,arr[j->second].jfy)-max(arr[i].bay,arr[j->second].bay);
            }*/
        }
        auto r2 = map_y.equal_range(arr[i].jfy);
        for(auto j = r2.first; j != r2.second;j++){
            //cout <<arr[i].bax <<" "<<arr[i].jfx <<" "<<arr[j->second].bax<<" "<<arr[j->second].jfx<< "\n";
            int mini = min(arr[i].jfx,arr[j->second].jfx);
            int maxi = max(arr[i].bax,arr[j->second].bax);
            if (mini-maxi>0 ){
                diff += mini-maxi;
            }
           // if ((arr[i].bax <= arr[j->second].bax && arr[i].jfx >= arr[j->second].bax) ||
                //(arr[i].bax <= arr[j->second].jfx && arr[i].jfx >= arr[j->second].jfx) ||
                //(arr[i].bax >= arr[j->second].bax && arr[i].jfx <= arr[j->second].jfx) ){
               // cout << min(arr[i].jfx,arr[j->second].jfx)-max(arr[i].bax,arr[j->second].bax) << "\n";
                //diff += min(arr[i].jfx,arr[j->second].jfx)-max(arr[i].bax,arr[j->second].bax);
           // }
        }
    }
    auto e = chrono::high_resolution_clock::now();
    //cout << chrono::duration_cast<chrono::milliseconds>(e-b).count()<< "\n";
    cout<< sum - diff * 2 << "\n";
}
