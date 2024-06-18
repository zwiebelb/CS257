
#include "json.hpp"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <stdlib.h>
#include "xkcd.h"
using namespace std;
using json = nlohmann::json;

int main(int argc, char *argv[]) {
  string error_message =
      "\x1B[35m\nPlease enter a valid choice. \033[4m\x1B[36m\e[1m\n\nThe "
      "options are:\e[0m\033[0m \n\033[4mField:\033[0m Transcript, alt, or "
      "title. If you do not specify a field "
      "transcript will automaticaly be searched for the topic you "
      "choose.\n\033[4mKeyword:\033[0m Any topic or word you would like to "
      "search for.\n-It is position senstive. (field, "
      "transcript).\n\033[4m\x1B[36m\e[1m\nTags:\e[0m \033[0m \n"
      "\e[1m--random\e[0m at beginning or end of your selection for a random "
      "comic with "
      "your keyword. If you do not specify a field or keyword, then a "
      "random comic from the transcript field will be printed. "
      "\n\e[1m--img\e[0m at the beginning or end of your selection for the "
      "image link to be printed instead of the comic link.";
  // im bored
  xkcd k;
  xk vectorXkcd;
  ifstream file("xkcd.json");
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      auto x = json::parse(line);
      k.month = x["month"].get<string>();
      k.num = x["num"].get<int>();
      k.link = x["link"].get<string>();
      k.year = x["year"].get<string>();
      k.news = x["news"].get<string>();
      k.safe_title = x["safe_title"].get<string>();
      k.transcript = x["transcript"].get<string>();
      k.alt = x["alt"].get<string>();
      k.img = x["img"].get<string>();  ////
      k.title = x["title"].get<string>();
      k.day = x["day"].get<string>();
      vectorXkcd.push_back(k);
    }
    file.close();
  }
  /* if argc is 1, or greater than 4 then give error
   if argc is 2 than automatically search transcript
   if argc is 3 first check if theres a flag then if there isnt search
   normally // field, keyword
   if argc is 4 then theres a flag //check which flag //==--random or --img in
   and give error if theres a flag in second or third argc
   both locations 1 and 5 */
  query q;
  string x;

  if (argc == 1) {

    cerr << "\nYou have not entered a field or keyword." << error_message
         << endl;
    return 1;
  } else if (argc == 2) {
    string first = string(argv[1]);
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    if (((first != "transcript") || (first != "alt") || (first != "title")) &&
        (first != "--random") && (first != "--img")) {
      q.field = "transcript";
      q.keyword = first;
      x = "N/A";
    } else if (first == "--random") {
      x = "--random";
      q.field = "transcript";
      q.keyword = "///all";
      x = "--random";

    } else {
      cerr << error_message << endl;
      return 1;
    }
  } else if (argc == 3) {
    string first = string(argv[1]);
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    string second = string(argv[2]);
    transform(second.begin(), second.end(), second.begin(), ::tolower);

    if ((first == "--random") && ((second == "transcript") ||
                                  (second == "alt") || (second == "title"))) {
      q.field = second;
      q.keyword = "///all";
      x = "--random";

    } else if ((first == "--random") && (second == "--img")) {
      q.field = "transcript";
      q.keyword = "///all";
      x = "--random, --img";  //
    } else if ((second == "--random") &&
               ((first == "transcript") || (first == "alt") ||
                (first == "title"))) {
      q.field = first;
      q.keyword = "///all";
      x = "--random";
    } else if ((first == "--random") &&
               ((second != "transcript") || (second != "alt") ||
                (second != "title"))) {

      q.field = "transcript";
      q.keyword = second;
      x = "--random";

    } else if ((second == "--random") &&
               ((first != "transcript") || (first != "alt") ||
                (first != "title"))) {
      q.field = "transcript";
      q.keyword = first;
      x = "--random";
    } else if ((first == "--img") &&
               ((second == "transcript") || (second == "alt") ||
                (second == "title"))) {
      x = "--img";
      q.field = second;
      q.keyword = "///all";

    } else if ((second == "--img") &&
               ((first == "transcript") || (first == "alt") ||
                (first == "title"))) {
      x = "--img";
      q.field = first;
      q.keyword = "///all";
    } else if ((first == "--img") &&
               ((second != "transcript") || (second != "alt") ||
                (second != "title"))) {
      q.field = "transcript";
      q.keyword = second;
      x = "--img";

    } else if ((second == "--img") &&
               ((first != "transcript") || (first != "alt") ||
                (first != "title"))) {

      q.field = "transcript";
      q.keyword = first;
      x = "--img";
    } else if (((first == "transcript") || (first == "alt") ||
                (first == "title")) &&
               ((second != "--random") || (second != "--img"))) {
      q.field = first;
      q.keyword = second;
      x = "N/A";
    } else {
      cout << error_message << endl;
    }
  } else if (argc == 4) {
    string first = string(argv[1]);
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    string second = string(argv[2]);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    string third = string(argv[3]);
    transform(third.begin(), third.end(), third.begin(), ::tolower);

    if ((first == "--random") && ((second == "transcript") ||
                                  (second == "alt") || (second == "title"))) {
      q.field = second;
      q.keyword = third;
      x = "--random";
    } else if ((third == "--random") &&
               ((first == "transcript") || (first == "alt") ||
                (first == "title"))) {
      q.field = first;
      q.keyword = second;
      x = "--random";
    } else if ((first == "--img") &&
               ((second == "transcript") || (second == "alt") ||
                (second == "title"))) {
      q.field = second;
      q.keyword = third;
      x = "--img";
    } else if ((third == "--img") && ((first == "transcript") ||
                                      (first == "alt") || (first == "title"))) {
      q.field = first;
      q.keyword = second;
      x = "--img";
    } else if (((second == "--img") && (third == "--random")) ||
               ((second == "--random") && (third == "--img")) &&
                   ((first != "transcript") && (first != "alt") &&
                    (first != "title"))) {
      q.field = "transcript";
      q.keyword = first;
      x = "--random, --img";
    } else if (((first == "--img") && (second == "--random")) ||
               ((first == "--random") && (second == "--img")) &&
                   ((third != "transcript") && (third != "alt") &&
                    (third != "title"))) {
      q.field = "transcript";
      q.keyword = third;
      x = "--random, --img";
    } else {
      cout << error_message << endl;
    }
  } else if (argc == 5) {  // includes both tags and both
    string first = string(argv[1]);
    transform(first.begin(), first.end(), first.begin(), ::tolower);
    string second = string(argv[2]);
    transform(second.begin(), second.end(), second.begin(), ::tolower);
    string third = string(argv[3]);
    transform(third.begin(), third.end(), third.begin(), ::tolower);
    string fourth = string(argv[4]);
    transform(fourth.begin(), fourth.end(), fourth.begin(), ::tolower);
    if (((first == "--img") && (second == "--random")) ||
        ((first == "--random") && (second == "--img")) &&
            ((third == "transcript") || (third == "alt") ||
             (third == "title"))) {
      q.field = third;
      q.keyword = fourth;
      x = "--random, --img";
    } else if (((third == "--img") && (fourth == "--random")) ||
               ((third == "--random") && (fourth == "--img")) &&
                   ((first == "transcript") || (first == "alt") ||
                    (first == "title"))) {
      q.field = first;
      q.keyword = second;
      x = "--random, --img";
    } else {
      cout << error_message << endl;
    }
  } else {
    cout << error_message << endl;
  }
  // searches for the word and prints the title and url.
  search(vectorXkcd, q, x);
  return 0;
}
