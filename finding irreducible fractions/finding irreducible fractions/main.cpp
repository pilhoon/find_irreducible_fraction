//
//  main.cpp
//  finding irreducible fractions
//
//  Created by 1000961 on 8/4/15.
//  Copyright (c) 2015 ph. All rights reserved.
//

#include <iostream>

using namespace std;


double dabs(double a) { //double abs
    return (a<0)? -a : a;
}

int get_gcd(int a, int b) {
    int smaller = a, larger = b;
    if(a>b) {
        larger = a;
        smaller = b;
    } // naming is meaningless.
    
    while(larger % smaller) { //euclid
        larger -= (larger/smaller)*smaller;
        //swap
        int tmp = larger;
        larger = smaller;
        smaller = tmp;
    }
    
    return smaller;
}

bool is_irreducible(int a, int b) {
    return get_gcd(a, b) == 1;
}

int main(int argc, const char * argv[]) {
    cout << "I'll run infinitly. Stop by C-c\n";
    double d;
    cout << "insert d: ";
    cin >> d;
    while(1) {
        for(int i=2; i<INT_MAX; i++) { //denom
            int j=1;
            while((double)j/i < d) {
                j++;
            }
            
            double former = dabs(d - (double)(j-1)/i), latter = dabs(d - (double)j/i);
            if(former < latter) j--;
            
            if(j<=0) continue;
            
            if(is_irreducible(j, i))
                cout << j << "/" << i << endl;
            //else skip.
        }
    }
    return 0;
}
