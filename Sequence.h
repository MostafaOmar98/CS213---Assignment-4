#ifndef SEQUENCE_H
#define SEQUENCE_H



#include <bits/stdc++.h>
using namespace std;
//template <class T>
///template<class T>
class Sequence
{
protected:
    char * seq;
    int len;
public:
    // constructors and destructor
    Sequence();
    Sequence(char * seq);
    Sequence(string seq);
    Sequence(int length);
    Sequence(Sequence& rhs);
    virtual ~Sequence();
    Sequence& operator= (Sequence& rhs);
    // pure virtual function that should be overridden because every
    // type of sequence has its own details to be printed
    virtual void Print() = 0;
    // friend function that will find the LCS (longest common
    // subsequence) between 2 sequences of any type, according to
    // polymorphism
    friend char* Align(Sequence * s1, Sequence * s2);
};

//class Sequence{
//    private:
//
////        char * strand ;
////        string strand;
//        string type;
////        const int maxsize ;
////        vector<T> allowed_characters;
//    public:
//        Sequence();
//        Sequence(string strand);
//        Sequence(char * strand);
//        Sequence(string strand, string type);
////        Sequence(vector<T> allowed_characters);
//        void setStrand(string strand);
//        void setType(string type);
//        string getType();
//        string getStrand();
//        virtual void loadSequenceFile(string filename);
//        Sequence operator+(const Sequence& other);
//        bool operator==(const Sequence& other);
//        bool operator!=(const Sequence& other);
//        friend ostream& operator<<(ostream& out, const Sequence& sequence);
//        friend istream& operator>>(istream& in, Sequence& sequence);
//};



#endif // SEQUENCE_H

///template class Sequence<int>;