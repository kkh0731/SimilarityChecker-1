#include <string>
#include <vector>

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

	int getAlphaSimilarityScore(const string& input1, const string& input2) {
		vector<int> alphaBitmap1 = getAlphaBitmap(input1);
		vector<int> alphaBitmap2 = getAlphaBitmap(input2);

		int alphaSameCnt = getAlphaSameCount(alphaBitmap1, alphaBitmap2);
		int alphaDiffCnt = getAlphaDiffCount(alphaBitmap1, alphaBitmap2);

		if (checkSameAlpha(alphaDiffCnt)) return MAX_ALPHA_SCORE;
		if (checkDiffAlpha(alphaSameCnt)) return MIN_ALPHA_SCORE;
		return calculateAlphaSimilarityScore(alphaSameCnt, alphaDiffCnt);
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

	vector<int> getAlphaBitmap(const string& str) {
		vector<int> alphaBitmap(NUMBER_OF_ALPHA);
		for (int i = 0; i < str.length(); i++) {
			alphaBitmap[str[i] - 'A'] = 1;
		}
		return alphaBitmap;
	}

	int getAlphaSameCount(vector<int> alphaBitmap1, vector<int> alphaBitmap2) {
		int result = 0;
		for (int i = 0; i < NUMBER_OF_ALPHA; i++) {
			if (alphaBitmap1[i] != 0 || alphaBitmap2[i] != 0) {
				if (alphaBitmap1[i] == alphaBitmap2[i]) result++;
			}
		}
		return result;
	}

	int getAlphaDiffCount(vector<int> alphaBitmap1, vector<int> alphaBitmap2) {
		int result = 0;
		for (int i = 0; i < NUMBER_OF_ALPHA; i++) {
			if (alphaBitmap1[i] != 0 || alphaBitmap2[i] != 0) {
				if (alphaBitmap1[i] != alphaBitmap2[i]) result++;
			}
		}
		return result;
	}

	bool checkSameAlpha(int alphaDiffCnt) {
		return alphaDiffCnt == 0;
	}

	bool checkDiffAlpha(int alphaSameCnt) {
		return alphaSameCnt == 0;
	}

	int calculateAlphaSimilarityScore(int alphaSameCnt, int alphaDiffCnt) {
		return alphaSameCnt * MAX_ALPHA_SCORE / (alphaSameCnt + alphaDiffCnt);
	}

	const int MAX_LENGTH_SCORE = 60;
	const int MIN_LENGTH_SCORE = 0;
	const int MAX_ALPHA_SCORE = 40;
	const int MIN_ALPHA_SCORE = 0;
	const int NUMBER_OF_ALPHA = 26;
};