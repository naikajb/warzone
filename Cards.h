#include <iostream>
#include <string>
#include <vector>

#ifndef CARDS_H
#define CARDS_H

using namespace std;

class Hand;
class Deck;

class Card {
    public:
        enum CardType {BOMB, REINFORCEMENT, BLOCKADE, AIRLIFT, NEGOTIATE };
        
        //Card constructor that takes type 
        Card(CardType type);
        string getCardType() const;
        
        //This method will be called when the card is played
        void play(int index, Hand& hand, Deck& deck);
        
        //required for the shuffle method in the Deck class
        bool operator==(const Card& other) const;

        // Destructor to free allocated memory
        ~Card();

        // Copy constructor
        Card(const Card& other);

        //output stream operator
        friend ostream& operator<<(ostream& out, const Card& card);

        
    private:
        CardType* type; 

};

class Deck {
    public:
        Deck();
        ~Deck();
        Deck(const Deck& other);
        Card* draw();
        void returnCardToDeck(Card* card);
        void displayDeck();
        vector<Card *> getCardsInDeck();
        friend ostream& operator<<(ostream& out, const Deck& deck);
    private:
        //Arraylist equivalent in C++ that represents the deck of cards
        vector<Card*> cardsInDeck; 

};

class Hand {
    public:
        Hand();
        ~Hand();
        Hand(const Hand& other);
        void addCard(Card* card);
        friend ostream& operator<<(ostream& out, const Hand& hand);
        //Creates an order & returns it to the player's 
        //list of orders and then returns the card to the deck 
        void displayHand();
        vector <Card*> getCardsHand();// added
        //Arraylist equivalent in C++ that represents the hand of cards
        vector<Card*> cardsInHand; 

};

#endif