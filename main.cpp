#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <cmath>
#include "algorithms.h"
using namespace std;

void presetAlgs();
void randomizedAlgs();
int calculateComplexity(int size, int alg);

int main() {
    presetAlgs();
    randomizedAlgs();
    exit(0);
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

void randomizedAlgs() {
    srand(time(NULL));

    int* arrays[19];
    for (int i = 0; i < 20; i++) {
        int newArray[5 * (i + 1)];
        for (int j = 0; j < 5 * (i + 1); j++) {
            int multiplier = rand() % 2 == 1 ? -1 : 1;
            newArray[j] = multiplier * (rand() % 50);
        }

        arrays[i] = newArray;
    }

    double times[20][8];
    int runs = 100000;
    for (int i = 0; i < 20; i++) {
        clock_t start, end;

        start = clock();
        for (int t = 0; t < runs; t++) {
            algorithm1(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][0] = (end - start) * 10000 / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < runs; t++) {
            algorithm2(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][1] = (end - start) * 10000 / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < runs; t++) {
            algorithm3(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][2] = (end - start) * 10000 / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < runs; t++) {
            algorithm4(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][3] = (end - start) * 10000 / (double) CLOCKS_PER_SEC;

        for (int j = 1; j <= 4; j++) {
            times[i][3 + j] = calculateComplexity(5 * (i + 1), j);
        }
    }

    ofstream outStream;
    outStream.open("lucaswelton_phw_output.txt");

    outStream << "Algorithm1,Algorithm2,Algorithm3,Algorithm4,T1(n),T2(n),T3(n),T4(n)";

    for (int i = 0; i < 20; i++) {
        outStream << times[i][0] << "," << times[i][1] << "," << times[i][2] << "," << times[i][3] << ","
                  << times[i][4] << "," << times[i][5] << "," << times[i][6] << "," << times[i][7] << endl;
    }
    outStream.close();
}

int calculateComplexity(int size, int alg) {
    switch (alg) {
        case 1: {
            return (int) (4 / 3 * pow(size, 3) + 10 * pow(size, 2) + 41 / 3 * size + 8);
        }
        case 2: {
            return (int) (13 / 2 * pow(size, 2) + 23 / 2 * size + 8);
        }
        case 3: {
            return (int) (12 * size * log2(size) + 24 * size - 17);
        }
        case 4: {
            return 14 * size + 5;
        }
        default: return 0;
    }
}