// Problem Statement : You are given a stack of integers.Your task is to sort the stack in descending order using recursion, such that the top of the stack contains the greatest element.You are not allowed to use any loop - based sorting methods(e.g., quicksort, mergesort).You may only use recursive operations and the standard stack operations(push, pop, peek / top, and isEmpty).

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <stack>

using namespace std;

stack<int> sorting_by_stack(stack<int> main_stack, stack<int> dup_stack, stack<int> store_stack)
{
    if (main_stack.empty())
        return dup_stack;

    if (dup_stack.empty() || main_stack.top() < dup_stack.top())
    {
        dup_stack.push(main_stack.top());
        main_stack.pop();
        while (!store_stack.empty())
        {
            dup_stack.push(store_stack.top());
            store_stack.pop();
        }

        return sorting_by_stack(main_stack, dup_stack, store_stack);
    }

    store_stack.push(dup_stack.top());
    dup_stack.pop();
    return sorting_by_stack(main_stack, dup_stack, store_stack);
}

stack<int> sort_stack(stack<int> main_stack)
{
    stack<int> dup_stack;
    stack<int> store_stack;
    return sorting_by_stack(main_stack, dup_stack, store_stack);
}

int main()
{
    stack<int> main_stack;
    main_stack.push(4);
    main_stack.push(1);
    main_stack.push(3);
    main_stack.push(2);
    main_stack.push(2);
    main_stack.push(3);

    stack<int> dup_stack = sort_stack(main_stack);

    while (!dup_stack.empty())
    {
        cout << dup_stack.top() << endl;
        dup_stack.pop();
    }
}