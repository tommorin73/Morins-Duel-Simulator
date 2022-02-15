/*Thomas Morin
 *FILE NAME: project2_Morin_twm0023.cpp
 * AUTHOR: Thomas Morin
 * Sources: I used the project 2 hints to get a general idea od the program's layout.
 *          I also used StackOverflow to better understand boolean functions and test cases in C++.
*/

#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <ctime>

using namespace std;

/*
* GIVEN (HINTS)
* Input: A_alive indicates Aaron is alive true for alive, false for dead
* B_alive indicates Bob is alive
* C_alive indicates Charlie is alive
* Return: true if at least two are alive otherwise return false
*/

bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive);

/*
* GIVEN (HINTS)
* Call by reference
* Strategy 1: Everyone shoots to kill the highest accuracy player alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/

void Aaron_shoots1(bool& B_alive, bool& C_alive);

/*
* GIVEN (HINTS)
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* C_alive indicates Charlie is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change C_alive into false if Charlie is killed
*/

void Bob_shoots(bool& A_alive, bool& C_alive);

/*
* GIVEN (HINTS)
* Call by reference
* Input: A_alive indicates Aaron is alive or dead
* B_alive indicates Bob is alive or dead
* Return: Change A_alive into false if Aaron is killed
* Change B_alive into false if Bob is killed
*/

void Charlie_shoots(bool& A_alive, bool& B_alive);

/*
* GIVEN (HINTS)
* Call by reference
* Strategy 2: Aaron intentionally misses if both are alive
* Input: B_alive indicates Bob is alive or dead
* C_alive indicates Aaron is alive or dead
* Return: Change B_alive into false if Bob is killed
* Change C_alive into false if Charlie is killed
*/

void Aaron_shoots2(bool& B_alive, bool& C_alive);

//Simple method to implement pause function in linux (GIVEN HINTS)

void Press_any_key(void);

//TEST PROTOTYPES (GIVEN HINTS)

void test_at_least_two_alive(void);
void test_Aaron_shoots1(void);
void test_Bob_shoots(void);
void test_Charlie_shoots(void);
void test_Aaron_shoots2(void);

//Variables

const int A_acc = 33;
const int B_acc = 50;
const int C_acc = 100;
const int TOTAL_RUNS = 10000; //Given in Proj2 Hints.
bool aaronAlive = true; //Given in Proj2 Hints.
bool bobAlive = true; //Given in Proj2 Hints.
bool charlieAlive = true; //Given in Proj2 Hints.
int aaronWins1 = 0; //Given in Proj2 Hints
int bobWins = 0; //Given in Proj2 Hints
int charlieWins = 0; //Given in Proj2 Hints
int aaronWins2 = 0; //Given in Proj2 Hints

//GIVEN (HINTS)

