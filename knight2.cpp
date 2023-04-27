#include "knight2.h"

/* * * BEGIN implementation of class BaseBag * * */

/* * * END implementation of class BaseBag * * */

/* * * BEGIN implementation of class BaseKnight * * */
string BaseKnight::toString() const
{
    string typeString[4] = {"PALADIN", "LANCELOT", "DRAGON", "NORMAL"};
    // inefficient version, students can change these code
    //      but the format output must be the same
    string s("");
    s += "[Knight:id:" + to_string(id) + ",hp:" + to_string(hp) + ",maxhp:" + to_string(maxhp) + ",level:" + to_string(level) + ",gil:" + to_string(gil) + "," + bag->toString() + ",knight_type:" + typeString[knightType] + "]";
    return s;
}

/* * * END implementation of class BaseKnight * * */

/* * * BEGIN implementation of class ArmyKnights * * */
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
        if (hp == 888)
        {
            knights[i] = LancelotKnight::create(i + 1, hp, level, gil, antidote, phoenixdownI);
        }
        if (isDragonKnightHP(hp))
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
    for (int i = 0; i < numKnights; i++)
    {
        delete knights[i];
    }
    delete[] knights;
}
int ArmyKnights::count() const
{
    return numKnights;
}

BaseKnight *ArmyKnights::lastKnight() const
{
    if (numKnights == 0)
    {
        return nullptr;
    }
    return knights[numKnights - 1];
}

void ArmyKnights::printInfo() const
{
    cout << "No. knights: " << this->count();
    if (this->count() > 0)
    {
        BaseKnight *lknight = lastKnight(); // last knight
        cout << ";" << lknight->toString();
    }
    cout << ";PaladinShield:" << this->hasPaladinShield()
         << ";LancelotSpear:" << this->hasLancelotSpear()
         << ";GuinevereHair:" << this->hasGuinevereHair()
         << ";ExcaliburSword:" << this->hasExcaliburSword()
         << endl
         << string(50, '-') << endl;
}
bool ArmyKnights::fight(BaseOpponent *Opponent)
{
}

void ArmyKnights::printResult(bool win) const
{
    cout << (win ? "WIN" : "LOSE") << endl;
}

/* * * END implementation of class ArmyKnights * * */

/* * * BEGIN implementation of class KnightAdventure * * */
KnightAdventure::KnightAdventure()
{
    armyKnights = nullptr;
    events = nullptr;
}

/* * * END implementation of class KnightAdventure * * */