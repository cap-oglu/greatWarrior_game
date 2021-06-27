//////////////////////////////////
/*   Ahmet Ramazan Çapoğlu      */
/*            150190080         */
//////////////////////////////////
#include <iostream>
#include <cstdio>


//some important notes about code, i started characters array in charList as size 1 so at the end it has 1 empty character
using namespace std;
class Land{
    friend class Character;
     private:
        string name;
        string holding;
        Land * next;
     public:
        Land(const string& = "", const string& ="");
        Land(const Land &);
        ~Land();
        void setName(const string& setname){name = setname;};
        string getName(){return name;};
        string getHolding(){return holding;};
        Land * getNext(){return next;};
        
        void setHolding(const string& setholding){holding= setholding;};
        //void setNext(Land * nextone){next = nextone;};

};

class Character{
    friend class Characterlist;
    private:
        string name;
        int manpower;
        int gold;
        int numOfLands;
        Land * lands;
    public:
        Character(const string& = "",int = 0,int = 0,int = 0);
        Character(const Character &);
        ~Character();
        void setName(string& setname){name = setname;};
        void setManpower(int setmanpower){manpower = setmanpower;};
        void setGold(int setgold){gold = setgold;};
        void setNumOfLands(int setnumoflands){numOfLands = setnumoflands;};
        int getManpower(){return manpower;};
        int getGold(){return gold;};
        string getName() const{return name;};
        Land* getLands(){return lands;};
        int getNumOfLands(){return numOfLands;};
        void getTaxes(); //int mi olcak emin degilim
        void addLand(Land & object);
        void removeLand(Land & object);
};

class CharacterList{
    private:
        int size;
        Character * characters;
        friend void listCharacters(CharacterList&);    
        friend void listLands(CharacterList&);
    public:
        CharacterList(int size = 1);
        ~CharacterList();
        void addCharacter(Character&);
        void delCharacter(Character&);
        Character & getPlayer(int);
        int getSize(){return size;};
        Character & getLandOwner(string &);
};
