#pragma once

#include "vector"
#include "string"
#include "iostream"
#include "set"


void printListe(std::vector<std::string> l);
void printReverse(std::vector<std::string> l);
std::vector<std::string> replace(std::vector<std::string> &v , std::string old , std::string replace);

void printSet(std::set<std::string> s);
void reversedSet(std::set<std::string> s);
std::set<std::string> replaceSet(std::set<std::string> &s, std::string old, std::string replacement);