//
//  main.cpp
//  basicExample
//
//  Created by William Ching on 2019-03-20.
//  Copyright © 2019 William Ching. All rights reserved.
//

#include <fstream>
#include <iostream>

using namespace std;

int main(int argc, const char * argv[]) {

    if(argc < 3) { cout << "Enter input and output file names!" << endl; return -1; }
    
    // open input file
    ifstream fi(argv[1]);
    if(!fi) { cout << "Cannot read from input file!" << endl; return -1; }
    
    // open output file
    ofstream fo(argv[2]);
    if(!fo) { cout << "Cannot write to output file!" << endl; return -1; }
    
    // N indicates the total number of datasets
    int N;
    fi >> N;
    
    // for each dataset
    for(int i = 0; i < N; i++) {
        // M indicates the number of elements in the i-th dataset
        int M;
        fi >> M;
        int maxNum = -INT_MAX;
        int count = 0;
        // for each element in this dataset
        for(int j = 0; j < M; j++) {
            // read next (j-th) number and perform the operation (add to sum)
            int num;
            fi >> num;
            if(num > maxNum){
                count = 0;
                maxNum = num;
                count++;
            } else if (num == maxNum) {
                count++;
            }
        }
        // write the answer (sum) for this dataset along with a new-line "\n" token
        
        if(count > 0){
            fo << maxNum << " " << count << endl;
        } else {
            fo << "EMPTY" << endl;
        }
        
    }
    return 0;
}
