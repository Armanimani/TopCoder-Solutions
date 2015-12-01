#include <vector>
#include <algorithm>
using namespace std;

class PlaneGame{

public:
	int bestShot(vector<int> x, vector<int> y){

		int ret = 0;

		if (x.size() <4){
			return x.size();
		}

		for (int i = 0; i != x.size(); ++i){
			for (int j = i + 1; j != y.size(); ++j){
				if (j != i){
					int dx = x[j] - x[i];
					int dy = y[j] - y[i];
					for (int k = j + 1; k != x.size(); ++k){
						int number = 0;
						for (int l = 0; l != x.size(); ++l){
							if ((x[i] - x[l]) * (y[j] - y[l]) - (x[j] - x[l]) * (y[i] - y[l]) == 0){
								++number;
							}
							else if ((y[k] - y[l]) * dy + (x[k] - x[l]) * dx == 0){
								++number;
							}
							ret = max(ret, number);
						}

					}
				}
			}
		}

		return ret;
	}
};