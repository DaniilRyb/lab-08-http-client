//
// Created by daniilrybakov on 20.01.2021.
//
#include <string>
#ifndef TEMPLATE_REQUESTPARAM_H
struct RequestParam {
  std::string url;
  std::string host;
  std::string port;
  std::string target;
  std::string request_body;
  int version;
};
#define TEMPLATE_REQUESTPARAM_H

#endif  // TEMPLATE_REQUESTPARAM_H
