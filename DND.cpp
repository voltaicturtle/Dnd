/*
  Filename   : DND.cpp
  Author     : Ian Martin
  Last Updated: 2/22/22
  Assignment : N/A
  Description: Array class, our implementation of a list ADT 
                 with random access and dynamic resizing.

		 With templated class we often include the
		 implementation of the class in the header
		 file. In these cases we use the extension
		 ".hpp". 
*/   
//includes/usings
#include <iostream>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <time.h>
using std::setw;
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::time_t;
//*************************************
  //class variables
  int fix = 1;
  int count = 0;
//*************************************

//rolls a die of given number of sides
int
roll(int sides)
{
  return std::rand() % sides + 1;
}

//rolls a stat line by rolling 4d6 and dropping the lowest
int
rollStat()
{
  int d1;
  int d2;
  int d3;
  int d4;
  d1 = roll(6);
  d2 = roll(6);
  d3 = roll(6);
  d4 = roll(6);

if (d1<= d2 && d1<= d3 && d1<= d4)
    return d2 + d3 + d4;

if (d2<= d1 && d2<= d3 && d2<= d4)
    return d1 + d3 + d4;

if (d3<= d1 && d3<= d2 && d3<= d4)
    return d1 + d2 + d4;

  return d1 + d3 + d2;
}
//rolls a dnd stat table for bingo method
void
rollTable()
{
  int A[6][6];
  for (int i =0; i <= 5; ++i)
  {
    
    for (int j = 0; j <= 5; ++j)
      A[i][j] = rollStat();
    
    fix*=3;
  }
  cout << "\nD 1  2  3  4  5  6  D2\n";
  cout << "a " << setw(2) << A[0][0] << " " << setw(2) << A[1][0] << " " << setw(2) << A[2][0] << " " << setw(2) << A[3][0] << " " << setw(2) << A[4][0] << " " << setw(2) << A[5][0] << " " << endl;
  cout << "b " << setw(2) << A[0][1] << " " << setw(2) << A[1][1] << " " << setw(2) << A[2][1] << " " << setw(2) << A[3][1] << " " << setw(2) << A[4][1] << " " << setw(2) << A[5][1] << " " << endl;
  cout << "c " << setw(2) << A[0][2] << " " << setw(2) << A[1][2] << " " << setw(2) << A[2][2] << " " << setw(2) << A[3][2] << " " << setw(2) << A[4][2] << " " << setw(2) << A[5][2] << " " << endl;
  cout << "d " << setw(2) << A[0][3] << " " << setw(2) << A[1][3] << " " << setw(2) << A[2][3] << " " << setw(2) << A[3][3] << " " << setw(2) << A[4][3] << " " << setw(2) << A[5][3] << " " << endl;
  cout << "e " << setw(2) << A[0][4] << " " << setw(2) << A[1][4] << " " << setw(2) << A[2][4] << " " << setw(2) << A[3][4] << " " << setw(2) << A[4][4] << " " << setw(2) << A[5][4] << " " << endl;
  cout << "f " << setw(2) << A[0][5] << " " << setw(2) << A[1][5] << " " << setw(2) << A[2][5] << " " << setw(2) << A[3][5] << " " << setw(2) << A[4][5] << " " << setw(2) << A[5][5] << " " << endl;
}
//simulates a pair flair stat line randomization
void
pairFlair()
{
  int A[12]= {4,4,5,5,6,6,7,7,8,8,9,9};
  int temp1 = 0;
  int temp2 = 0;
  int temp3 = 0;
  for (int i =0; i < 7823; ++i)
  {
    temp1 = std::rand() % 12;
    temp2 = std::rand() % 12;
    temp3 = A[temp1];
    A[temp1] = A[temp2];
    A[temp2] = temp3;
  }
  int A2[6] = {A[0] + A[1], A[2] + A[3], A[4] + A[5], A[6] + A[7], A[8] + A[9], A[10] + A[11]};
  
  for (int i=0; i < 6; ++i)
    cout << A2[i] << " ";
}
//prints the start message
int
start()
{
  std::srand(time(NULL));
  cout << "Welcome, to my dnd app input the number of what you want to happen\n";
  cout << "1: roll table\n";
  cout << "2: roll single stat line\n";
  cout << "3: roll a single die\n";
  cout << "4: stats by pair flair\n";
  int input;
  cin >> input;
  return input;
}
int 
main()
{
  int response = start();
  if(response == 1)
    rollTable();
  if(response == 2)
    cout << rollStat() << " " << rollStat() << " " << rollStat() << " " << rollStat() << " " << rollStat() << " " << rollStat();
  if(response == 3)
  {
     cout << "how many dice\n";
     int number;
     cin >> number;
     cout << "how many sides\n";
     int sides;
     cin >> sides;
     int cum = 0;
     for (int i = 0; i < number; ++i)
     {
       int rolled = roll(sides);
       cout << rolled << "\n";
       cum += rolled;
     }
    cout << cum << "\n";
  }
  if(response == 4)
    pairFlair();
   
  if(response == 5)
  {
    for(size_t temp = 0; temp < 1000000000; ++temp)
    {
      int one = roll(4);
      int two = roll(4);
      int three = roll(4);
      int four = roll(4);
      if (one == 1 && one == two && one == three && one == four)
      ++count;
    }
    cout << count;
  }
}