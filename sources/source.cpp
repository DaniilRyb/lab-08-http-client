// Copyright 2020 DaniilRybakov <pochtaworld7@gmail.com>

#include <client.hpp>

int main(int argc, char* argv[]) {
  client client(argc, argv);
  return client.Run();
}
//./cmake-build-debug/tests  http://localhost:8080/v1/api/suggest
//{\"input\":\"hel\"}
// {\"input\":\"c\"}