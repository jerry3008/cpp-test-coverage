#ifndef MAIN_HPP_
#define MAIN_HPP_

#include <string>
#include <vector>
#include <algorithm>

class UserManager {
public:
    void AddUser(const std::string& user);
    std::vector<std::string> GetUsers() const;
private:
    std::vector<std::string> users;
};

#endif  // MAIN_HPP_