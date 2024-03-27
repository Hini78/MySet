#pragma once
#include<iostream>
using namespace std;
class KSet
{
private:
	int findPos(int el);
	int size;
	int *kset;
public:
	friend class SetIter;
	KSet() :size(0) { kset = new int[size+1]; }
	KSet(const KSet& s);
	KSet& operator=(const KSet& s);
	KSet& operator|(KSet& s);
	KSet& operator&(KSet& s);
	KSet& operator/(KSet& s);
	KSet& operator|=(KSet& s);
	KSet& operator&=(KSet& s);
	KSet& operator/=(KSet& s);
	~KSet();
	int Size() { return size; }
	void Clear();
	bool isEmpty();
	void operator>>(int el);
	SetIter* createIterator() const;
	friend ostream& operator<<(ostream& os, const KSet& k);
};
class SetIter
{
private:
	const KSet* ks;
	int index;
public:
	SetIter(const KSet* s) :index(0) { ks = s; }
	SetIter(const KSet& s) :index(0) { ks = &s; }
	int currentItem() { return (ks->kset[index]); }
	void First() { index=0; }
	void Next() { index++; }
	void Previous() { index--; }
	bool isDone() { return (index >= ks->size); }
	void operator++() { index++; }
	void operator--() { index--; }
	bool operator()() { return (index >= ks->size); }
	int operator *() { return(ks->kset[index]); }
};