#ifndef SLOTMACHINE_H
#define SLOTMACHINE_H

#include<iostream>
#include <random>
#include <vector>
#include <string>



#include <string>
class SlotMachine
{

    private:
    const int max_lines =3;
  const int min_lines=1;
   double deposit;

  double balance;
  int lines;
  double bet;

   std:: string images[7] = {"Cherries", "Oranges", "Plums", "Bells", "Melons", "Bars" }; 
   typedef std::vector<std::vector<int>> Wheels; //3 x 3 matrix //one wheel is one column

    Wheels generateWheels();
   
    Wheels generated_wheels;
   
    int getLines();
    double checkWinnings(int );
    void printWinning();
    void printTheWheels();
    void setBet();
    void autoSpin();

    public:
    void startSlot();
    void setDeposit();
};
#endif




