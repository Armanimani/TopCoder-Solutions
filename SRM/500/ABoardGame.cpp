#include <vector> 
#include <string>
#include <algorithm>
using std::vector;
using std::string;

class ABoardGame{

	int N = 0;
	vector<int> ARegionCount;
	vector<int> BRegionCount;
	int getRegion(int i, int j);
	int getRegion(int n);

	void readData(vector<string> &s);
	string compare();

public:
	string whoWins(vector<string> board);

};

string ABoardGame::whoWins(vector<string> board){

	this->N = board.at(0).size() / 2;

	ARegionCount = vector<int>(N + 1, 0);
	BRegionCount = vector<int>(N + 1, 0);

	readData(board);
	return compare();



}

void ABoardGame::readData(vector<string> &s){

	for (int i = 0; i != s.size(); ++i){

		for (int j = 0; j != s.at(i).size(); ++j){

			if (s.at(i).at(j) == 'A'){

				ARegionCount.at(getRegion(i, j)) += 1;
			}
			else if (s.at(i).at(j) == 'B'){
				BRegionCount.at(getRegion(i, j)) += 1;
			}
		}
	}

}

int ABoardGame::getRegion(int i, int j){

	return std::max(getRegion(i), getRegion(j));

}

int ABoardGame::getRegion(int n){

	if (n < N){
		return N - n;
	}
	else {
		return n - N + 1;
	}
}

string ABoardGame::compare(){

	for (int i = 0; i != N + 1; ++i){
		if (ARegionCount.at(i) > BRegionCount.at(i)){
			return "Alice";
		}
		else if (BRegionCount.at(i) > ARegionCount.at(i)){
			return "Bob";
		}

	}
	return "Draw";
}
