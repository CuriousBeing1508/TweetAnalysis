// #include <iostream>
// using namespace std;

// int main() {
//     cout << "Hello, C++ on Mac with VSCode!" << endl;
//     return 0;
// }


#include <iostream>
#include "include/Tweet.hpp"
#include "include/Utils.hpp"


int main() {
    std::vector<Tweet> tweets = loadCSV("data/dummyTrain.csv");
    std::cout << "Loaded " << tweets.size() << " tweets.\n";

    for (int i = 0; i < std::min(5, (int)tweets.size()); ++i) {
        std::cout << "Tweet " << i << ": "
                  << (tweets[i].sentiment ? "Positive" : "Negative")
                  << " -> " << tweets[i].text << "\n";
    }

    return 0;
}