int main() {

   cout << "*** Welcome to Morin's Duel Simulator ***\n";
   
   srand(time(0));
   
   test_at_least_two_alive();
   Press_any_key();
   
   test_Aaron_shoots1();
   Press_any_key();
   
   test_Bob_shoots();
   Press_any_key();
   
   test_Charlie_shoots();
   Press_any_key();
   
   test_Aaron_shoots2();
   Press_any_key();
	
	//Starts strategy 1 and runs 10,000 times
   
   cout << "Ready to test strategy 1 (run 10000 times):\n";
   
   Press_any_key();
   
   for (int i = 0; i < TOTAL_RUNS; i++ ){
   
   //Assume they all start out alive.
   
      charlieAlive = true;
      bobAlive = true;
      aaronAlive = true;
      
      //GIVEN (HINTS)
      
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
      
      //Aaron shoots first.
      
         if (aaronAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Aaron_shoots1(bobAlive, charlieAlive); }
         
         //Assuming Bob is alive, he shoots.
         
         if (bobAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Bob_shoots(aaronAlive, charlieAlive); }
         
         //Assuming Charlie is alive, he shoots last.
         
         if (charlieAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Charlie_shoots(aaronAlive, bobAlive); }
      }
      
      //Determining who is still alive (who won).
      
      if (aaronAlive) 
         aaronWins1++;
         
      if (bobAlive) 
         bobWins++;
         
      if (charlieAlive) 
         charlieWins++; }
   
   //Displays the total number of wins per person as a number and a percentage. (GIVEN (HINTS))
   
   cout << "Aaron won " << aaronWins1 << "/10000 duels or " << static_cast<double>(aaronWins1) / TOTAL_RUNS * 100 << "%\n"
        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
        << endl;
	
	//Reinitializes variables and starts strategy 2 to run 10,000 times      
   
   //Sets time and wins back to zero to run strategy 2.
   
   srand(time(0));
   aaronWins2 = 0;
   bobWins = 0;
   charlieWins = 0;
   
   //GIVEN (HINTS)
   
   cout << "Ready to test strategy 2 (run 10000 times):\n";
   Press_any_key();
   for (int i = 0; i < TOTAL_RUNS; i++ ){
   
   //Assumes all three start alive.
   
      charlieAlive = true;
      bobAlive = true;
      aaronAlive = true;
      
      
      while (at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
      
      //Aaron shoots first.
      
         if (aaronAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Aaron_shoots2(bobAlive, charlieAlive); }
         
         //Assuming he's still alive, Bob shoots next.
         
         if (bobAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Bob_shoots(aaronAlive, charlieAlive); }
         
         //Assuming he's still alive, Charlie shoots last.
         
         if (charlieAlive && at_least_two_alive(aaronAlive, bobAlive, charlieAlive)) {
            Charlie_shoots(aaronAlive, bobAlive); }
      }
      
      //Determines who wins strategy 2 based off of who is still alive at the end.
      
      if (aaronAlive) 
         aaronWins2++;
         
      if (bobAlive) 
         bobWins++;
         
      if (charlieAlive) 
         charlieWins++; }
   
   //Displays strategy  2 results (GIVEN(HINTS))
   
   cout << "Aaron won " << aaronWins2 << "/10000 duels or " << static_cast<double>(aaronWins2) / TOTAL_RUNS * 100 << "%\n"
        << "Bob won " << bobWins << "/10000 duels or " << static_cast<double>(bobWins) / TOTAL_RUNS * 100 << "%\n"
        << "Charlie won " << charlieWins << "/10000 duels or " << static_cast<double>(charlieWins) / TOTAL_RUNS * 100 << "%\n"
        << endl;
	
   //Determins whether Aaron won more duels using strategy 1 or 2.
   
   
   if (aaronWins1 > aaronWins2) {
      cout << "Strategy 1 is better than strategy 2.\n"; }
      
   else {
      cout << "Strategy 2 is better than strategy 1.\n"; }
	
   return 0; }


bool at_least_two_alive(bool A_alive, bool B_alive, bool C_alive) {

   if (A_alive && B_alive)
      return true;
      
   if (B_alive && C_alive) 
      return true;
      
   if (A_alive && C_alive)
      return true;
      
      //If none of the above are true.
      
   return false; }



void test_at_least_two_alive(void) {
   cout << "Unit Testing 1: Function - at_least_two_alive()\n";
	
//Asserts that all three are still alive.
   
   cout << "\tCase 1: Aaron alive, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(true, true, true));
   cout << "\tCase passed ...\n";
	
//Aaron dead.
   
   cout << "\tCase 2: Aaron dead, Bob alive, Charlie alive\n";
   assert(true == at_least_two_alive(false, true, true));
   cout << "\tCase passed ...\n";
	
//Bob Dead
   
   cout << "\tCase 3: Aaron alive, Bob dead, Charlie alive\n";
   assert(true == at_least_two_alive(true, false, true));
   cout << "\tCase passed ...\n";

//Charlie dead.

   cout << "\tCase 4: Aaron alive, Bob alive, Charlie dead\n";
   assert(true == at_least_two_alive(true, true, false));
   cout << "\tCase passed ...\n";

//Aaron and Bob dead.

   cout << "\tCase 5: Aaron dead, Bob dead, Charlie alive\n";
   assert(false == at_least_two_alive(false, false, true));
   cout << "\tCase passed ...\n";
	
//Aaron and Charlie dead.
   
   cout << "\tCase 6: Aaron dead, Bob alive, Charlie dead\n";
   assert(false == at_least_two_alive(false, true, false));
   cout << "\tCase passed ...\n";

//Bob and Charlie dead.

   cout << "\tCase 7: Aaron alive, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(true, false, false));
   cout << "\tCase passed ...\n";
	
//All dead.
   
   cout << "\tCase 8: Aaron dead, Bob dead, Charlie dead\n";
   assert(false == at_least_two_alive(false, false, false));
   cout << "\tCase passed ...\n"; }



void Aaron_shoots1(bool& B_alive, bool& C_alive) {

//Asserts that B&C are alive.

   assert(B_alive || C_alive);
   
   int shootResult = rand() % 100;
   
   if (C_alive) {
      if (shootResult <= A_acc) {
         C_alive = false;}
   }
   
   else {
      if (shootResult <= A_acc) {
         B_alive = false;}
   }
}



