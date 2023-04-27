
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <math.h>

using namespace std;

// #define DEBUG

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
    KnightType knightType;

public:
    static BaseKnight *create(int id, int maxhp, int level, int gil, int antidote, int phoenixdownI);
    string toString() const;
};
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + ",knight_type:" + typeString[knightType] + "]";
    return s;
}
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
    void printKnightInfo() const
    {
        for (int i = 0; i < numKnights; i++)
        {
            cout << knights[i]->toString() << endl;
        }
    }

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
ArmyKnights::ArmyKnights(const string &file_armyknights)
{
    ifstream fin(file_armyknights);

    fin >> numKnights;
    knights = new BaseKnight *[numKnights];
    for (int i = 0; i < numKnights; i++)
    {
        int hp, level, phoenixdownI, gil, antidote;
        fin >> hp >> level >> phoenixdownI >> gil >> antidote;
        if (isPrime(hp))
        {
            knights[i] = PaladinKnight::create(i + 1, hp, level, gil, antidote, phoenixdownI);
        }
        else if (hp == 888)
        {
            knights[i] = LancelotKnight::create(i + 1, hp, level, gil, antidote, phoenixdownI);
        }
        else if (isDragonKnightHP(hp))
        {
            knights[i] = DragonKnight::create(i + 1, hp, level, gil, antidote, phoenixdownI);
        }
        else
            knights[i] = NormalKnight::create(i + 1, hp, level, gil, antidote, phoenixdownI);
    }
    fin.close();
}
ArmyKnights::~ArmyKnights()
{
    delete[] knights;
}

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
int main()
{
    ArmyKnights knights("file_armyknights");
    knights.printKnightInfo();
    return 0;
}
