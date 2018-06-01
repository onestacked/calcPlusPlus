#pragma once


class number
{
	friend number operator+(number, number);
};

class integer : public number
{
    public:
        int value;
};

class mathExpression
{
    public:
        virtual number calculate() = 0;
};

class ZeroMemberOperation : public mathExpression
{
	virtual number calculate() = 0;
};

class OneMemberOperation : public mathExpression
{
protected:
	mathExpression* mathexpression;
private:
	virtual number calculate() = 0;
};

class TwoMemberOperation : public mathExpression
{
protected:
	mathExpression* mathexpression1;
	mathExpression* mathexpression2;
public:
	virtual number calculate() = 0;
};



class numberExpression : public ZeroMemberOperation
{
	number value;

	virtual number calculate() = 0;
};

class Addition : public TwoMemberOperation
{

	virtual number calculate()
	{
		return mathexpression1->calculate() + mathexpression2->calculate();
	}
};