#include <iostream>
#include <windows.h>
using namespace std;

//інтерфейс
class WeaponBehavior{
public:
    virtual void useWeapon() = 0;
    virtual ~WeaponBehavior(){}
};

//зброя
class KnifeBehavior : public WeaponBehavior{
public:
    void useWeapon() override{
        cout << "Наносить удар ножем" << "\n";
    }
};

class SwordBehavior : public WeaponBehavior{
public:
    void useWeapon() override{
        cout << "Махає мечем" << "\n";
    }
};

class AxeBehavior : public WeaponBehavior{
public:
    void useWeapon() override{
        cout << "Рубає сокирою" << "\n";
    }
};

class BowAndArrowBehavior : public WeaponBehavior{
public:
    void useWeapon() override{
        cout << "Стріляє з лука" << "\n";
    }
};

//абстрактний клас
class Character{
protected:
    WeaponBehavior *weapon;
public:
    Character() : weapon(nullptr){}
    virtual ~Character(){}
    void setWeapon(WeaponBehavior *w){
        weapon = w;
    }
    virtual void fight() = 0;
};

//персонажі
class King : public Character{
public:
    void fight() override{
        cout << "Король: ";
        if(weapon)weapon -> useWeapon();
        else cout << "без зброї" << "\n";
    }
};

class Queen : public Character{
public:
    void fight() override{
        cout << "Королева: ";
        if(weapon)weapon -> useWeapon();
        else cout << "без зброї" << "\n";
    }
};

class Troll : public Character{
public:
    void fight() override{
        cout << "Троль: ";
        if(weapon)weapon -> useWeapon();
        else cout << "без зброї" << "\n";
    }
};

class Knight : public Character{
public:
    void fight() override{
        cout << "Лицар: ";
        if(weapon)weapon -> useWeapon();
        else cout << "без зброї" << "\n";
    }
};

//демонтрація, як можна додати нового персонажа
class Wizard : public Character{
public:
    void fight() override{
        cout << "Чарівник: ";
        if(weapon)weapon -> useWeapon();
        else cout << "без зброї" << "\n";
    }
};


int main(){
    system("chcp 65001 > nul");
    King king;
    Queen queen;
    Troll troll;
    Knight knight;

    SwordBehavior sword;
    BowAndArrowBehavior bow;
    AxeBehavior axe;
    KnifeBehavior knife;

    king.setWeapon(&sword);
    queen.setWeapon(&bow);
    troll.setWeapon(&axe);
    knight.setWeapon(&knife);

    king.fight();
    queen.fight();
    troll.fight();
    knight.fight();

    cout << "\n\tКороль міняє зброю на лук " << "\n";
    king.setWeapon(&bow);
    king.fight();
    cout << "\n";

    Wizard wizard;
    wizard.fight();


    return 0;

}
