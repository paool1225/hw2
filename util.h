#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

std::string convToLower(std::string src);
std::set<std::string> parseStringToWords(std::string line);

template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> result;
  typename std::set<T>::iterator it1 = s1.begin();
  typename std::set<T>::iterator it2 = s2.begin();

  while (it1 != s1.end() && it2 != s2.end()) {
    if (*it1 < *it2) {
      ++it1;
    } else if (*it2 < *it1) {
      ++it2;
    } else {
      result.insert(*it1);
      ++it1;
      ++it2;
    }
  }

  return result;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
  std::set<T> result;
  typename std::set<T>::iterator it1 = s1.begin();
  typename std::set<T>::iterator it2 = s2.begin();

  while (it1 != s1.end() && it2 != s2.end()) {
    if (*it1 < *it2) {
      result.insert(*it1);
      ++it1;
    } else if (*it2 < *it1) {
      result.insert(*it2);
      ++it2;
    } else {
      result.insert(*it1);
      ++it1;
      ++it2;
    }
  }

  // Add remaining elements from s1
  while (it1 != s1.end()) {
    result.insert(*it1);
    ++it1;
  }

  // Add remaining elements from s2
  while (it2 != s2.end()) {
    result.insert(*it2);
    ++it2;
  }

  return result;
}

#endif