void test_Aaron_shoots1(void) {
   cout << "Unit Testing 2: Function Aaron_shoots1(Bob_alive, Charlie_alive)\n";
	
   bool bob_a = true;
   bool charlie_a = true;
   cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
        
   Aaron_shoots1(bob_a, charlie_a);
	
   //GIVEN(HINTS)
   
   bob_a = false;
   charlie_a = true;
   cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
   Aaron_shoots1(bob_a, charlie_a);

//GIVEN(HINTS)

   bob_a = true;
   charlie_a = false;
   cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
   Aaron_shoots1(bob_a, charlie_a); }

//Same setup as before.

void Bob_shoots(bool& A_alive, bool& C_alive) {
   assert(A_alive || C_alive);
   int shootResult = rand() % 100;
   if (C_alive) {
      if (shootResult <= B_acc) {
         C_alive = false; }
   }
   else {
      if (shootResult <= B_acc) {
         A_alive = false; }
   }
}

void test_Bob_shoots(void) {

   cout << "Unit Testing 3: Function Bob_shoots(Aaron_alive, Charlie_alive)\n";

   bool aaron_a = true;
   bool charlie_a = true;
   
   cout << "\tCase 1: Aaron alive, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
        
   Bob_shoots(aaron_a, charlie_a);

   aaron_a = false; //Dead
   charlie_a = true; //Alive
   
   cout << "\tCase 2: Aaron dead, Charlie alive\n"
        << "\t\tBob is shooting at Charlie\n";
        
   Bob_shoots(aaron_a, charlie_a);
	
   aaron_a = true; //Alive
   charlie_a = false; //Dead
   
   cout << "\tCase 3: Aaron alive, Charlie dead\n"
        << "\t\tBob is shooting at Aaron\n";
        
   Bob_shoots(aaron_a, charlie_a); }
	
   
   
void Charlie_shoots(bool& A_alive, bool& B_alive) {
   assert(A_alive || B_alive);
   int shootResult = rand() % 100;
   if (B_alive) {
      B_alive = false; //Dead
   }
   else {
      A_alive = false; //Dead
   }
}



void test_Charlie_shoots(void) {
   cout << "Unit Testing 4: Function Charlie_shoots(Aaron_alive, Bob_alive)\n";

   bool aaron_a = true; //Alive
   bool bob_a = true; //Alive
   
   cout << "\tCase 1: Aaron alive, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";
        
   Charlie_shoots(aaron_a, bob_a);

   aaron_a = false; //Dead
   bob_a = true; //Alive
   
   cout << "\tCase 2: Aaron dead, Bob alive\n"
        << "\t\tCharlie is shooting at Bob\n";
        
   Charlie_shoots(aaron_a, bob_a);
	
   aaron_a = true; //Alive
   bob_a = false; //Dead
   
   cout << "\tCase 3: Aaron alive, Bob dead\n"
        << "\t\tCharlie is shooting at Aaron\n";
        
   Charlie_shoots(aaron_a, bob_a); }
   
   

void Aaron_shoots2(bool& B_alive, bool& C_alive) {

   int shootResult = rand() % 100;
   
   if (C_alive && !B_alive) {
      if (shootResult <= A_acc) {
         C_alive = false; }
   }
   if (B_alive && !C_alive) {
      if (shootResult <= A_acc) {
         B_alive = false; }
   }
}

void test_Aaron_shoots2(void) {
   cout << "Unit Testing 5: Function Aaron_shoots2(Bob_alive, Charlie_alive)\n";
	
   bool bob_a = true; //Alive
   bool charlie_a = true; //Alive
   
   cout << "\tCase 1: Bob alive, Charlie alive\n"
        << "\t\tAaron intentionally misses his first shot\n\t\tBoth Bob and Charlie are alive.\n";
        
   Aaron_shoots2(bob_a, charlie_a);
	
   bob_a = false; //Dead
   charlie_a = true; //True
   
   cout << "\tCase 2: Bob dead, Charlie alive\n"
        << "\t\tAaron is shooting at Charlie\n";
        
   Aaron_shoots2(bob_a, charlie_a);

   bob_a = true; //Alive
   charlie_a = false; //Dead
   
   cout << "\tCase 3: Bob alive, Charlie dead\n"
        << "\t\tAaron is shooting at Bob\n";
        
   Aaron_shoots2(bob_a, charlie_a); }

//GIVEN(HINTS)

void Press_any_key(void) {
   cout << "Press any key to continue...";
   cin.ignore().get();  }
