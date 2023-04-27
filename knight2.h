#ifndef __KNIGHT2_H__
#define __KNIGHT2_H__

#include "main.h"

// #define DEBUG

enum ItemType
{ /* TODO: */ };

class BaseBag
{
public:
    virtual bool insertFirst(BaseItem *item);
    virtual BaseItem *get(ItemType itemType);
    virtual string toString() const;
};

enum KnightType
{
    PALADIN = 0,
    LANCELOT,
    DRAGON,
    NORMAL
};
class BaseKnight
{
protected:
    int id;
    int hp;
    int maxhp;
    int level;
    int phoenixdownI;
    int gil;
    int antidote;
    BaseBag *bag;
    KnightType knightType;

public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};
BaseKnight *BaseKnight::create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
{
    BaseKnight *knight = new BaseKnight;
    knight->id = id;
    knight->hp = maxhp;
    knight->maxhp = maxhp;
    knight->level = level;
    knight->gil = gil;
    knight->antidote = antidote;
    knight->phoenixdownI = phoenixdownI;

    return knight;
}

class PaladinKnight : public BaseKnight
{
public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    {

        PaladinKnight *knight = new PaladinKnight;
        knight->id = id;
        knight->hp = maxhp;
        knight->maxhp = maxhp;
        knight->level = level;
        knight->gil = gil;
        knight->antidote = antidote;
        knight->phoenixdownI = phoenixdownI;
        knight->knightType = PALADIN;

        return knight;
    }
};
class LancelotKnight : public BaseKnight
{
public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    {

        LancelotKnight *knight = new LancelotKnight;
        knight->id = id;
        knight->hp = maxhp;
        knight->maxhp = maxhp;
        knight->level = level;
        knight->gil = gil;
        knight->antidote = antidote;
        knight->phoenixdownI = phoenixdownI;
        knight->knightType = LANCELOT;

        return knight;
    }
};
class DragonKnight : public BaseKnight
{
public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    {

        DragonKnight *knight = new DragonKnight;
        knight->id = id;
        knight->hp = maxhp;
        knight->maxhp = maxhp;
        knight->level = level;
        knight->gil = gil;
        knight->antidote = antidote;
        knight->phoenixdownI = phoenixdownI;
        knight->knightType = DRAGON;

        return knight;
    }
};
class NormalKnight : public BaseKnight
{
public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI)
    {

        NormalKnight *knight = new NormalKnight;
        knight->id = id;
        knight->hp = maxhp;
        knight->maxhp = maxhp;
        knight->level = level;
        knight->gil = gil;
        knight->antidote = antidote;
        knight->phoenixdownI = phoenixdownI;
        knight->knightType = NORMAL;

        return knight;
    }
};

class ArmyKnights
{
    BaseKnight **knights;

    int numKnights; // Số lượng hiệp sĩ trong đội

public:
    ArmyKnights(const string &file_armyknights);
    ~ArmyKnights();
    bool fight(BaseOpponent *opponent);
    bool adventure(Events *events);
    int count() const;
    BaseKnight *lastKnight() const;

    bool hasPaladinShield() const;
    bool hasLancelotSpear() const;
    bool hasGuinevereHair() const;
    bool hasExcaliburSword() const;

    void printInfo() const;
    void printResult(bool win) const;
    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i <= sqrt(n); i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }
    bool isDragonKnightHP(int n)
    {
        // Tách số n ra thành các chữ số a, b, c
        int a = n / 100;
        int b = (n / 10) % 10;
        int c = n % 10;

        // Kiểm tra xem a, b, c có đúng 3 chữ số và là các số dương không
        if (a <= 0 || b <= 0 || c <= 0 || a > 9 || b > 9 || c > 9)
        {
            return false;
        }

        // Tính giá trị của c bằng căn bậc hai của a^2 + b^2
        int c2 = a * a + b * b;
        int c_sqrt = sqrt(c2);

        // Kiểm tra xem c có là số nguyên và có bằng c không
        if (c_sqrt * c_sqrt != c2 || c_sqrt != c)
        {
            return false;
        }

        return true;
    }
};
class BaseOpponent;



class BaseItem
{
public:
    virtual bool canUse(BaseKnight *knight) = 0;
    virtual void use(BaseKnight *knight) = 0;
};

class Events
{
    int *events;
    int num_events;

public:
    Events(const string &file_events);
    int count() const;
    int get(int i) const;
    ~Events();
};
Events::Events(const string &file_events)
{
    ifstream fin(file_events);
    fin >> num_events;
    events = new int[num_events];
    for (int i = 0; i < num_events; i++)
    {
        fin >> events[i];
    }
    fin.close();
}
int Events::count() const
{
    return num_events;
}

// triển khai method get
int Events::get(int i) const
{
    return events[i];
}

// triển khai destructor
Events::~Events()
{
    delete[] events; // thu hồi vùng nhớ được cấp phát động trong Heap
}

class KnightAdventure
{
private:
    ArmyKnights *armyKnights;
    Events *events;

public:
    KnightAdventure();
    ~KnightAdventure(); // TODO:

    void loadArmyKnights(const string &);
    void loadEvents(const string &);
    void run();
};

#endif // __KNIGHT2_H__