//////////////////////////////////
/*   Ahmet Ramazan Çapoğlu      */
/*            150190080         */
//////////////////////////////////
#include <iostream>
#include <cstdio>
#include "GreatWarrior.h"

using namespace std;

Land::Land(const string & name_ptr, const string& holding_ptr) : name(name_ptr), holding(holding_ptr)
{
    next = NULL;
}
Land::Land(const Land &object_in){
    name = object_in.name;
    holding = object_in.holding;
    next= new Land(); //burada gelen objenin next pointerını nasıl geçireceğimizi düşünmemiz lazım
    *next = *(object_in.next); //?
}
Land::~Land(){
   
    //delete next;
    //gerekli mi emin değilim
} 

Character::Character(const string & name_ptr, int manpower_par, int gold_par, int numOflands_par) : name(name_ptr), 
manpower(manpower_par), gold(gold_par), numOfLands(numOflands_par)
{
    lands = new Land(); 
}
Character::~Character(){ //emin degilim
    
    //delete lands;
   /* for (int i=0; i<numOfLands;i++){
        cout<<"for ici"<<endl;
        if(numOfLands==5){
            cout << "5 ici" << endl;
            removeLand(*(lands->next->next->next->next));
            removeLand(*(lands->next->next->next));
            removeLand(*(lands->next->next));
            removeLand(*(lands->next));
            removeLand(*(lands));
        break;
        }
        else if(numOfLands==3){
            removeLand(*(lands->next->next));
            removeLand(*(lands->next));
            removeLand(*(lands));

        }
        else if(numOfLands==4){
            removeLand(*(lands->next->next->next));
            removeLand(*(lands->next->next));
            removeLand(*(lands->next));
            removeLand(*(lands));

        }
        else if(numOfLands==2){
            removeLand(*(lands->next));
            removeLand(*(lands));

        }
        else if(numOfLands==1){
            removeLand(*(lands));
        }
    }*/
   // Land* traverse = lands;
   // while(traverse !=NULL){
     //   removeLand(*traverse);
      //  traverse = traverse->getNext();
  //  }
    
    
    
}
Character::Character(const Character &object_in){
    name = object_in.name;
    manpower = object_in.manpower;
    gold = object_in.gold;
    numOfLands = object_in.numOfLands;
    lands = new Land();
    *lands = *(object_in.lands); // is it true?
}

CharacterList::CharacterList(int size_ptr): size(size_ptr){
    characters = new Character[size];
}
CharacterList::~CharacterList(){
   
    delete[] characters;
}

void Character::addLand(Land & object){
    Land* new_land = new Land();
    new_land->name = object.name;
    new_land->holding = object.holding;
    new_land->next = NULL;  

    Land * last = lands;
    if ((lands->name == "" )|| (lands->holding == "" )){  
        lands= new_land;  
        numOfLands++;
        return;  
    }  
    while (last->next != NULL) { 
        last = last->next;  
    }
    last->next = new_land;
    numOfLands++;
    return;
}

void Character::removeLand(Land & object){
    //kontrol et ama dogru gibi
    Land * temporary = lands;
    Land * prev = NULL;
    
    if ((temporary != NULL) && (temporary->getName() == object.getName()) /*&& temporary->holding == object.holding bunu silince bir hata gitti*/){   
        lands = temporary->next; // Changed head
        delete temporary;          // free old head
        numOfLands--;
        return;
    }
    else{
        while (temporary != NULL && temporary->name != object.name /*&& temporary->holding != object.holding */){
            prev = temporary;
            temporary = temporary->next;
        }
        if (temporary == NULL){
            return;
        }
        prev->next = temporary->next;
        delete temporary;
        numOfLands--;
    }
}
void Character::getTaxes(){//emin degilim
    Land * traverse = lands;
    while(traverse != NULL){
        if(traverse->holding == "village")
            gold += 5;
        else if(traverse->holding == "castle")
            gold += 7;
        else{
            gold += 10;
        }
        traverse = traverse->next;
    }
}

void CharacterList::addCharacter(Character & new_character){//emin degilim nasil oluyor iyice bak
                                                            //ifli bir şey koyup size ayarlayabilirsin belki bir boşluk olmaz
    characters[size - 1] = new_character;
    Character * temp = new Character[size+1];
    //temp[size - 1] = new_character;

    //copy(characters, characters + min(size , size+1), temp);
    for(int i = 0; i < size; i++){
       temp[i]= characters[i];
    }
    delete[] characters;
    characters = temp;
    size++;
}

void CharacterList::delCharacter(Character & del_character){
    int i;
    
    for (i=0; i<size; i++){
        if (characters[i].getName() == del_character.getName()) //ayni isimde karakter olursa calismaz
            break;
    }
   // If x found in array
   if (i < size)
   {
     // reduce size of array and move all
     // elements on space ahead
     size = size - 1;
     
     for (int j=i; j<size; j++)
        characters[j] = characters[j+1];
   }
}

Character& CharacterList::getLandOwner(string & land_name){
   for(int i = 0; i < size - 1; i++){ // iterator'e bak
        Land * forloop = characters[i].getLands();
         while (forloop != NULL){
        if (forloop->getName()== land_name){return characters[i];}

            forloop = forloop->getNext();
        }
        
       
    }
    return characters[size -1]; // bu null sanırım yani yanlış bir şey girersen hata verebilir

}

Character& CharacterList::getPlayer(int i){
  return characters[i];
}
