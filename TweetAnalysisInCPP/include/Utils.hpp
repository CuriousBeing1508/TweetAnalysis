#pragma once
#include <string>
#include <vector>
#include "Tweet.hpp"

std::vector<Tweet> loadCSV(const std::string& filepath);
std::string cleanText(const std::string& input);
std::vector<std::string> tokenize(const std::string& cleaned);
