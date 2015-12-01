#include <vector>
#include <string>

using namespace std;

class RelationClassifier{

public:

	string isBijection(vector<int> domain, vector<int> range){

		vector<int> d(100, 0);
		vector<int> r(100, 0);

		for (int i = 0; i != domain.size(); ++i){
			++d[domain[i] - 1];
			++r[range[i] - 1];
		}

		for (int i = 0; i != d.size(); ++i){
			if (d[i] > 1 || r[i] > 1){
				return "Not";
			}
		}

		return "Bijection";
	}
};