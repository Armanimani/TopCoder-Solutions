#include <string>
#include <algorithm>
using namespace std;
class ABBADiv1{

public:
	string canObtain(string initial, string target);

private:

	bool condition = false;

	string initial;
	string target;

	string reverseAmove(string s);
	string reverseBmove(string s);

	void compare(string initial, string target);

};

string ABBADiv1::canObtain(string initial, string target){

	this->initial = initial;
	this->target = target;
	compare(initial, target);

	if (condition == true){
		return "Possible";
	}
	else{
		return "Impossible";
	}

}

string ABBADiv1::reverseAmove(string s){

	return s.substr(0, s.size() - 1);

}

string ABBADiv1::reverseBmove(string s){

	string temp = s.substr(1, s.size());
	reverse(temp.begin(), temp.end());
	return temp;
}

void ABBADiv1::compare(string initial, string target){

	if (initial.size() == target.size()){
		if (initial == target){
			condition = true;
		}
	}
	else{

		if (*(target.begin()) == 'B'){
			string s1 = reverseBmove(target);
			compare(initial, s1);
		}

		if (*(target.end() - 1) == 'A'){
			string s1 = reverseAmove(target);
			compare(initial, s1);
		}

	}
}
