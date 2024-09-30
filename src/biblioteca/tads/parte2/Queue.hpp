#ifndef _TQUEUE_TAD_
#define _TQUEUE_TAD_

#include <iostream>
#include "../../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
   List<T> l=list<T>();
};

template<typename T>
Queue<T> queue()
{
   Queue<T> q;
   return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
   return listAdd<T>(q.l,e);
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
   T t=listRemoveFirst<T>(q.l);
   return t;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
   return listIsEmpty(q.l);
}

template<typename T>
int queueSize(Queue<T> q)
{
   return q.l.size;
}

#endif
