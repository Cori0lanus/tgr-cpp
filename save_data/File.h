//
// Created by nasiegel on 8/1/20.
//

#ifndef SFML_FILE_H
#define SFML_FILE_H

#include <fstream>
#include <string>
#include <vector>

void initFS();

// Getting File Struct
std::string getFile(const char* path);
std::string getSave();

// Write Operations
void clearFile(const std::string& file);
void append_to_file(const std::string& file, const std::vector<std::string>& lines);
void write_to_file(std::string file, const std::vector<std::string>& lines);

// Read Operations
std::vector<std::string> read_from_file(std::string file);
const char* read_line(std::string file, int line);
const char* getProgramDir();

#endif //SFML_FILE_H
