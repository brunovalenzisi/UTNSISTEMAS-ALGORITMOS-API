#ifndef _TSTACK_TAD_
#define _TSTACK_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Stack
{
   List<T> l=list<T>();
};

template<typename T>
Stack<T> stack()
{
   Stack<T> st;
   return st;
}

template<typename T>
T* stackPush(Stack<T>& st,T e)
{
   return listAddFirst<T>(st.l,e);
}

template<typename T>
T stackPop(Stack<T>& st)
{
   T t=listRemoveFirst<T>(st.l);
   return t;
}

template<typename T>
bool stackIsEmpty(Stack<T> st)
{
   return listIsEmpty(st.l);
}

template<typename T>
int stackSize(Stack<T> st)
{
   return listSize<T>(st.l);
}

#endif
