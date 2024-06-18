#ifndef XKCD_H
#define XKCD_H
#include <string>
#include <iostream>
#include <vector>

struct xkcd {
  std::string month;
  int num;
  std::string link;
  std::string year;
  std::string news;
  std::string safe_title;
  std::string transcript;
  std::string alt;
  std::string img;
  std::string title;
  std::string day;
};
struct query {
  std::string field;
  std::string keyword;
};
typedef std::vector<xkcd> xk;

xk search(xk index, query searching, std::string x);
void print(xk title_url, std::string flag);

#endif