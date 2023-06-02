#include <string>

using namespace std;

class SimilarityChecker {
public:
	int getLengthSimilarityScore(const string& input1, const string& input2) {
		int input1Length = input1.length();
		int input2Length = input2.length();

		if (checkSameLength(input1Length, input2Length)) return MAX_LENGTH_SCORE;
		if (checkDoubleLength(input1Length, input2Length)) return MIN_LENGTH_SCORE;

		int longStrLength = getLongLength(input1Length, input2Length);
		int shortStrLength = getShortLength(input1Length, input2Length);
		int gap = longStrLength - shortStrLength;
		return calculateLengthSimilarityScore(shortStrLength, gap);
	}

private:
	bool checkSameLength(int input1Length, int input2Length) {
		return input1Length == input2Length;
	}

	bool checkDoubleLength(int input1Length, int input2Length) {
		return input1Length * 2 <= input2Length
			|| input2Length * 2 <= input1Length;
	}

	int getLongLength(int input1Length, int input2Length) {
		if (input1Length > input2Length) return input1Length;
		return input2Length;
	}

	int getShortLength(int input1Length, int input2Length) {
		if (input1Length > input2Length) return input2Length;
		return input1Length;
	}

	int calculateLengthSimilarityScore(int shortStrLength, int gap) {
		return MAX_LENGTH_SCORE - (gap * MAX_LENGTH_SCORE / shortStrLength);
	}

	int MAX_LENGTH_SCORE = 60;
	int MIN_LENGTH_SCORE = 0;
};