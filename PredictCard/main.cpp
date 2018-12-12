#include <iostream>
#include <opencv2\opencv.hpp>
#include "PredictCard.h"
#include "count.h"

using namespace std;

int main(){
	int suit = 0, rank[4] = { 0, 0, 0, 0 };
	//for (int i = 0; i < 4; i++){
	while(1){
		scan(suit, rank[1]);
		cout << "suit: " << suit << ", rank: " << rank[1] << endl;
		waitKey();
	}
	D24(rank[0], rank[1], rank[2], rank[3]);
	return 0;
}