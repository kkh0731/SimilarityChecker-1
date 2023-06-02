#include "pch.h"
#include "../Day9-2/simchk.cpp"

TEST(SimilarityChecker, Length_Same) {
	string input1 = "ASD";
	string input2 = "DSA";
	int score = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	EXPECT_EQ(60, score);
}

TEST(SimilarityChecker, Length_Larger_Equal_Double) {
	string input1 = "A";
	string input2 = "BB";
	int score = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	EXPECT_EQ(0, score);
}

TEST(SimilarityChecker, Length_Less_Double_1) {
	string input1 = "AAABB";
	string input2 = "BAA";
	int score = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	EXPECT_EQ(20, score);
}

TEST(SimilarityChecker, Length_Less_Double_2) {
	string input1 = "AA";
	string input2 = "AAA";
	int score = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	EXPECT_EQ(30, score);
}

TEST(SimilarityChecker, Alpha_Same_1) {
	string input1 = "ASD";
	string input2 = "DSA";
	int score = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	EXPECT_EQ(40, score);
}

TEST(SimilarityChecker, Alpha_Same_2) {
	string input1 = "AAABB";
	string input2 = "BA";
	int score = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	EXPECT_EQ(40, score);
}

TEST(SimilarityChecker, Alpha_Different_All) {
	string input1 = "A";
	string input2 = "BB";
	int score = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	EXPECT_EQ(0, score);
}

TEST(SimilarityChecker, Alpha_Different_Partial) {
	string input1 = "AA";
	string input2 = "AAE";
	int score = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	EXPECT_EQ(20, score);
}

TEST(SimilarityChecker, Total_Same) {
	string input1 = "ASD";
	string input2 = "DSA";
	int scoreLength = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	int scoreAlpha = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	int scoreTotal = scoreLength + scoreAlpha;
	EXPECT_EQ(100, scoreTotal);
}

TEST(SimilarityChecker, Total_Different_All) {
	string input1 = "A";
	string input2 = "BB";
	int scoreLength = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	int scoreAlpha = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	int scoreTotal = scoreLength + scoreAlpha;
	EXPECT_EQ(0, scoreTotal);
}

TEST(SimilarityChecker, Total_Different_Partial) {
	string input1 = "AA";
	string input2 = "AAE";
	int scoreLength = SimilarityChecker().getLengthSimilarityScore(input1, input2);
	int scoreAlpha = SimilarityChecker().getAlphaSimilarityScore(input1, input2);
	int scoreTotal = scoreLength + scoreAlpha;
	EXPECT_EQ(50, scoreTotal);
}