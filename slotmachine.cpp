#include "slotmachine.h"



void SlotMachine::setDeposit()
{
  int deposit__;
    std::cout<<"Set deposit ";
    std::cin>>deposit__;
    this->deposit = deposit__;
    this->balance = deposit__;
}



SlotMachine::Wheels SlotMachine::generateWheels()
{
      std:: srand((unsigned int)time(NULL));
    const int size = 3;
  Wheels wheels (3,std::vector<int>(3));
    for (int i=0;i<3;i++)
        {
          for (int j=0;j<3;j++)
          {
            wheels[i][j] = std::rand() % 6;              
        }        
}
return wheels;
}

double SlotMachine::checkWinnings(int line__)
{
double won=0;
int first_num = generated_wheels[line__][0];

//std:: string images[7] = {"Cherries", "Oranges", "Plums", "Bells", "Melons", "Bars" }; 

if (generated_wheels[line__][0] == 5 and generated_wheels[line__][1] == 5) //bars bars any 
    {  won+=(this->bet/this->lines)*2.45; }

  if (generated_wheels[line__][0] == 5 and generated_wheels[line__][2]==5) //bars any bars
  {
    won+=(this->bet/this->lines) * 2.25;
  }
    if (generated_wheels[line__][0] == 0 and generated_wheels[line__][1] == 0) //cherries cherries any 
    { 
      won+=(this->bet/this->lines)*1.34;
       }
     if (generated_wheels[line__][0] == 1 and generated_wheels[line__][1] == 1) //oranges oranges any 
    { 
      won+= this->bet * 2.5;
    }
      if (generated_wheels[line__][0] == 2 and generated_wheels[line__][1] == 2) //plums plums any 
    { 
      won+=(this->bet/this->lines)*1.55;
    }
      if (generated_wheels[line__][0] == 3 and generated_wheels[line__][1] == 3) //bells bells any 
    { 
      won+=(this->bet/this->lines)*2.75;
    }
       if (generated_wheels[line__][0] == 4 and generated_wheels[line__][1] == 4) //mellons mellons any 
    { 
      won+=(this->bet/this->lines)*0.85;
    }
  
bool all_same=true;
for (int i=1;i<3;i++)
{
  if (generated_wheels[line__][i] != first_num)
      all_same=false;

}
 
if (all_same) // all same
{

  if(first_num==0) //all cherries
  {
    won+=(this->bet/this->lines)*5;
  }
  if (first_num==1) // all oranges
{
won+=(this->bet/this->lines)*5;
}
  if (first_num==2) // all plums
{
won+=(this->bet/this->lines)*5;
}
  if (first_num==3) // all bells
{
won+=(this->bet/this->lines)*5;
}
  if (first_num==3) // all melons
{
won+=(this->bet/this->lines)*5;
}
  if (first_num==3) // all bars
{
won+=(this->bet/this->lines)*5;
}
}
if (won>0)
  std::cout<<"\nCombination on line "<<line__ + 1;

return won;
}

void SlotMachine::printWinning()
{
   double won=0;

if (this->lines==1)
{
  won+=checkWinnings(1); //Second line --> index = 1
}
if (this->lines==2)
{
  won+=checkWinnings(0); //first line --> index = 0
  won+=checkWinnings(1);
}
if (this->lines==3)
{
  won+=checkWinnings(0); //first line --> index = 0
  won+=checkWinnings(1);
  won+=checkWinnings(2); //third line --> index = 2
  
}
  this->balance+=won;
   std::cout<<"\nWon "<<won;
   std::cout<<"\nCurrent balance "<<this->balance;
  }


void SlotMachine::printTheWheels()  
{
    
    this->generated_wheels = generateWheels();
  
    std::cout<<"--------------\n";
  for (int i=0;i<3;i++)
  {
    for (int j=0;j<3;j++)
    {
     std::cout<<images[generated_wheels[i][j]]<<" "; //translates numbers into strings
    }
    std::cout<<"\n";
  }
printWinning();

}

int SlotMachine::getLines()
{
  
  int lines;
  std::cout<<"\nNumber of lines (between 1 and 3): ";
  std::cin>>lines;

  while (lines<this->min_lines or lines>this->max_lines)
  {
      std::cout<<"\nBetween 1 and 3: ";
  std::cin>>lines;
  if (lines >= this->min_lines and lines<=this->max_lines)
      break;

  }
  return lines;
}

void SlotMachine::autoSpin()
{
  
  setBet();

  char continue_to_spin;
  while (continue_to_spin != 'N' and this->bet<=this->balance )
  {
  this->balance-=this->bet;
  printTheWheels();

  std::cout<<"\n\nContinue to spin (Y or N) ";
  std::cin>>continue_to_spin;
  std::cout<<"\n";
  if (continue_to_spin =='N' or this->bet>this->balance)
    break;
  }

}
void SlotMachine::startSlot()
{
char continue_to_spin;
int choice;
std::cout<<"1. Auto spin\n";
std::cout<<"2. Manually\n";
std::cin>>choice;
if (choice == 1)
autoSpin();

if (choice==2)
{
while (continue_to_spin!='N')
{
  std::cout<<"\nSpin: (Y or N) ";
  std::cin>>continue_to_spin;
  std::cout<<"\n";
  if (continue_to_spin!='N')
  { 
    setBet();
    this->balance-=this->bet;
    printTheWheels();
  }
   if (continue_to_spin == 'N')
    {
      break;
    }
}
}
}
void SlotMachine::setBet()
{

    int bet;
    int total_bet;

     std::cout<<"Place your bet: ";
  std::cin>>bet;
    this->lines = getLines();
  total_bet = bet*this->lines;

  if (total_bet<=this->balance)
  {
    std::cout<<"Your bet is "<<bet*this->lines<<"\n\n";

  this->bet = total_bet;
  }
  while (total_bet>this->balance and balance!=0)
  { 
    std::cout<<"Bet is larger than current balance "<< this->balance<<"\n";
      std::cout<<"Place your bet: ";
  std::cin>>bet;
  this->lines=getLines();
    total_bet = bet*this->lines;

  if (total_bet<=this->balance)
    {
std::cout<<"Your bet is "<<total_bet<<"\n\n";
    this->bet = total_bet;
  break;
    }
  }
}

