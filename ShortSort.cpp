#include <iostream>

using namespace std;

void solve() {
    string abc = "abc";
    string given;
    cin >> given;
    int count = 0;
    for(int i = 0; i < abc.length(); i++) {
        if(given[i] != abc[i]) {
            count++;
        }
    }
    if(count <= 2) {
        cout << "YES" << "\n";
    }else {
        cout << "No" << "\n";
    }
}

void solveF() {
    int size;
    cin >> size;
    int prefixCount[size+1];
    prefixCount[0] = 0;
    int hTrees[size+1];
    hTrees[0] = 0;
    int maxApples;
    cin >> maxApples;
    int count = 0;

    for(int i = 1; i < size + 1; i++) {
        int x;
        cin >> x;
        count += x;
        prefixCount[i] = count;
    }
    
    for(int i = 1; i < size + 1; i++) {
        cin >> hTrees[i];
    }
    hTrees[0] = hTrees[1];
    int maxC = 0;
    int startTree = 0;
    int endTree = 1;
    count = 0;
    for(int i = 1; i < size + 1; i++) {
        if((prefixCount[endTree] - prefixCount[startTree]) <= maxApples && hTrees[i-1] % hTrees[i] == 0) {
            endTree++;
            count++;
            if(count > maxC) {
                maxC = count;
            }   
        }else {
            bool res = true;
            if(prefixCount[endTree] - prefixCount[startTree] > maxApples && !(startTree == endTree - 1)) {
                
                i--;
                endTree--;
                res = false;
            }

            if(hTrees[i-1] % hTrees[i] != 0 && prefixCount[endTree] - prefixCount[startTree] <= maxApples) {
                if(maxC == 0) {
                    maxC = 1;
                }
            }
            
            
            endTree++;
            
            startTree = endTree - 1;
            if(res == false) {

                count = 1;
            }
             
        }
    }

    cout << maxC << "\n";
}

int main() {
    int j;
    cin >> j;

    for(int i = 0; i < j; i++) {
        solve();
    }

    return 0;
}
