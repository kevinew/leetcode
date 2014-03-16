// Copyright 2014 kevinew@leetcode Inc. All Rights Reserved.

#include <algorithm>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

class Solution {
  public:
    void ltrim(char *s, char c)
    {
      char *p;
      p = s;
      while(*p == c || *p == c){*p++;}
      strcpy(s,p);
    }

    void rtrim(char *s)
    {
      int i;

      i = strlen(s)-1;
      while((s[i] == ' ' || s[i] == '\t') && i >= 0){i--;};
      s[i+1] = '\0';
    }

    void trim(char *s){
      ltrim(s, ' ');
      ltrim(s, '\t');
      rtrim(s);
    }


    bool isNumber(const char *s) {
      char t[strlen(s) + 2], t2[strlen(s) + 2];
      strcpy(t, s);
      trim(t);
      if (strcmp(t, "0") == 0) return true;
      ltrim(t, '0');
      if (strlen(t) == 0) return false;
      if (strlen(t) > 1 && t[0] == '.') {
        strcpy(t2, "0");
        strcat(t2, t);
        strcpy(t, t2);
      }
      float f = atof(s);
      sprintf(t2, "%f", f);
      if (strncmp(t2, t, strlen(t)) == 0) return true;
      else return false;
    }
};

int main(int argc, char **argv) {

  Solution s;
  if (s.isNumber(" 56.789 ")) cout << "is number." << endl;
  if (!s.isNumber(" 5b6.789 ")) cout << "is not number." << endl;
  if (!s.isNumber(" 56. 789 ")) cout << "is not number." << endl;
  if (!s.isNumber(" 56 .789 ")) cout << "is not number." << endl;
  if (!s.isNumber(" ")) cout << "is not number." << endl;
  if (s.isNumber(".1")) cout << "is number." << endl;

  return 0;
}
