//
// Created by nasiegel on 8/1/20.
//

#include <iostream>
#include <string>
#include <boost/filesystem.hpp>
#include "File.h"
#include <experimental/filesystem>

static std::string runningPath;

void initFS() {
    runningPath = std::experimental::filesystem::current_path().string();
}

std::string getSave() {
    boost::filesystem::create_directories(runningPath + "/saves");
    return runningPath.append("/saves/save.sav");
}

void clearFile(const std::string& file) {
    std::ofstream saveStream(file, std::ios::trunc);
    saveStream.close();
}

void append_to_file(const std::string& file, const std::vector<std::string>& lines) {
    std::ofstream saveStream(file, std::ios::app);
    for (std::string line : lines) {
        saveStream << line << "\n";
    }
    saveStream.close();
}

void write_to_file(std::string file, const std::vector<std::string>& lines) {
    std::ofstream saveStream(file, std::ios::out);
    for (std::string line : lines) {
        saveStream << line << "\n";
    }
    saveStream.close();
}

std::vector<std::string> read_from_file(std::string file) {
    std::vector<std::string> lines = {};
    std::string line;
    std::ifstream saveStream(file);
    while (std::getline(saveStream, line)) {
        lines.push_back(line);
    }
    if (lines.empty()) {
        return {""};
    }
    return lines;
}

const char *read_line(std::string file, int line) {
    int index = 0;
    std::string l;
    std::ifstream saveStream(file);
    while (std::getline(saveStream, l)) {
        if (line == index) return (l.c_str());
        index++;
    }
    return "";
}
