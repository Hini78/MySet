#include <iostream>
#include"KSet.h"
using namespace std;

SetIter* KSet::createIterator() const { return new SetIter(this); }

int find(KSet& s, int el) {
    SetIter *it = s.createIterator();
    int i = 0;
    while (!(it->isDone())) {
        if (it->currentItem() == el) return i;
        i++;
        it->Next();
    }
    return -1;
}

int findByOperators(KSet& s, int el) {
    SetIter it(s);
    int i = 0;
    while (!(it())) {
        if (*it == el) return i;
        i++;
        ++it;
    }
    return -1;
}
int main()
{
    KSet k,k2,rez;
    for (int i = 0; i < 7; i++) {
        k >> (2 * i);
        k2 >> (2 * i);
    }
    k >> (1);
    k >> (-5);    
    k >> (58);   
    k >> (17);   
    k >> (17);  
    k >> (19);
    cout << "Set k = " << k << endl;
    cout << "Set k2 = " << k2 << endl;
    rez = k & k2;
    cout << "k & k2 = " << rez << endl;
    rez = k | k2;
    cout << "k | k2 = " << rez << endl;
    rez = k / k2;
    cout << "k / k2 = " << rez << endl;
    rez.Clear();
    //cout << rez.isEmpty() << endl;
    cout << "Position of 12 in set k = " << find(k, 12) << endl;
    cout << "Position of 54 in set k = " << findByOperators(k, 54) << endl;
}