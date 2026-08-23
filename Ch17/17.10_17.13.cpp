#include <iostream>
#include <bitset>
#include <vector>
#include <random>
#include <ctime>

using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ex_17_10() {
	int sqc[7]{ 1, 2, 3, 5, 8, 13, 21 };
	bitset<32> bts;											// omg bts 
	cout << "before : " << bts << '\n';
	for (const int& i : sqc) bts.flip(i);

	cout << "after : " << bts << '\n';
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ex_17_11() {
	// we can use bitset<10> for saving answers of 10-quiz.
	// but those questions are extended to 100, then we can just change the size of bitset from 10 -> 100.
	// the size of bitset is finalized at compile time, so if those counts of questions are changed at runtime, we can use vector<bool> instead.
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void set_result(bitset<10>& bs, size_t idx, bool answer) {
	bs[idx] = answer;
}

bitset<10> ex_17_12() {
	bitset<10> quiz;
	default_random_engine e(time(0));
	uniform_int_distribution<int> dist(0, 1);
	for (int i = 0; i < quiz.size(); ++i)
	{
		set_result(quiz, i, dist(e));					// user's answer.
	}
	
	// cout << "quiz state : " << quiz << '\n';

	return quiz;
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void ex_17_13() {
	bitset<10> user_answer, correct_answer;
	default_random_engine e;
	uniform_int_distribution<int> dist(0, 1);
	size_t ANSWERSIZE = correct_answer.size();
	size_t i = 0;
	int total_grade = 0;

	for (i = 0; i < ANSWERSIZE; ++i)
	{
		set_result(correct_answer, i, dist(e));			// the final answer of quiz.
	}

	user_answer = ex_17_12();							// user's answer.

	cout << "user's answers  : " << user_answer << '\n';
	cout << "correct answers : " << correct_answer << '\n';
	

	total_grade = (user_answer ^ correct_answer).count();

	cout << "your total grade is : " << total_grade << '\n';
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
	ex_17_10();
	ex_17_11();
	ex_17_12();
	cout << '\n';
	ex_17_13();
	return 0;
}

