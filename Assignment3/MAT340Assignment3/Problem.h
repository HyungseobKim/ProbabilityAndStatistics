#ifndef PROBLEM_H
#define PROBLEM_H

class RNG;

class Problem
{
public:
	Problem();

	virtual bool Execute() = 0;

protected:
	int EndMenu() const;

	RNG* rng;
};

#endif // !PROBLEM_H
