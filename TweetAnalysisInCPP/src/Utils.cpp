#include "Utils.hpp"
#include <fstream>
#include <sstream>
#include <cctype>
#include <algorithm>

std::string cleanText(const std::string& input) {
    std::string result;
    for (char ch : input) {
        if (std::isalpha(ch) || ch == ' ') {
            result += std::tolower(ch);
        }
    }
    return result;
}

std::vector<std::string> tokenize(const std::string& text) {
    std::istringstream iss(text);
    std::string token;
    std::vector<std::string> tokens;
    while (iss >> token) {
        tokens.push_back(token);
    }
    return tokens;
}

std::vector<Tweet> loadCSV(const std::string& filepath) {
    std::ifstream file(filepath);
    std::vector<Tweet> tweets;
    std::string line;

    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string labelStr, tweetText;

        std::getline(ss, labelStr, ',');
        std::getline(ss, tweetText);

        int sentiment = std::stoi(labelStr);
        tweetText = cleanText(tweetText);
        Tweet tweet(sentiment, tweetText);
        tweet.tokens = tokenize(tweetText);

        tweets.push_back(tweet);
    }

    return tweets;
}
