#include "File.h"
#include <sstream>
#include <cmath>
#include <math.h>

using namespace std;

File::File(){
}

File::~File(){
  cout << "object deleted" << endl;
}

//sum of the nucleotides
int File::sum(string data){
  int sum;
  for(int i = 0; data.size(); ++i){
    char dataAt = tolower(data[i]);
    if(dataAt == 'a') {
      sum++;
    }else if(dataAt == 't'){
      sum++;
    }else if(dataAt == 'c'){
      sum++;
    }else if(dataAt == 'g'){
      sum++;
    }else{
      sum == sum;
    }
  }
  return sum;
}

double File::mean(string data, int sum){
  //int lines = 5; // for testing purposes
  double mean = 0.0;
  istringstream file(data);
  string line;
  while (getline(file, line)) {
    lines++;
  }
  cout << lines << endl;*/
  mean = sum / double(lines);
  return mean;
}

float File::variance(string data, double mean){
  //set variables
  int numOfLines = 0;
  int amountOfNuc = 0;
  float x = 0; //variable for amount - mean
  float y = 0; //variable for x squared
  float total = 0;
  float variance = 0;

  //find variables
  istringstream file(data);
  string line;
  while (getline(file, line)){
    numOfLines++;

    //calculations for each line
    amountOfNuc = line.size();
    x = amountOfNuc - mean;
    y = pow(x,2);
    total = total + y;
    amountOfNuc = 0; // reset
    x = 0;
    y = 0;
    return total, numOfLines;
  }
  variance = total / float(numOfLines);
  return variance;
}

float File::standardDeviation(float variance){
  float sd = 0;
  sd = sqrt(variance);
  return sd;
}

//find the probability of the A nucleotide
double File::probOfA(string data){
  int a = 0;
  double sum = 0;
  double probability = 0;
  for (int i = 0; data.size(); ++i){
    char strData = tolower(data[i]); // all characters lower case
    if(strData == 'a'){
      a++;
      sum++; // add for total number of nucleotides to include A as well
    }else{
      sum++;
    }
    return a;
  }
  probability = (a / sum); // calculation and percent outcome
  return probability;
}

//find the probability of the C nucleotide
double File::probOfC(string data){
  int c = 0;
  double sum = 0;
  double probability = 0;
  for (int i = 0; data.size(); ++i){
    char strData = tolower(data[i]);
    if(strData == 'c'){
      c++;
      sum++;
    }else{
      sum++;
    }
    return c;
  }
  probability = (c / sum);
  return probability;
}

//find the probability of the T nucleotide
double File::probOfT(string data){
  int t = 0;
  double sum = 0;
  double probability = 0;
  for (int i = 0; data.size(); ++i){
    char strData = tolower(data[i]);
    if(strData == 't'){
      t++;
      sum++;
    }else{
      sum++;
    }
    return t;
  }
  probability = (t / sum);
  return probability;
}

//find the probability of the G nucleotide
double File::probOfG(string data){
  int g = 0;
  double sum = 0;
  double probability = 0;
  for (int i = 0; data.size(); ++i){
    char strData = tolower(data[i]);
    if(strData == 'g'){
      g++;
      sum++;
    }else{
      sum++;
    }
    return g;
  }
  probability = (g / sum);
  return probability;
}

string File::newDNA(double mean, float standardDeviation, double probOfA, double probOfT, double probOfC, double probOfG){
  //make each probability a percent out of 100
  double probA = probOfA * 100;
  double probT = probOfT * 100;
  double probC = probOfC * 100;
  double probG = probOfG * 100;

  //two random numbers out of 100
  double a = ((double) rand() / (RAND_MAX));
  double b = ((double) rand() / (RAND_MAX));

  //Gaussian distribution
  float c = (sqrt(-2 * (ln(a))) * cos(2 * M_PI * b);

  float d = (standardDeviation * c) + mean;
  string dna = "";

  //for correct probability
  for(int i = 0; i < d; ++i){
    double randNum;

    randNum = rand() % 100+1;
    if(randNum <= probA){
      dna = dna + "A";
    }else if(probA < randNum <= (probA + probT) ){
      dna = dna + "T";
    }else if((probA + probT) < randNum <= (probA + probT + probC) ){
      dna = dna + "C";
    }else if((probA + probT + probC)< randNum <= (probA + probT + probC + probG) ){
      dna = dna + "G";
    }
  }
  return dna;
}
