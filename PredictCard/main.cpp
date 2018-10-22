#include <iostream>
#include <opencv2\opencv.hpp>
#include "PredictCard.h"

using namespace std;

int main(){
	int suit = 0, rank = 0;
    scan(suit, rank);
	cout << "suit: " << suit << ", rank: " << rank << endl;
	return 0;
}