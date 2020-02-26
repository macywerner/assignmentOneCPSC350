#include "File.h"
#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
  /*if (argc < 1) {
    cout << "INVALID USAGE: please provide a file." << endl;
    return 1; // error
  }*/
  File *file = new File();

  ifstream inFS;
  ofstream outFS;
  string fileData; //data of the file
  //string fName = argv[1]; //file name

  //cout << "Opening file: " << fName << endl;
  cout << "Opening file: " << endl;
  inFS.open(fName);
  //inFS.open("sampleInput.txt"); //testing purposes
  inFS >> fileData;
  outFS.open("macywerner.out");



  //if file does not exist or cannot be opened
  if(!inFS.is_open()){
    cout << "Could not open file: " << fName << endl;
    return 1; // error
  }
  /*while (!inFS.eof()){
    inFS >> fileData;
    return fileData;
  }*/



  //make variables
  int m_sum = file->sum(fileData);
  double m_mean = file->mean(fileData, m_sum);
  float m_variance = file->variance(fileData, m_mean);
  float m_sd = file->standardDeviation(m_variance);

  //find probability of each nucleotide
  float m_probOfA = file->probOfA(fileData);
  float m_probOfT = file->probOfT(fileData);
  float m_probOfC = file->probOfC(fileData);
  float m_probOfG = file->probOfG(fileData);

  //out file heading
  outFS << "Macy Werner " << endl;
  outFS << "Student ID: 2327782 " << endl;
  outFS << "CPSC350 - 01 " << endl;
  outFS << "Spring 2020 " << endl;

  //put calculations
  outFS << "Sum: " << m_sum << endl;
  outFS << "Mean: " << m_mean << endl;
  outFS << "Variance: " << m_variance << endl;
  outFS << "Standard Deviation: " << m_sd << endl;

  //print probability
  outFS << "Probability of A: " << m_probOfA << endl;
  outFS << "Probability of T: " << m_probOfT << endl;
  outFS << "Probability of C: " << m_probOfC << endl;
  outFS << "Probability of G: " << m_probOfG << endl;

  string bigram = "";
  int aa = 0;
  int at = 0;
  int ac = 0;
  int ag = 0;

  int tt = 0;
  int ta = 0;
  int tc = 0;
  int tg = 0;

  int cc = 0;
  int ca = 0;
  int ct = 0;
  int cg = 0;

  int gg = 0;
  int ga = 0;
  int gt = 0;
  int gc = 0;

  double allBigrams= 0;

  for(int i = 0; i < fileData.length()-2;i = i + 2);{
    for(int j = 1; j < fileData.length()-1; j = j + 2);{
      char one = tolower(fileData[i]);
      char two = tolower(fileData[j]);
      bigram = one + two;

      if (bigram == 'aa'){
        aa++;
        allBigrams ++;
      }else if (bigram == 'at'){
        at++;
        allBigrams ++;
      }else if (bigram == 'ac'){
        ac++;
        allBigrams ++;
      }else if (bigram == 'ag'){
        ag++;
        allBigrams ++;
      }else if (bigram == 'tt'){
        tt++;
        allBigrams ++;
      }else if (bigram == 'ta'){
        ta++;
        allBigrams ++;
      }else if (bigram == 'tc'){
        tc++;
        allBigrams ++;
      }else if (bigram == 'tg'){
        tg++;
        allBigrams ++;
      }else if (bigram == 'cc'){
        cc++;
        allBigrams ++;
      }else if (bigram == 'ca'){
        ca++;
        allBigrams ++;
      }else if (bigram == 'ct'){
        ct++;
        allBigrams ++;
      }else if (bigram == 'cg'){
        cg++;
        allBigrams ++;
      }else if (bigram == 'gg'){
        gg++;
        allBigrams ++;
      }else if (bigram == 'ga'){
        ga++;
        allBigrams ++;
      }else if (bigram == 'gt'){
        gt++;
        allBigrams ++;
      }else if (bigram == 'gc'){
        gc++;
        allBigrams ++;
      }

    }
    float m_AA = aa / allBigrams;
    float m_AT = at / allBigrams;
    float m_AC = ac / allBigrams;
    float m_AG = ag / allBigrams;

    float m_TT = tt / allBigrams;
    float m_TA = ta / allBigrams;
    float m_TC = tc / allBigrams;
    float m_TG = tg / allBigrams;

    float m_CC = cc / allBigrams;
    float m_CA = ca / allBigrams;
    float m_CT = ct / allBigrams;
    float m_CG = cg / allBigrams;

    float m_GG = gg / allBigrams;
    float m_GA = ga / allBigrams;
    float m_GT = gt / allBigrams;
    float m_GC = gc / allBigrams;

    outFS << "Probabilities of each bigram: ";
    outFS << "AA: " << m_AA << endl;
    outFS << "AT: " << m_AT << endl;
    outFS << "AC: " << m_AC << endl;
    outFS << "AG: " << m_AG << endl;

    outFS << "TT: " << m_TT << endl;
    outFS << "TA: " << m_TA << endl;
    outFS << "TC: " << m_TC << endl;
    outFS << "TG: " << m_TG << endl;

    outFS << "CC: " << m_CC << endl;
    outFS << "CA: " << m_CA << endl;
    outFS << "CT: " << m_CT << endl;
    outFS << "CG: " << m_CG << endl;

    outFS << "GG: " << m_GG << endl;
    outFS << "GA: " << m_GA << endl;
    outFS << "GT: " << m_GT << endl;
    outFS << "GC: " << m_GC << endl;
  }


  int newLines = 0;

  for(int i = 0; i < 1000; ++i){
    outFS << file->newDNA(m_mean, m_sd, m_probOfA, m_probOfT, m_probOfC, m_probOfG);
  }

  cout << "File successfully processed." << endl;

  //cout << "Would you like to process another file? (y/n) ";
  //cin >> answer;

  delete file;

  inFS.close(); // Done with file, so close it
  outFS.close();

  return 0;

}
