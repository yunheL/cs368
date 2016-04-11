#include <iostream>
#include <vector>
using namespace std;

enum Suits         { clubs, diamonds, hearts, spades };
enum FaceCardRanks { jack = 11, queen = 12, king = 13, ace = 1 };

struct Card {
    Suits suit;
    int rank;
};

// PASS BY CONST-REFERENCE (this causes a compiler error)
// not allowed to change the data members of a const object
// that is passed by reference
void setCard( const Card &c ) {
 //    c.suit = hearts ;  // set the card in the calling function to hearts
 //    c.rank = queen;  // set the card in the calling function to queen
     cout << c.suit << " " << c.rank << endl;
}

void printCard(Card c) {

    switch (c.rank) { 
        case 1:  cout << 'A'; break;
        case 11: cout << 'J'; break;
        case 12: cout << 'Q'; break;
        case 13: cout << 'K'; break;
        default: cout << c.rank; break;
     }
 
    switch (c.suit) { 
        case hearts:   cout << 'H'; break;
        case spades:   cout << 'S'; break;
        case clubs:    cout << 'C'; break;
        case diamonds: cout << 'D'; break;
    }
}

bool arraysAreEqual( int a[], int b[], int n ) {
    for ( int i=0; i < n ; i++ ) 
        if (a[i]!=b[i]) return false;
    return true;
}

int main() {

    //**********************************************
    // Create individual cards
    //**********************************************

    Card card1, card2, card3;

    card1.suit = hearts;
    card1.rank = 5;

    card2.suit = diamonds;
    card2.rank = jack;

    cout << "card1.suit is: " << card1.suit << "\ncard1.rank is: " << card1.rank << endl;

    cout << "card1 is: ";
    printCard(card1);
    cout << endl;

    cout << "card2.suit is: " << card2.suit << "\ncard2.rank is: " << card2.rank << endl;

    cout << "card2 is: ";
    printCard(card2);
    cout << endl;

    cout << "card3.suit is: " << card3.suit << "\ncard3.rank is: " << card3.rank << endl;

    cout << "card3 is: ";
    printCard(card3);
    cout << endl;

    //**********************************************
    // Create a deck of cards
    //**********************************************

    Card deck[4][13];

    // Fill it 
    for (int s = 0; s < 4; s++) {
        for (int val = 1; val <= 13; val++) {
            deck[s][val-1].suit = Suits(s);
            deck[s][val-1].rank = val;
        }  
    } 
	
    // Print it out
    cout << endl << "Printing 2-d array deck: " << endl;
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            printCard(deck[i][j]);
            cout << ", ";
        }
        cout << endl;
    }

    //**********************************************
    // Create a vector of cards
    //**********************************************

    vector<Card> deck2;

    // Fill it 
    for (int s = 0; s < 4; s++) {
        for (int val = 1; val <= 13; val++) {
            deck2.push_back(deck[s][val-1]);
        }  
    } 

    // Print it out
    cout << endl << "Printing vector deck: " << endl;
    for (int i = 0; i < 52; i++) {
         printCard(deck2[i]);
         cout << ", ";
    }
    cout << endl;


    //**********************************************
    // Test arrayAreEqual
    //**********************************************
    int n = 3;
    int a[n];
    int b[n];
    int c[n];
    for ( int i=0; i < n; i++ ) {
        a[i] = b[i] = i;
        c[i] = i+1;
    }
    bool results  = arraysAreEqual(a,b,n);
    cout << "results of arraysAreEqual(a,b,n) = " << (results? "true" : "false") << endl;
    results  = arraysAreEqual(a,c,n);
    cout << "results of arraysAreEqual(a,c,n) = " << (results? "true" : "false") << endl;

    Card* cardPtr ;
    cout << "cardPtr=" << cardPtr ;
    cardPtr = NULL;
    cout << " -- after assigned NULL cardPtr = " << cardPtr << endl;

    return 0; 
}
