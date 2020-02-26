#include <iostream> //pre processor directive
//this is the header file

using namespace std;

//create File class
class File{
public:
  File(); //constructor
  ~File(); //destructor

  //functions
  int sum (string data);
  double mean(string data, int sum);
  float variance(string data, double mean);
  float standardDeviation(float variance);

  //probability functions
  float probOfA(string data);
  float probOfC(string data);
  float probOfT(string data);
  float probOfG(string data);

  //bigram probability
  string bigrams(string data);

  //functions for new DNA strands
  string newDNA(double mean, float standardDeviation, double probOfA, double probOfT, double probOfC, double probOfG);
};
