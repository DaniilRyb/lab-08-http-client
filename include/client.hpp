// Copyright 2020 DaniilRybakov <pochtaworld7@gmail.com>

#ifndef INCLUDE_HEADER_HPP_
#define INCLUDE_HEADER_HPP_
//
// Created by daniilrybakov on 20.01.2021.
//

#include <boost/asio/connect.hpp>
#include <boost/asio/ip/tcp.hpp>
#include <boost/beast/core.hpp>
#include <boost/beast/http.hpp>
#include <boost/beast/version.hpp>
#include <cstdlib>
#include <iostream>
#include <string>

#include "RequestParam.hpp"
#include "client.hpp"
#include "url.hpp"

namespace beast = boost::beast;  // from <boost/beast.hpp>
namespace http = beast::http;    // from <boost/beast/http.hpp>
namespace net = boost::asio;     // from <boost/asio.hpp>
using tcp = net::ip::tcp;        // from <boost/asio/ip/tcp.hpp>

class client {
 public:
  client(int argc, char* argv[]);
  int Run();

 private:
  void prepareCommandLine();
  int argc_;
  char** argv_;
  RequestParam parametrs;
};
#endif  // INCLUDE_HEADER_HPP_
