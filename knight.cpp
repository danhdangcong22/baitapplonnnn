#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
  ifstream fin(file_input);
  string line1,line2;
  getline(fin,line1);
  stringstream ss(line1);
  ss >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
   int max_event_id = 0;  // Số sự kiện tối đa
    int event_id, event_count[100] = { 0 };
    while (fin >> event_id) {
        event_count[event_id]++;
        if (event_id > max_event_id) {
            max_event_id = event_id;
            switch (event_id) {
            case 0: // Bowser đầu hàng và trả lại công chúa
                rescue = 1;
                break;
            case 1: // Gặp gấu MadBear
            {
                int enemyLevel = 1;
                int enemyHP = 50 * level;
                while (HP > 0 && enemyHP > 0) {
                    enemyHP -= 20 * level;
                    if (enemyHP > 0) {
                        HP -= 30 * enemyLevel;
                        if (HP <= 0) {
                            rescue = 0;
                        }
                    }
                }
                if (HP > 0) {
                    level++;
                    remedy++;
                }
            }
            break;
            case 2: // Gặp cướp Bandit
            {
                int enemyLevel = 2;
                int enemyHP = 80 * level;
                while (HP > 0 && enemyHP > 0) {
                    enemyHP -= 25 * level;
                    if (enemyHP > 0) {
                        HP -= 35 * enemyLevel;
                        if (HP <= 0) {
                            rescue = 0;
                        }
                    }
                }
                if (HP > 0) {
                    remedy++;
                }
            }
            break;
            case 3: // Gặp tướng cướp LordLupin
            {
                int enemyLevel = 3;
                int enemyHP = 120 * level;
                while (HP > 0 && enemyHP > 0) {
                    enemyHP -= 30 * level;
                    if (enemyHP > 0) {
                        HP -= 40 * enemyLevel;
                        if (HP <= 0) {
                            rescue = 0;
                        }
                    }
                }
                if (HP > 0) {
                    maidenkiss++;
                }
            }
            break;
            case 4: // Gặp yêu tinh Elf
            {
                int enemyLevel = 4;
                int enemyHP = 180 * level;
                while (HP > 0 && enemyHP > 0) {
                    enemyHP -= 35 * level;
                    if (enemyHP > 0) {
                        HP -= 45 * enemyLevel;
                        if (HP <= 0) {
                            rescue = 0;
                        }
                    }
                }
                if (HP > 0) {
                    phoenixdown++;
                }
            }
            break;

            }
        }
   string file_mush_ghost, file_asclepius_pack, file_merlin_pack;
        getline(fin, file_mush_ghost,',');
        getline(fin, file_asclepius_pack,',');
        getline(fin, file_merlin_pack);
}
