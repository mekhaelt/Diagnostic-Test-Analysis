#include <iostream>
#include <cmath>
#include <cstdlib> 
using namespace std;


int main (const int argc, const char* argv[])
 {
    float TPR; //True positive rate
    float FPR; //False positive rate
    int i; //Value used to for error checking with characters
    int j; //Value used to for error checking with characters
    int counter = 0; //Diagnostic test counter
    float best = 0.0; //Best diagnostic test
    int c = 1; //keeps track of the number of the best diagnostic test
    int y; //variable that keeps track of when TPR <0
    int z; //variable that keeps track of when FPR <0



    do 
    {
      counter ++; //increases the counter for every test
      y=0; //Gives variable an initial value of 0 (will later be switched to 1 if TPR<0)
      z=0; //Gives variable an initial value of 0 (will later be switched to 1 if FPR<0)
      do 
      {
          cout << "Please enter the diagnostic test's true positive rate: ";
          cin >> TPR;  //input for true positive rate
          
          i = cin.good(); //checks if the input is a float value
          cin.clear(); //clears error flag on cin
          cin.ignore(100, '\n'); //skips to the next line, to prevent errors

          if (i==0) //Warning message if TPR isn't a float
          {
            cout << "Warning: invalid input to true positive rate. Please enter a numeric input." << endl;
          }

          if (TPR>1) //Warning message if TPR is too high
          {
            cout << "Warning: invalid input to true positive rate. Please enter an input <=1." << endl;
          }
      }

      while (TPR>1 || i == 0); //Keeps asking the user for the TPR if the input is not a float or >1

      if (TPR<0)
      {
          TPR = 0; //Makes TPR == 0 if the input is <0
          y=1; //Makes y == 1 if the input is <0
      }


      do 
      {
          
          cout << "Please enter the diagnostic test's false positive rate: ";
          cin >> FPR; //input for false positive rate
          j = cin.good(); //checks if the input is a float value
          cin.clear(); //clears error flag on cin
          cin.ignore(100, '\n'); //skips to the next line, to prevent errors

          if (j==0) //Warning message if FPR isn't a float
          {
            cout << "Warning: invalid input to false positive rate. Please enter a numeric input." << endl;
          }

          if (FPR>1) //Warning message if FPR is too high
          {
            cout << "Warning: invalid input to false positive rate. Please enter an input <=1." << endl;
          }
      
      }
      while (FPR>1 || j==0); //Keeps asking the user for the FPR if the input is not a float or >1

      if (FPR<0)
      {
          FPR = 0; //Makes FPR == 0 if the input is <0
          z=1; //Makes z == 1 if the input is <0
      }

      float score = 1-sqrt(pow(FPR, 2) + pow((1-TPR), 2)); //performs the actual calculations for the diagnostic test 

      if (y == 0 || z == 0) //Outputs message if TPR and FPR are >=0
      {
        cout << "The score for diagnostic test " << counter << " is " << score << endl;
      }

      if (score > best) //Replaces best score, and which test the best score took place if necessary
      {
        best = score;
        c = counter;
      }


    }
    while (y == 0 || z == 0); //ends loop if TPR and FPR are <0

    cout << endl << "Diagnostic test " << c << " has the best score of " << best << endl; //outputs the best score and which test it occurred on
    cout << "Exiting Program." << endl; //Outputs message
    return 0;


 }
