#pragma once
#include <string>
#include <vector>

class Tweet {
public:
    int sentiment;           // 0 or 1
    std::string text;        // Raw tweet
    std::vector<std::string> tokens;  // Tokenized

    Tweet(int sentiment, const std::string& text);
};
