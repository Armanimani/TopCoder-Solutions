#include <vector>
#include <algorithm>

using std::vector;

class BearSlowlySorts{

public:

	int minMoves(vector<int> &w){
		
		int numberMoves[] = { 0, 0 };
		
		for (int i = 0; i != 2; ++i){
			vector<int> temp = w;
			int cnt = i;

			while (!isSorted(temp)){

				if (cnt % 2 == 0){ // sort left side
					std::sort(temp.begin(), temp.end() - 1);
				}
				else{
					std::sort(temp.begin() + 1, temp.end()); // sort right side
				}

				cnt++;
				++numberMoves[i];
			}
		}

		return std::min(numberMoves[0], numberMoves[1]);
	}
	
private:

	bool isSorted(vector<int> w){

		for (auto i = 0; i != w.size() - 1; ++i){
			if (w[i] > w[i + 1]){
				return false;
			}
		}
		return true;
	}

};
