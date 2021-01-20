//
// Created by daniilrybakov on 20.01.2021.
//

#ifndef TEMPLATE_URL_H
#define TEMPLATE_URL_H
#include <string>

const char k_protocol_name[] = "http://";
const size_t k_size_name_of_protocol = 7;

class URL {
  std::string url_;

 public:
  explicit URL(std::string url);
  std::string parseUrl();
  std::string parseUrlToHost();
  std::string parseUrlToPort();
  std::string parseUrlToTarget();
};
#endif  // TEMPLATE_URL_H
