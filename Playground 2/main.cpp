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
#include <unordered_map>
#include <unordered_set>
#include <fstream>

using namespace std;
class rect{
public:
    rect() = default;
    rect(int a,int b,int c,int d, int e){bax = a; bay = b ; jfx = c; jfy = d; id = e;};
    int bax, bay, jfx, jfy, id;
};
long long int sum = 0, diff = 0;

int builds;
rect arr [100000];
//auto l_hash_x = [](const rect* rect){return rect->bax;};
//auto l_hash_y = [](const rect* rect){return rect->bay;};
auto l_eq = [](const rect* lhs, const rect* rhs){
    if(lhs->bay == rhs->jfy){
        if ( (lhs->bax < rhs->bax && lhs->jfx > rhs->bax) ||
             (lhs->bax < rhs->jfx && lhs->jfx > rhs->jfx) ){
            return true;
        }
    }
    else if (lhs->bax == rhs->jfx){
        if ( (lhs->bay < rhs->bay && lhs->jfy > rhs->bay) ||
             (lhs->bay < rhs->jfy && lhs->jfy > rhs->jfy) ){
            return true;
        }
    }
    return false;
};
int main() {
    // insert code here...
    //std::cout << "Hello, World!\n";
    //ifstream in("/Users/takatsbalint/Documents/Projects/Playground 2/Playground 2/base.txt");
    unordered_multimap<int,int> map_x;
    unordered_multimap<int,int> map_y;
    ios_base::sync_with_stdio(false);
    cin >> builds;
    for(int i = 0;i < builds; i++){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        sum += (c - a) * 2 + (d - b) * 2;
        //rect_set.insert({a,b,c,d,i});
        arr[i] = {a,b,c,d,i};
        // lehet rossz az élet
        map_x.insert({a,i});
        map_y.insert({b,i});
    }
    //cout << sum << "\n";
    for (int i = 0; i < builds; i++){
        auto r = map_x.equal_range(arr[i].jfx);
        for(auto j = r.first; j != r.second;j++){
            if ((arr[i].bay <= arr[j->second].bay && arr[i].jfy >= arr[j->second].bay) ||
                (arr[i].bay <= arr[j->second].jfy && arr[i].jfy >= arr[j->second].jfy) ||
                (arr[i].bay >=arr[j->second].bay && arr[i].jfy <= arr[j->second].jfy) ){
                //cout <<min(arr[i].jfy,arr[j->second].jfy)-max(arr[i].bay,arr[j->second].bay)<< "\n";
                diff += min(arr[i].jfy,arr[j->second].jfy)-max(arr[i].bay,arr[j->second].bay);
            }
        }
        auto r2 = map_y.equal_range(arr[i].jfy);
        for(auto j = r2.first; j != r2.second;j++){
            //cout <<arr[i].bax <<" "<<arr[i].jfx <<" "<<arr[j->second].bax<<" "<<arr[j->second].jfx<< "\n";
            if ((arr[i].bax <= arr[j->second].bax && arr[i].jfx >= arr[j->second].bax) ||
                (arr[i].bax <= arr[j->second].jfx && arr[i].jfx >= arr[j->second].jfx) ||
                (arr[i].bax >= arr[j->second].bax && arr[i].jfx <= arr[j->second].jfx) ){
               // cout << min(arr[i].jfx,arr[j->second].jfx)-max(arr[i].bax,arr[j->second].bax) << "\n";
                diff += min(arr[i].jfx,arr[j->second].jfx)-max(arr[i].bax,arr[j->second].bax);
            }
        }
    }
    cout<< sum - diff * 2 << "\n";
}
