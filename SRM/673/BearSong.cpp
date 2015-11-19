#include <string>
#include <vector>
using std::string;
using std::vector;

class BearSong{

public:

	int countRareNotes(vector<int> notes){

		counter = vector<int>(1001, 0);

		calculate(notes);

		int cnt = 0;
		for (auto i = 0; i != counter.size(); ++i){

			if (counter[i] == 1){
				++cnt;
			}
		}
		return cnt;
	}

private:

	vector<int> counter;

	void calculate(vector<int> &notes){

		for (auto i = 0; i != notes.size(); ++i){

			++counter[notes[i]];
		}
	}

};