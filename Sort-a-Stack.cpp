#include <bits/stdc++.h> 

void insert(stack<int>&stack,int ele){
	if(stack.empty() || (!stack.empty() && stack.top()<ele)){
		stack.push(ele);
		return;
	}
	int topele  = stack.top();
	stack.pop();
	insert(stack,ele);
	stack.push(topele);
}

void sortStack(stack<int> &stack)
{
	if(stack.empty())	return;
	int topElement = stack.top();
	stack.pop();
	sortStack(stack);
	insert(stack,topElement);
}
