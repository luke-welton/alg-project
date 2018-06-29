#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include "algorithms.h"
using namespace std;

void presetAlgs();

int main() {
    presetAlgs();
}

void presetAlgs() {
    ifstream inStream;

    char filename[] = "phw_input.txt";
    inStream.open(filename);

    if (inStream) {
        int presetNums[10];
        for (int i = 0; i < 10; i++) {
            string input = "";
            getline(inStream, input, ',');
            istringstream(input) >> presetNums[i];
        }

        cout << "algorithm-1: " << algorithm1(presetNums, 0, 9) << endl;
        cout << "algorithm-2: " << algorithm2(presetNums, 0, 9) << endl;
        cout << "algorithm-3: " << algorithm3(presetNums, 0, 9) << endl;
        cout << "algorithm-4: " << algorithm4(presetNums, 0, 9) << endl;
    } else {
        printf("An error occurred trying to open the file \"phw_input.txt\"");
        exit(1);
    }
}
