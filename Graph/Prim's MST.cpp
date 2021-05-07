//Logic: https://www.hackerearth.com/practice/algorithms/graphs/minimum-spanning-tree/tutorial/

#include <bits/stdc++.h>
using namespace std;

// Time Complexity : O(V^2)
int primsMST(vector<int> graph[], int v) {
    vector<int> key(v, INT_MAX);
    vector<bool> mSet(v, false);
    int res = 0;
    
    for(int count=0; count<v; count++) {
        int p = -1;
        for(int i=0; i<v; i++) {
            if(!mSet[i] && (p==-1 || key[i]<key[p]))
                p = i;
            mSet[p] = true;
            res = res + key[p];

            for(int q=0; q<v; q++) {
                if(graph[p][q] && !mSet[q])
                    key[q] = min(key[q], graph[p][q]);
            }
        }
    }
    return res;
}
