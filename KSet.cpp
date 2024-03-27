#include "KSet.h"
KSet::~KSet() {
	delete[] kset;
}
KSet::KSet(const KSet& s){
	size = s.size;
	kset = s.kset;
}
KSet& KSet::operator=(const KSet& s) {
	if (this == &s) return *this;
	size = s.size;
	kset = s.kset;
	return *this;
}
KSet& KSet::operator|(KSet& s) {
	KSet* n = new KSet;
	for (int i = 0; i < s.size; i++) {
		*n >> s.kset[i];
	}
	for (int i = 0; i < size; i++) {
		*n >> this->kset[i];
	}
	return *n;
}
KSet& KSet::operator&(KSet& s) {
	int i = 0, j = 0;
	KSet *n=new KSet;
	while (i < size && j < size) {
		if (this->kset[i] == s.kset[j]) {
			*n >> s.kset[j];
			i++;
			j++;
		}
		else if (this->kset[i] > s.kset[j]) j++;
		else i++;
	}
	return *n;
}
KSet& KSet::operator/(KSet& s) {
	KSet* n = new KSet;
	for (int i = 0; i < size; i++) {
		if (s.findPos(kset[i]) > -1) *n >> kset[i];
	}
	return *n;
}
KSet& KSet::operator|=(KSet& s) {
	KSet* n = new KSet;
	*n = *this | s;
	return *n;
}
KSet& KSet::operator&=(KSet& s) {
	KSet* n = new KSet;
	*n = *this & s;
	return *n;
}
KSet& KSet::operator/=(KSet& s) {
	KSet* n = new KSet;
	*n = *this / s;
	return *n;
}
void KSet::Clear() {
	size = 0;
	int* a = new int[1];
	delete[] kset;
	kset = a;
}
bool KSet::isEmpty() {
	return (size < 1);
}
int KSet::findPos(int el) {
	int left = 0;
	int right = size - 1;
	int mid;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (kset[mid] == el) return -1;
		else if (kset[mid] < el) left = mid + 1;
		else right = mid - 1;
	}
	return left; 
}

void KSet::operator>>(int el) {
	if (size == 0) {
		kset[0] = el;
		size++;
	}
	else{
		int pos = findPos(el);
		size++;
		int* newkset = new int[size];
		if (pos != -1) {
			int i;
			for (i = 0; i < pos; i++) {
				newkset[i] = kset[i];
			}
			newkset[i] = el;
			i++;
			for (; i < size; i++) {
				newkset[i] = kset[i - 1];
			}
			delete[] kset;
			kset = newkset;
			
		}
		else {
			size--;
			delete[] newkset;
		}
		
	}
}
ostream& operator<<(ostream& os, const KSet& k) {
	if (k.size > 0) {
		os << "[";
		int i = 0;
		for (; i < k.size - 1; i++) {
			os << k.kset[i] << ", ";
		}
		os << k.kset[i++] << "]";
	}
	else os << "[]";
	return os;
}