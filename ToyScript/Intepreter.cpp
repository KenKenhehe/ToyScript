
#include "Intepreter.h"
#include <typeinfo>

Value* Intepreter::Visit(Node* node)
{
	if (node == nullptr) 
	{
		return nullptr;
	}
	const char* str = typeid(*node).name();
	if (strcmp(str, "class NumberNode") == 0)
	{
		return VisitNumberNode(node);
	}
	else if (strcmp(str, "class AddNode") == 0)
	{
		return VisitAddNode(node);
	}
	else if (strcmp(str, "class SubtractNode") == 0)
	{
		return VisitSubtractNode(node);
	}
	else if (strcmp(str, "class MultiplyNode") == 0)
	{
		return VisitMultiplyNode(node);
	}
	else if (strcmp(str, "class DivideNode") == 0)
	{
		return VisitDivideNode(node);
	}
	else if (strcmp(str, "class PlusNode") == 0)
	{
		return VisitPlusNode(node);
	}
	else if (strcmp(str, "class MinusNode") == 0)
	{
		return VisitMinusNode(node);
	}
	std::string errStr = "MATH ERROR: " + errorInfo;
	throw errStr;
}

Value* Intepreter::VisitNumberNode(Node* node)
{
	float value = atof(((NumberNode*)node)->GetValue().c_str());
	Value* num = new NumberValue(value);
	return num;
}

Value* Intepreter::VisitAddNode(Node* node)
{
	float leftValue = Visit(((AddNode*)node)->GetLeft())->GetValue();
	float rightValue = Visit(((AddNode*)node)->GetRight())->GetValue();

	Value* result = new NumberValue(leftValue + rightValue);
	return result;
}

Value* Intepreter::VisitSubtractNode(Node* node)
{
	float leftValue = Visit(((AddNode*)node)->GetLeft())->GetValue();
	float rightValue = Visit(((AddNode*)node)->GetRight())->GetValue();

	Value* result = new NumberValue(leftValue - rightValue);
	return result;
}

Value* Intepreter::VisitMultiplyNode(Node* node)
{
	float leftValue = Visit(((AddNode*)node)->GetLeft())->GetValue();
	float rightValue = Visit(((AddNode*)node)->GetRight())->GetValue();

	Value* result = new NumberValue(leftValue * rightValue);
	return result;
}

Value* Intepreter::VisitDivideNode(Node* node)
{
	float leftValue = Visit(((AddNode*)node)->GetLeft())->GetValue();
	float rightValue = Visit(((AddNode*)node)->GetRight())->GetValue();
	if (rightValue == 0)
	{
		errorInfo = "can not divide by zero";
	}
	else
	{
		Value* result = new NumberValue(leftValue / rightValue);
		return result;
	}
}

Value* Intepreter::VisitPlusNode(Node* node)
{
	float value = atof(((NumberNode*)node)->GetValue().c_str());
	Value* num = new NumberValue(value);
	return num;
}

Value* Intepreter::VisitMinusNode(Node* node)
{
	float value = Visit(((MinusNode*)node)->GetNode())->GetValue();
	Value* num = new NumberValue(-value);
	return num;
}


