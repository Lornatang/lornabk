/*
 * The development suite necessary for the system to run.
 * Priority execution when importing.
 * Otherwise, there will be a major flaw in the program running.*/

#ifndef SSM_USER_BASE_H
#define SSM_USER_BASE_H

#include "user.h"

User::User() {
  head = new userNode;
  head->next = nullptr;
}

User::~User() {
  userNode *p;
  while (head) {
    p = head;
    head = head->next;
    delete p;
  }
  head = nullptr;
}

#endif //SSM_BASE_H
