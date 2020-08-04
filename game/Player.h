//
// Created by nasiegel on 8/4/20.
//

#ifndef TREEGAME_PLAYER_H
#define TREEGAME_PLAYER_H

#include <ttmath/ttmath.h>
#include <ctime>

#define UPGRADE_NUM 49
#define RB_UPGRADE_NUM 40
#define S_UPGRADE_NUM 25

class Player {
public:
    static ttmath::Big<16, 16> x, y, z; // Primary currencies
    static ttmath::Big<16, 16> a, b, c; // Secondary currencies
    static ttmath::Big<8, 8> RP; // Rebirth Points
    static std::vector<u_char> upgrades, r_upgrades, s_upgrades; // Upgrades and RP upgrades stored in unsigned chars, 1 byte
    static time_t lastOn; // Time the player last saved their game, stored in an unsigned long

    Player() {
        x = y = z = 0; // Initialize all currencies to 0
        a = b = c = 0; // Initialize all secondary currencies to 0
        RP = 0; // Initialize RP to 0
        // Initialize upgrades to false VVVV
        for (uint i = 0; i < UPGRADE_NUM; i++) {
            upgrades.push_back(false);
        }
        for (uint i = 0; i < RB_UPGRADE_NUM; i++) {
            r_upgrades.push_back(false);
        }
        for (uint i = 0; i < S_UPGRADE_NUM; i++) {
            s_upgrades.push_back(false);
        }
        // Initialize time
        lastOn = time(nullptr);
    }
};

ttmath::Big<16, 16> Player::x, Player::y, Player::z, Player::a, Player::b, Player::c;
ttmath::Big<8, 8> Player::RP;
std::vector<u_char> Player::upgrades, Player::r_upgrades, Player::s_upgrades;
time_t Player::lastOn;

#endif //TREEGAME_PLAYER_H
