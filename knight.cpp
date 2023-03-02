#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int& HP, int& level, int& remedy, int& maidenkiss, int& phoenixdown, int& rescue)
{
    ifstream fin(file_input);
    string line1;
    getline(fin,line1);
    stringstream ss(line1);
    ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
   
    rescue = 1;
       
    int maxHP = HP, maxLevel=10;
    string line2;
      getline(fin, line2);
      stringstream s(line2);
     int event[100];
    int count = 0;
     while (s >> event[count])
    {
        count++;
    }
    float baseDamage ;
    int levelO ;
    for (int i = 0; i < count; i++)
    { 
        if (event[i]==0)
       {rescue=1;
       break;
        } 
   
    
       else if (event[i] >= 1 && event[i] <= 5)
        {
            int b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
           
            switch (event[i])
            {
                case 1:
                    baseDamage = 1;
                    break;
                case 2:
                    baseDamage = 1.5;
                    break;
                case 3:
                    baseDamage = 4.5;
                    break;
                case 4:
                    baseDamage = 7.5;
                    break;
                case 5:
                    baseDamage = 9.5;
                    break;
            }
         if (level > levelO) level++;

        
         else if (level>=10) level = maxLevel;

         else if (level < levelO)
        {
            double damage = baseDamage * levelO * 10;
            HP -= damage;
            if (HP <= 0)
            {
                if (phoenixdown > 0)
                {
                    HP = maxHP;
                    phoenixdown--;
                    rescue = 1;
                }
                else
                {
                    rescue = 0;
                    break;
                }
            }
        }
     else if (level=levelO) {continue;}

        }
        
     if (event[i]==6)
        {
            int b = (i + 1) % 10;
            levelO = (i + 1) > 6 ? (b > 5 ? b : 5) : b;
            if (level > levelO)
            {
               level=min(maxLevel,level+2);
            }
           else if (level < levelO)
           {int   shrunkCount=0;
            bool  isShrunken;
              if (isShrunken)
               {
                if (remedy >= 1) 
        {
     
            isShrunken = false;
            remedy--;
        }
        else if (HP<= 0 && phoenixdown >= 1)
         {
          
            isShrunken = false;
            HP = maxHP;
            phoenixdown--;
        }
        else
         {
           
            HP/= 5;
            if (HP < 1)
             {
                HP = 1;
             }
            shrunkCount++;
             if (shrunkCount >= 2) 
            {
                isShrunken = false;
                HP*=5;
                
            }
         }
    }
            }
    }
    }
     cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;

 }



