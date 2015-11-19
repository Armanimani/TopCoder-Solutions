#include <vector>
using std::vector;

class ANDEquation{
public:
	int restoreY(vector<int> A);
};

int ANDEquation::restoreY(vector<int> A){

	int size = A.size();

	for (int i = 0; i != size; ++i){
		int Y = A.at(i);
		int sum = 0;
		bool firstElement = false;
		for (int j = 0; j != size; ++j){

			if (i != j){

				if (firstElement == false){
					firstElement = true;
					sum = A.at(j);
				}
				else{
					sum = sum & A.at(j);
				}
			}
		}

		if (sum == Y){
			return Y;
		}
	}
	return -1;
}
