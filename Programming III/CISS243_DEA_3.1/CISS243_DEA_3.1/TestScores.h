// Class header and definition for TestScores Class
#ifndef TESTSCORES_H
#define TESTSCORES_H

// The TestScores Class accepts an array pointer to
// an array of test scores and a function to return
// the average of the scores in the array. There 
// are member error classes to throw for scores that
// are either negative or too large.

class TestScores
{
private:
	// to point to the array of scores
	double *scores;
public:
	// Member class to throw if a score is less than 0
	// Holds the score and a funciton to return the score.
	class NegativeScore
	{
	private:
		// holds score that was identified as less than 0
		double score;
	public:
		// constructor
		NegativeScore(double s)
		{
			score = s;
		}
		// accessor function
		double getScore()
		{
			return score;
		}
	};
	// Member class to throw if a score is greater than 100
	// Holds the score and a funciton to return the score.
	class TooLargeScore
	{
	private:
		// holds score that was identified as less than 100
		double score;
	public:
		// constructor
		TooLargeScore(double s)
		{
			score = s;
		}
		// accessor function
		double getScore()
		{
			return score;
		}
	};
	// constructor accepts array pointer as argument
	TestScores(double *s)
	{
		scores = s;
	}

	// calculated return value function
	// accepts array size as an argument
	double getAverages(int n)
	{
		// function variables for total and average
		double total = 0.0;
		double average;
		// loop through scores class field
		for (int i = 0; i < n; i++)
		{
			// throw NegativeScore object if test score is
			// less than 0
			if (scores[i] < 0)
			{
				throw NegativeScore(scores[i]);
			}
			// throw TooLargeScore object if test score is
			// greater than 100
			else if (scores[i] > 100)
			{
				throw TooLargeScore(scores[i]);
			}
			// otherwise add score to total
			else
			{
				total += scores[i];
			}
		}
		// calculate average and assign to variable
		average = total / n;

		return average;
	}
};

#endif // !TESTSCORES_H

