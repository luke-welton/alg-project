#include <fstream>
#include <sstream>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include "algorithms.h"
using namespace std;

void presetAlgs();
void randomizedAlgs();

int main() {
    presetAlgs();
    randomizedAlgs();
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
    for (int i = 0; i < 19; i++) {
        int newArray[5 * (i + 1)];
        for (int j = 0; j < 5 * (i + 1); j++) {
            int multiplier = rand() % 2 == 1 ? -1 : 1;
            newArray[j] = multiplier * (rand() % 50);
        }

        arrays[i] = newArray;
    }

    double times[19][4];
    for (int i = 0; i < 19; i++) {
        clock_t start, end;

        start = clock();
        for (int t = 0; t < 25000; t++) {
            algorithm1(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][0] = (end, start) / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < 25000; t++) {
            algorithm2(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][1] = (end, start) / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < 25000; t++) {
            algorithm3(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][2] = (end, start) / (double) CLOCKS_PER_SEC;


        start = clock();
        for (int t = 0; t < 25000; t++) {
            algorithm4(arrays[i], 0, 5 * (i + 1));
        }
        end = clock();
        times[i][3] = (end, start) / (double) CLOCKS_PER_SEC;
    }

    ofstream outStream;
    outStream.open("lucaswelton_phw_output.txt");
    for (int i = 0; i < 19; i++) {
        outStream << times[i][0] << "," << times[i][1] << "," << times[i][2] << "," << times[i][3] << endl;
    }
    outStream.close();
}