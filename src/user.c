#include "user.h"

#include <string.h>

struct User {
    int cash
} user;

struct User createNewUser(int cash) {
    struct User u;
    u.cash = cash;
    return u;
}