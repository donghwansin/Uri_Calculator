#pragma once
#include <string>
#include <vector>
using namespace std;

class Calculator
{
public:
	Calculator();
	~Calculator();
};

const string simbols = "(+-*/) ";

string GetPostFix(const string infixExpression);
double Calculate(const string postfixExpression);

