#include "xkcd.h"
#include <algorithm>
#include <vector>
#include <string>
#include <random>
#include <ctype.h>
#include <ctime>
using namespace std;
xk search(xk index, query searched, string x) {
  vector<xkcd> index2(index);  
  for(unsigned int i = 0; i < index2.size(); i++){
    transform(index2.at(i).title.begin(), index2.at(i).title.end(), index2.at(i).title.begin(), ::tolower);
    transform(index2.at(i).alt.begin(), index2.at(i).alt.end(), index2.at(i).alt.begin(), ::tolower);
    transform(index2.at(i).transcript.begin(), index2.at(i).transcript.end(), index2.at(i).transcript.begin(), ::tolower);
  }
  xk vectFound;
  if ((searched.field == "transcript")) {
    if (searched.keyword != "///all") {

      bool found = false;
      for (unsigned int i = 0; i < index.size(); ++i) {
        if (index2.at(i).transcript.find(searched.keyword) != string::npos) {
          found = true;
          vectFound.push_back(index[i]);
        }
      }
      if (!found) {
        cout << "word was not found, try again." << endl;
      }
    } else if (searched.keyword == "///all") {
      for (unsigned int i = 0; i < index2.size(); ++i) {
        vectFound.push_back(index[i]);
      }
    }
  } else if (searched.field == "alt") {
    bool found = false;
    for (unsigned int i = 0; i < index.size(); ++i) {
      if (index2.at(i).alt.find(searched.keyword) != string::npos) {
        found = true;
        vectFound.push_back(index[i]);
      }
    }
    if (!found) {
      cout << "word was not found, try again." << endl;
    }
  } else if (searched.field == "title") {
    bool found = false;
   // string str = searched.keyword;
    //str[0] = toupper(str[0]);
    for (unsigned int i = 0; i < index.size(); ++i) {
      if (index2.at(i).title.find(searched.keyword) != string::npos) {
        found = true;
        vectFound.push_back(index[i]);
      }
    }
    if (!found) {
      cout << "word was not found, try again." << endl;
    }
  }
  print(vectFound, x);
  return vectFound;
}
void print(xk vectFound, string flag) {
  if (flag == "N/A") {
    for (unsigned int i = 0; i < vectFound.size(); i++) {
      cout << vectFound.at(i).title << ": "
           << "https://xkcd.com/" << vectFound.at(i).num << "/" << endl;
    }
  } else if (flag == "--img") {
    for (unsigned int i = 0; i < vectFound.size(); i++) {
      cout << vectFound.at(i).title << ": " << vectFound.at(i).img << endl;
    }
  } else if (flag == "--random") {
    srand(time(0));
    int randomIndex = rand() % vectFound.size();
    cout << vectFound.at(randomIndex).title << ": "
         << "https://xkcd.com/" << vectFound.at(randomIndex).num << "/" << endl;
  } else if (flag == "--random, --img") {
    srand(time(0));
    int randomIndex = rand() % vectFound.size();
    cout << vectFound.at(randomIndex).title << ": "
         << vectFound.at(randomIndex).img << endl;
  }
}