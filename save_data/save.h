//
// Created by nasiegel on 8/4/20.
//

#ifndef TREEGAME_SAVE_H
#define TREEGAME_SAVE_H

#include <ttmath/ttmath.h>
#include "../save_data/File.h"
#include "../game/Player.h"

void save() {
    std::string path = getSave();
    std::vector<std::string> lines;
    lines.push_back(Player::x.ToString() + "," + Player::y.ToString() + "," + Player::z.ToString()); // Primary Currencies
    lines.push_back(Player::RP.ToString()); // RP
    lines.push_back(Player::a.ToString() + "," + Player::b.ToString() + "," + Player::c.ToString()); // Secondary Currencies

    // Normal Upgrades
    std::string line;
    for (int i = 0; i < UPGRADE_NUM; i++) {
        line += std::to_string(Player::upgrades[i]);
    }
    lines.push_back(line);

    // RB Upgrades
    line = "";
    for (int i = 0; i < RB_UPGRADE_NUM; i++) {
        line += std::to_string(Player::r_upgrades[i]);
    }
    lines.push_back(line);

    // Secondary Upgrades
    line = "";
    for (int i = 0; i < S_UPGRADE_NUM; i++) {
        line += std::to_string(Player::upgrades[i]);
    }
    lines.push_back(line);

    write_to_file(path, lines);
}

#endif //TREEGAME_SAVE_H
